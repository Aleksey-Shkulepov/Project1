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
        ifstream in(storageFile.to_str(), ios::binary);
        if (!in) return;

        size_t s; in.read((char*)&s, sizeof(s));
        categories.clear();
        for (size_t i = 0; i < s; ++i) {
            Category c; c.load(in); categories.push_back(c);
        }
    }

    void TestManager::saveAll() {
        ofstream out(storageFile.to_str(), ios::binary);

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
        ofstream out(filename.to_str());
        if (!out) return false;
        for (const auto& c : categories) {
            out << "Category: " << c.name.to_char() << "\n";
            for (const auto& t : c.tests) {
                out << "Test: " << t.name.to_char() << "\n";
                for (const auto& q : t.questions) {
                    out << "Q: " << q.text.to_char() << "\n";
                    for (const auto& o : q.options) out << "O: " << o.to_char() << "\n";
                    out << "A: " << q.correctIndex << "\n";
                    out << "\n";
                }
            }
            out << "===\n";
        }
        out.close();
        return true;
    }

    bool TestManager::importFromText(const String& filename) {
        ifstream in(filename.to_str());
        if (!in) return false;
        string line;
        Category curCat;
        Test curTest;
        Question curQ;
        bool inQ = false;
        bool inTest = false;
        categories.clear();
        while (getline(in, line)) {
            if (line.rfind("Category:", 0) == 0) {
                if (inTest) { curTest = Test(); inTest = false; }
                if (inQ) { curQ = Question(); inQ = false; }
                if (curCat.name.get_length() != 0) { categories.push_back(curCat); curCat = Category(); }
                std::string nm = line.substr(9);
                String s(nm.c_str()); curCat.name = s;
            }
            else if (line.rfind("Test:", 0) == 0) {
                if (inQ) { curTest.questions.push_back(curQ); inQ = false; }
                if (curTest.name.get_length() != 0) { curCat.tests.push_back(curTest); curTest = Test(); }
                std::string nm = line.substr(5); curTest.name = String(nm.c_str()); inTest = true;
            }
            else if (line.rfind("Q:", 0) == 0) {
                if (inQ) { curTest.questions.push_back(curQ); curQ = Question(); }
                std::string txt = line.substr(2); curQ.text = String(txt.c_str()); curQ.options.clear(); inQ = true;
            }
            else if (line.rfind("O:", 0) == 0) {
                std::string op = line.substr(2); curQ.options.push_back(String(op.c_str()));
            }
            else if (line.rfind("A:", 0) == 0) {
                int idx = stoi(line.substr(2)); curQ.correctIndex = idx;
            }
            else if (line == "===") {
                if (inQ) { curTest.questions.push_back(curQ); inQ = false; }
                if (curTest.name.get_length() != 0) { curCat.tests.push_back(curTest); curTest = Test(); }
                if (curCat.name.get_length() != 0) { categories.push_back(curCat); curCat = Category(); }
            }
        }
        if (inQ) curTest.questions.push_back(curQ);
        if (curTest.name.get_length() != 0) curCat.tests.push_back(curTest);
        if (curCat.name.get_length() != 0) categories.push_back(curCat);
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