#pragma once

#include "UserManager.h"
#include "TestManager.h"
#include "TestResult.h"

#include "Menu.h"

namespace TestingSystem {

    class ParticipantMenu
    {
        static int calculateMark(int correct, int total) {
            if (total <= 0) return 0;
            return (int)((double)correct / total * 12 + 0.5);
        }
    public:
        static void open(UserManager& um, TestManager& tm, Participant* p) {
            while (true) {
                int sel = Menu::select_vertical({ "View past results", "Start/Resume test", "Back" }, Center, 8);
                if (sel == 0) { p->viewResults(); cout << "Press Enter..."; cin.get(); }
                else if (sel == 1) {
                    // show categories -> tests -> questions; minimal test engine with pause/resume
                    auto cats = tm.listCategories();
                    if (cats.is_empty()) { cout << "No categories\n"; cout << "Press Enter..."; cin.get(); continue; }
                    vector<string> catNames;
                    for (auto& c : cats) catNames.push_back(string(c.to_char()));
                    int ci = Menu::select_vertical(catNames, Left, 6);
                    String chosenCat(catNames[ci].c_str());
                    auto tests = tm.listTests(chosenCat);
                    if (tests.is_empty()) { cout << "No tests in category\n"; cout << "Press Enter..."; cin.get(); continue; }
                    vector<string> testNames;
                    for (auto& t : tests) testNames.push_back(string(t.to_char()));
                    int ti = Menu::select_vertical(testNames, Left, 8);
                    String chosenTest(testNames[ti].c_str());
                    const Test* testPtr = tm.findTest(chosenCat, chosenTest);
                    if (!testPtr) { cout << "Test not found\n"; cout << "Press Enter..."; cin.get(); continue; }
                    // run test
                    const Test& test = *testPtr;
                    int total = (int)test.questions.get_size();
                    int correct = 0;
                    for (int qi = 0; qi < total; ++qi) {
                        const Question& q = test.questions[qi];
                        cout << "Q" << (qi + 1) << ": " << q.text.to_char() << "\n";
                        for (int oi = 0; oi < (int)q.options.get_size(); ++oi) {
                            cout << "  " << oi << ") " << q.options[oi].to_char() << "\n";
                        }
                        cout << "Answer (index), or -1 to pause: ";
                        int ans; cin >> ans; cin.ignore(/*std::numeric_limits<std::streamsize>::max()*/1, '\n');
                        if (ans == -1) {
                            cout << "Paused. (resume not implemented in demo)\n"; break;
                        }
                        if (ans == q.correctIndex) ++correct;
                    }
                    int mark = calculateMark(correct, total);
                    TestResult tr; tr.testName = test.name; tr.correct = correct; tr.total = total; tr.mark = mark;
                    p->addResult(tr);
                    um.saveAll();
                    cout << "Test finished. Correct " << correct << "/" << total << ". Mark: " << mark << "/12\n";
                    cout << "Press Enter..."; cin.get();
                }
                else break;
            }
        }
    };

}