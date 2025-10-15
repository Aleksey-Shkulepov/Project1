#pragma once

#include "UserManager.h"
#include "TestManager.h"
#include "TestResult.h"

#include "Menu.h"

namespace TestingSystem {

	class AdminMenu
	{
    public:
        static void open(UserManager& um, TestManager& tm) {
            while (true) {
                int sel = Menu::select_vertical({ "Manage users", "Manage tests", "View/Export stats", "Change admin password", "Back" }, Center, 6);
                if (sel == 0) {
                    int s2 = Menu::select_vertical({ "List users", "Create user", "Delete user", "Back" }, Left, 10);
                    if (s2 == 0) {
                        auto logins = um.listUserLogins();
                        for (auto& l : logins) cout << l.to_char() << "\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 1) {
                        string fn, adr, ph, lg, pw;
                        cout << "Full name: "; getline(cin, fn);
                        cout << "Address: "; getline(cin, adr);
                        cout << "Phone: "; getline(cin, ph);
                        cout << "Login: "; getline(cin, lg);
                        cout << "Password: "; getline(cin, pw);
                        Participant p(String(fn.c_str()), String(adr.c_str()), String(ph.c_str()), String(lg.c_str()), Hash::MD5(String(pw.c_str())));
                        if (!um.registerUser(p)) cout << "Login already used\n"; else cout << "Created\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 2) {
                        cout << "Login to delete: "; string dl; getline(cin, dl);
                        if (um.deleteUser(String(dl.c_str()))) cout << "Deleted\n"; else cout << "Not found\n";
                        cout << "Press Enter..."; cin.get();
                    }
                }
                else if (sel == 1) {
                    // Manage tests -> use TestManager menus (list/create category/test/question, import/export)
                    int s2 = Menu::select_vertical({ "List categories", "Create category", "Create test", "Add question", "Import from txt", "Export to txt", "Back" }, Left, 10);
                    if (s2 == 0) {
                        auto cats = tm.listCategories();
                        for (auto& c : cats) cout << c.to_char() << "\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 1) {
                        cout << "Category name: "; string cn; getline(cin, cn);
                        if (tm.createCategory(String(cn.c_str()))) cout << "Created\n"; else cout << "Exists\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 2) {
                        cout << "Category name: "; string cn; getline(cin, cn);
                        cout << "Test name: "; string tn; getline(cin, tn);
                        Test t; t.name = String(tn.c_str());
                        if (tm.createTest(String(cn.c_str()), t)) cout << "Test created\n"; else cout << "Fail (category?)\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 3) {
                        cout << "Category: "; string cn; getline(cin, cn);
                        cout << "Test: "; string tn; getline(cin, tn);
                        Question q; string qt; cout << "Question text: "; getline(cin, qt); q.text = String(qt.c_str());
                        cout << "How many options: "; int n; cin >> n; cin.ignore(/*std::numeric_limits<std::streamsize>::max()*/1, '\n');
                        for (int i = 0;i < n;++i) { string opt; cout << "Option " << i << ": "; getline(cin, opt); q.options.push_back(String(opt.c_str())); }
                        cout << "Index of correct option (0-based): "; int idx; cin >> idx; cin.ignore(/*std::numeric_limits<std::streamsize>::max()*/1, '\n'); q.correctIndex = idx;
                        if (tm.addQuestion(String(cn.c_str()), String(tn.c_str()), q)) cout << "Added\n"; else cout << "Fail\n";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 4) {
                        cout << "Import filename: "; string fn; getline(cin, fn);
                        tm.importFromText(fn.c_str());
                        cout << "Imported\n"; cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 5) {
                        cout << "Export filename: "; string fn; getline(cin, fn);
                        tm.exportToText(fn.c_str());
                        cout << "Exported\n"; cout << "Press Enter..."; cin.get();
                    }
                }
                else if (sel == 2) {
                    // statistics: simple per-user or per-test aggregation from users' results
                    int s2 = Menu::select_vertical({ "By user", "By category/test (basic)", "Export to file", "Back" }, Left, 10);
                    if (s2 == 0) {
                        cout << "Enter user login: "; string ul; getline(cin, ul);
                        Participant* p = um.findParticipant(String(ul.c_str()));
                        if (!p) { cout << "Not found\n"; cout << "Press Enter..."; cin.get(); continue; }
                        p->viewResults();
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (s2 == 2) {
                        cout << "Export filename: "; string fn; getline(cin, fn);
                        std::ofstream out(fn);
                        auto logins = um.listUserLogins();
                        for (auto& l : logins) {
                            Participant* p = um.findParticipant(l);
                            out << l.to_char() << "\n";
                            for (auto& r : p->getResults()) {
                                out << "  " << r.testName.to_char() << " " << r.correct << "/" << r.total << " " << r.mark << "\n";
                            }
                        }
                        out.close();
                        cout << "Exported\n"; cout << "Press Enter..."; cin.get();
                    }
                }
                else if (sel == 3) {
                    cout << "New admin password: "; string np; getline(cin, np);
                    um.getAdmin()->changePassword(String(np.c_str()));
                    um.saveAll();
                    cout << "Changed\n"; cout << "Press Enter..."; cin.get();
                }
                else break;
            }
        }
	};

}