#pragma once

#include "UserManager.h"
#include "TestManager.h"
#include "TestResult.h"

#include "Menu.h"

namespace TestingSystem {

    class ParticipantMenu
    {
    public:
        static void open(UserManager& userManager, TestManager& testManager, Participant* p) {
            while (true) {
                system("cls");
                cout << "Choose action: " << endl;
                int selectedAction = Menu::select_vertical({ "View past results", "Start/Resume test", "Back" }, Left, 2);
                if (selectedAction == 0) { p->viewResults(); cout << "Press Enter..."; cin.get(); }
                else if (selectedAction == 1) {
                    Vector<String> categoriesNames = testManager.listCategories();
                    if (categoriesNames.is_empty()) {
                        cout << "No categories" << endl;
                        cout << "Press Enter..."; cin.get(); continue; 
                    }
                    String selectedCategory = categoriesNames.at(Menu::select_vertical(categoriesNames, Left, 2));

                    Vector<String> testsNames = testManager.listTests(selectedCategory);
                    if (testsNames.is_empty()) {
                        cout << "No tests in category" << endl; 
                        cout << "Press Enter..."; cin.get(); continue; 
                    }
                    String selectedTest = testsNames.at(Menu::select_vertical(testsNames, Left, 8));

                    const Test& test = *testManager.findTest(selectedCategory, selectedTest);

                    int currentQustion = 0;
                    int total = test.questions.get_size();
                    int correct = 0;
                    bool isFinish = true;
                    
                    Vector<TestResult>& pResults = p->getResults();
                    TestResult emptyTR;
                    TestResult& trg = emptyTR;
                    if (!pResults.is_empty())
                    {
                        for (size_t i = 0; i < pResults.get_size(); i++)
                        {
                            TestResult& tr = pResults.at(i);
                            if (tr.testName == test.name && tr.isPaused == true) {
                                system("cls");
                                cout << "Choose the option: ";
                                int selectedDoResetTest = Menu::select_vertical({ "Continue.", "Start again." }, Left, 2);
                                if (selectedDoResetTest == 1) break;
                                else {
                                    trg = tr;
                                    correct = tr.correct;
                                    currentQustion = tr.currentQuestion;
                                    break;
                                }
                            }
                        }
                    }

                    for (size_t i = currentQustion; i < total; ++i) {
                        system("cls");
                        const Question& q = test.questions.at(i);
                        cout << "Question " << (i + 1) << ": " << q.text << endl;
                        int selectedAnswer = Menu::select_vertical(q.options + Vector<String>{"Pause"}, Left, q.options.get_size());
                        if (selectedAnswer == q.correctIndex) ++correct;
                        else if (selectedAnswer == q.options.get_size()) {
                            TestResult tr; 
                            tr.testName = test.name; 
                            tr.correct = correct; 
                            tr.total = total;
                            tr.isPaused = true;
                            tr.currentQuestion = i;
                            p->addResult(tr);
                            userManager.saveAll();
                            system("cls");
                            cout << "Successfully paused!" << endl;
                            cout << "Returning to the main menu." << endl;
                            cout << "Press Enter..."; cin.get(); 
                            isFinish = false; break;
                        }
                    }
                    if (isFinish) {
                        int mark = (int)((double)correct / total * 12 + 0.5);
                        if (trg.isPaused == false) {
                            TestResult tr; tr.testName = test.name; tr.correct = correct; tr.total = total; tr.mark = mark;
                            p->addResult(tr);
                        }
                        else {
                            trg.correct = correct; trg.total = total; trg.mark = mark; trg.isPaused = false;
                        }
                        userManager.saveAll();
                        cout << "Test finished. Correct " << correct << "/" << total << ". Mark: " << mark << "/12\n";
                        cout << "Press Enter..."; cin.get();
                    }
                }
                else break;
            }
        }
    };

}