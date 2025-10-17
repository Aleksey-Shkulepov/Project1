#pragma once

#include "UserManager.h"
#include "TestManager.h"
#include "TestResult.h"

#include "Menu.h"

namespace TestingSystem {

	class AdminMenu
	{
    public:
        static void open(UserManager& userManager, TestManager& testManager) {
            while (true) {
                system("cls");
                cout << "Hi again.";
                int selectedAction = Menu::select_vertical({ "Manage users", "Manage tests", "View/Export stats", "Change admin password", "Back" }, Left, 2);
                if (selectedAction == 0) {
                    system("cls");
                    cout << "Choose action: ";
                    int selectedActionWithUser = Menu::select_vertical({ "List users", "Create user", "Delete user", "Back" }, Left, 2);
                    if (selectedActionWithUser == 0) {
                        Vector<String> logins = userManager.listUserLogins();
                        system("cls");
                        cout << "List of users: " << endl;
                        for (size_t i = 0; i < logins.get_size(); i++)
                            cout << i+1 << "." << logins.at(i);
                        cout << endl << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithUser == 1) {
                        system("cls");
                        String fn, adr, ph, lg, pw;
                        cout << "Full name: "; cin >> fn;
                        cout << "Address: ";   cin >> adr;
                        cout << "Phone: ";     cin >> ph;
                        cout << "Login: ";     cin >> lg;
                        cout << "Password: ";  cin >> pw;
                        Participant p(fn, adr, ph, lg, Hash::MD5(pw));
                        if (!userManager.registerUser(p)) cout << "Login already used" << endl; 
                        else cout << "Successfully created!" << endl;
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithUser == 2) {
                        system("cls");
                        cout << "Choose user to delete: ";
                        Vector<String> logins = userManager.listUserLogins();
                        int selectedUser = Menu::select_vertical(logins, Left, 2);
                        userManager.deleteUser(logins.at(selectedUser));
                        cout << "Successfully Deleted!" << endl;
                        cout << "Press Enter..."; cin.get();
                    }
                }

                else if (selectedAction == 1) {
                    system("cls");
                    cout << "Choose the action: ";
                    int selectedActionWithTests = Menu::select_vertical({ "List categories", "Create category", "Create test", "Add question", "Import from txt", "Export to txt", "Back" }, Left, 2);
                    if (selectedActionWithTests == 0) {
                        Vector<String> categories = testManager.listCategories();
                        if (!categories.is_empty()){
                            cout << "List of categories: " << endl;
                            for (size_t i = 0; i < categories.get_size(); i++)
                                cout << i + 1 << "." << categories.at(i);
                        }
                        else cout << "No catogories yet." << endl << "Create at least one." << endl;
                        cout << endl << endl << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithTests == 1) {
                        cout << "Type category name: "; String cn; cin >> cn;
                        if (testManager.createCategory(cn)) cout << "Category Successfully Created!" << endl;
                        else cout << "Error" << endl;
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithTests == 2) {
                        Vector<String> categories = testManager.listCategories();
                        if (!categories.is_empty()) {
                            cout << "Choose the category: " << endl;
                            int selectedCategory = Menu::select_vertical(categories, Left, 2);
                            cout << "Type test name: "; String tn; cin >> tn;
                            Test t; t.name = tn;
                            if (testManager.createTest(categories.at(selectedCategory), t))
                                cout << "Test Successfully created" << endl;
                            else
                                cout << "Error" << endl;
                        }
                        else cout << "No catogories yet." << endl << " Create at least one.";
                        cout << "Press Enter..." << endl; cin.get();
                    }
                    else if (selectedActionWithTests == 3) {
                        Vector<String> categories = testManager.listCategories();
                        if (!categories.is_empty()) {
                            cout << "Choose the category: " << endl;
                            int selectedCategory = Menu::select_vertical(categories, Left, 2);

                            Vector<String> tests = testManager.listTests(categories.at(selectedCategory));
                            if (!tests.is_empty()) {
                                cout << "Choose the test: " << endl;
                                int selectedTest = Menu::select_vertical(tests, Left, 2);

                                Question q;
                                cout << "Type question text: "; String qt; cin >> qt; q.text = qt;
                                cout << "How many options: "; size_t n; cin >> n; cin.ignore();
                                for (size_t i = 0; i < n; i++) {
                                    String o; cout << "Option " << i << ": "; cin >> o;
                                    q.options.push_back(o);
                                }
                                cout << "Index of correct option: "; size_t i; cin >> i; q.correctIndex = i;
                                if (testManager.addQuestion(categories.at(selectedCategory), tests.at(selectedTest), q))
                                    cout << "Question Successfully added!" << endl;
                                else
                                    cout << "Error" << endl;
                                cout << "Press Enter..."; cin.get();
                            }
                            else cout << "No tests yet." << endl << " Create at least one.";
                        }
                        else cout << "No catogories yet." << endl << " Create at least one.";
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithTests == 4) {
                        cout << "Type import filename: "; String fn; cin >> fn;
                        testManager.importFromText(fn);
                        cout << "Successfully imported!" << endl; 
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionWithTests == 5) {
                        cout << "Export filename: "; String fn; cin >> fn;
                        testManager.exportToText(fn);
                        cout << "Successfully exported!" << endl;
                        cout << "Press Enter..."; cin.get();
                    }
                }
                else if (selectedAction == 2) {
                    cout << "Choose stats for: " << endl;
                    int selectedActionForStats = Menu::select_vertical({ "By user", "By category", "By test", "Export to file", "Back" }, Left, 2);
                    if (selectedActionForStats == 0) {
                        cout << "List of users: " << endl;
                        Vector<String> participants = userManager.listUserLogins();
                        int selectedUser = Menu::select_vertical(participants, Left, 2);

                        Participant* p = userManager.findParticipant(participants.at(selectedUser));
                        p->viewResults();
                        cout << "Press Enter..."; cin.get();
                    }
                    else if (selectedActionForStats == 1) {
                        Vector<String> categories = testManager.listCategories();
                        if (categories.is_empty()) { cout << "No catogories yet." << endl << " Create at least one."; cout << "Press Enter..."; cin.get(); }
                        cout << "Choose the category: " << endl;
                        int selectedCategory = Menu::select_vertical(categories, Left, 2);

                        Vector<String> tests = testManager.listTests(categories.at(selectedCategory));
                        if (tests.is_empty()) { cout << "No tests in this category." << endl << " Create at least one."; cout << "Press Enter..."; cin.get(); }

                        for (size_t iT = 0; iT < tests.get_size(); iT++)
                        {
                            Vector<Participant> listParticipants = userManager.listParticipants();
                            if (listParticipants.is_empty()) { cout << "No results yet."; cout << "Press Enter..."; cin.get(); }
                            for (size_t iP = 0; iP < listParticipants.get_size(); iP++)
                            {
                                Vector<TestResult> listResults = listParticipants.at(iP).getResults();
                                if (listResults.is_empty()) continue;
                                for (size_t iR = 0; iR < listResults.get_size(); iR++)
                                {
                                    if (listResults.at(iR).testName == tests.at(iT)) {
                                        cout << listParticipants.at(iP).getLogin() << endl;
                                        listResults.at(iR).print();
                                    }
                                }
                            }
                        }
                        cout << "Press Enter..."; cin.get();
                    }

                    else if (selectedActionForStats == 2) {
                        Vector<String> categories = testManager.listCategories();
                        if (categories.is_empty()) { cout << "No catogories yet." << endl << " Create at least one."; cout << "Press Enter..."; cin.get(); }
                        cout << "Choose the category: " << endl;
                        int selectedCategory = Menu::select_vertical(categories, Left, 2);

                        cout << "Choose the test: " << endl;
                        Vector<String> tests = testManager.listTests(categories.at(selectedCategory));
                        if (tests.is_empty()) { cout << "No tests in this category." << endl << " Create at least one."; cout << "Press Enter..."; cin.get(); }
                        int selectedTest = Menu::select_vertical(tests, Left, 2);
                        Vector<Participant> listParticipants = userManager.listParticipants();
                        if (listParticipants.is_empty()) { cout << "No results yet."; cout << "Press Enter..."; cin.get(); }
                        for (size_t iP = 0; iP < listParticipants.get_size(); iP++)
                        {
                            Vector<TestResult> listResults = listParticipants.at(iP).getResults();
                            if (listResults.is_empty()) continue;
                            for (size_t iR = 0; iR < listResults.get_size(); iR++)
                            {
                                if (listResults.at(iR).testName == tests.at(selectedTest)) {
                                    cout << listParticipants.at(iP).getLogin() << endl;
                                    listResults.at(iR).print();
                                }
                            }
                        }
                        cout << "Press Enter..."; cin.get();
                    }

                    else if (selectedActionForStats == 3) {
                        cout << "Export filename: "; String fn; cin >> fn;
                        ofstream out(fn.to_char());
                        Vector<String> logins = userManager.listUserLogins();
                        for (auto& l : logins) {
                            Participant* p = userManager.findParticipant(l);
                            out << l << endl;
                            for (auto& r : p->getResults()) {
                                out << "  " << r.testName << " " << r.correct << "/" << r.total << " " << r.mark << endl;
                            }
                        }
                        out.close();
                        cout << "Successfully Exported!"; cout << "Press Enter..."; cin.get();
                    }
                    else break;
                }
                else if (selectedAction == 3) {
                    cout << "New admin password: "; String np; cin >> np;
                    userManager.getAdmin()->changePassword(np);
                    userManager.saveAll();
                    cout << "Successfully Changed!" << endl;
                    cout << "Press Enter..."; cin.get();
                }
                else break;
            }
        }
	};

}