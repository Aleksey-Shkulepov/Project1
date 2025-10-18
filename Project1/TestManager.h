#pragma once

#include "Category.h"

#include "Vector.h"
#include "String.h"

namespace TestingSystem {

    class TestManager {
        Vector<Category> categories;
        String storageFile;
    public:
        TestManager(const String& storageFile = "tests.bin");
        ~TestManager() = default;

        void loadAll();
        void saveAll();

        bool createCategory(const String& name);
        bool deleteCategory(const String& name);
        Vector<String> listCategories() const;

        bool createTest(const String& categoryName, const Test& test);
        bool deleteTest(const String& categoryName, const String& testName);
        Vector<String> listTests(const String& categoryName) const;

        bool addQuestion(const String& categoryName, const String& testName, const Question& q);

        bool exportToText(const String& filename) const;
        bool importFromText(const String& filename);

        const Category* findCategory(const String& name) const;
        Category* findCategory(const String& name);
        const Test* findTest(const String& categoryName, const String& testName) const;
    };

    TestManager::TestManager(const String& storageFile_) : storageFile(storageFile_) {}

    void TestManager::loadAll() {
        ifstream in(storageFile.to_char(), ios::binary);
        if (!in) return;

        size_t s; in.read((char*)&s, sizeof(s));
        categories.clear();
        for (size_t i = 0; i < s; ++i) {
            Category c; c.load(in); categories.push_back(c);
        }
    }

    void TestManager::saveAll() {
        ofstream out(storageFile.to_char(), ios::binary);

        size_t s = categories.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            categories.at(i).save(out);
    }

    bool TestManager::createCategory(const String& name) {
        for (size_t i = 0; i < categories.get_size(); i++)
            if (categories.at(i).name == name) return false;
        Category c; c.name = name; categories.push_back(c); saveAll(); return true;
    }

    bool TestManager::deleteCategory(const String& name) {
        for (size_t i = 0; i < categories.get_size(); i++) {
            if (categories.at(i).name == name) {
                categories.pop(i); saveAll(); return true;
            }
        }
        return false;
    }

    Vector<String> TestManager::listCategories() const
    { 
        Vector<String> res; 
        for (size_t i = 0; i < categories.get_size(); i++)
            res.push_back(categories.at(i).name);
        return res;
    }

    bool TestManager::createTest(const String& categoryName, const Test& test) {
        for (size_t i = 0; i < categories.get_size(); i++)
        {
            if (categories.at(i).name == categoryName) {
                for (size_t j = 0; j < categories.at(i).tests.get_size(); j++)
                    if (categories.at(i).tests.at(j).name == test.name) return false;
                categories.at(i).tests.push_back(test); saveAll(); return true;
            }
        }
        return false;
    }

    bool TestManager::deleteTest(const String& categoryName, const String& testName) {
        for (size_t i = 0; i < categories.get_size(); i++) {
            if (categories.at(i).name == categoryName) {
                for (size_t j = 0; j < categories.at(i).tests.get_size(); j++) {
                    if (categories.at(i).tests.at(j).name == testName) {
                        categories.at(i).tests.pop(j); saveAll(); return true;
                    }
                }
            }
        }
        return false;
    }

    Vector<String> TestManager::listTests(const String& categoryName) const {
        Vector<String> res;
        for (size_t i = 0; i < categories.get_size(); i++) {
            if (categories.at(i).name == categoryName) {
                for (size_t j = 0; j < categories.at(i).tests.get_size(); j++)
                    res.push_back(categories.at(i).tests.at(j).name);
                break;
            }
        }
        return res;
    }

    bool TestManager::addQuestion(const String& categoryName, const String& testName, const Question& q) {
        for (size_t i = 0; i < categories.get_size(); i++) {
            if (categories.at(i).name == categoryName) {
                for (size_t j = 0; j < categories.at(i).tests.get_size(); j++) {
                    if (categories.at(i).tests.at(j).name == testName) {
                        categories.at(i).tests.at(j).questions.push_back(q); saveAll(); return true;
                    }
                }
            }
        }
        return false;
    }

    bool TestManager::exportToText(const String& filename) const {
        ofstream out(filename.to_char());
        if (!out) return false;
        for (const auto& c : categories) {
            out << "Category: " << c.name << endl;
            for (const auto& t : c.tests) {
                out << "Test: " << t.name << endl;
                for (const auto& q : t.questions) {
                    out << "Q: " << q.text << endl;
                    for (const auto& o : q.options) out << "O: " << o << endl;
                    out << "A: " << q.correctIndex << endl;
                    out << endl;
                }
            }
            out << "===" << endl;
        }
        out.close();
        return true;
    }

    bool TestManager::importFromText(const String& filename) {
        ifstream in(filename.to_char());
        if (!in) return false;

        Category curCategory;
        Test curTest;
        Question curQuestion;

        bool inQuestion = false;
        bool inTest = false;

        categories.clear();
        String line;
        while (in >> line) {
            if (line.rfind("Category:", 0) == 0) {
                if (inTest) { curTest = Test(); inTest = false; }
                if (inQuestion) { curQuestion = Question(); inQuestion = false; }
                if (!curCategory.name.is_empty()) { 
                    categories.push_back(curCategory); curCategory = Category(); 
                }
                curCategory.name = line.substr(10);
            }
            else if (line.rfind("Test:", 0) == 0) {
                if (inQuestion) { curTest.questions.push_back(curQuestion); inQuestion = false; }
                if (!curTest.name.is_empty()) { curCategory.tests.push_back(curTest); curTest = Test(); }
                curTest.name = line.substr(6); inTest = true;
            }
            else if (line.rfind("Q:", 0) == 0) {
                if (inQuestion) { curTest.questions.push_back(curQuestion); curQuestion = Question(); }
                curQuestion.text = line.substr(3); curQuestion.options.clear(); inQuestion = true;
            }
            else if (line.rfind("O:", 0) == 0) {
                curQuestion.options.push_back(line.substr(3));
            }
            else if (line.rfind("A:", 0) == 0) {
                int idx = line.substr(3).to_int(); curQuestion.correctIndex = idx;
            }
            else if (line == "===") {
                if (inQuestion) { curTest.questions.push_back(curQuestion); inQuestion = false; }
                if (!curTest.name.is_empty()) { curCategory.tests.push_back(curTest); curTest = Test(); }
                if (!curCategory.name.is_empty()) { categories.push_back(curCategory); curCategory = Category(); }
            }
        }
        if (inQuestion) curTest.questions.push_back(curQuestion);
        if (!curTest.name.is_empty()) curCategory.tests.push_back(curTest);
        if (!curCategory.name.is_empty()) categories.push_back(curCategory);
        saveAll();
        return true;
    }

    const Category* TestManager::findCategory(const String& name) const {
        for (size_t i = 0; i < categories.get_size(); i++)
            if (categories.at(i).name == name) return &categories.at(i);
        return nullptr;
    }

    Category* TestManager::findCategory(const String& name) {
        for (size_t i = 0; i < categories.get_size(); i++)
            if (categories.at(i).name == name) return &categories.at(i);
        return nullptr;
    }

    const Test* TestManager::findTest(const String& categoryName, const String& testName) const {
        const Category* c = findCategory(categoryName); if (!c) return nullptr;
        for (size_t i = 0; i < c->tests.get_size(); i++)
            if(c->tests.at(i).name == testName) return &c->tests.at(i);
        return nullptr;
    }
}