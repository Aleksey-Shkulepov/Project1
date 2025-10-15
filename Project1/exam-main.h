#pragma once

#include "mystd.h"
#include "fullstd.h"

#include "Menu.h"
#include "Hash.h"

#include "UserManager.h"
#include "TestManager.h"

#include "Participant.h"
#include "Admin.h"

#include "AdminMenu.h"
#include "ParticipantMenu.h"

namespace TestingSystem {
	void main()
	{
        UserManager userManager("users.bin", "admin.bin");
        TestManager testManager("tests.bin");
        userManager.loadAll(); testManager.loadAll();

        if (userManager.getAdmin()->isEmpty()) {
            cout << "Create admin account" << endl;
            String l, pw; 
            cout << "Admin login: "; cin >> l;
            cout << "Admin password: "; cin >> pw;
            userManager.setAdmin(l, Hash::MD5(pw));
            userManager.saveAll();
        }

        while (true) {
            int sel = Menu::select_vertical({ "Login", "Register (participant)", "Exit" }, Center, 6);
            if (sel == 0) {
                string login, pass; cout << "Login: "; getline(cin, login); cout << "Password: "; getline(cin, pass);
                bool isAdmin = false;
                Participant* p = userManager.loginUser(String(login.c_str()), String(pass.c_str()), isAdmin);
                if (isAdmin) {
                    AdminMenu::open(userManager, testManager);
                }
                else if (p) {
                    ParticipantMenu::open(userManager, testManager, p);
                }
                else {
                    cout << "Bad credentials\n"; cout << "Press Enter..."; cin.get();
                }
            }
            else if (sel == 1) {
                string fn, adr, ph, lg, pw;
                cout << "Full name: "; getline(cin, fn);
                cout << "Address: "; getline(cin, adr);
                cout << "Phone: "; getline(cin, ph);
                cout << "Login: "; getline(cin, lg);
                if (!userManager.isLoginUnique(String(lg.c_str()))) { cout << "Login taken\n"; cout << "Press Enter..."; cin.get(); continue; }
                cout << "Password: "; getline(cin, pw);
                Participant p(String(fn.c_str()), String(adr.c_str()), String(ph.c_str()), String(lg.c_str()), Hash::MD5(String(pw.c_str())));
                userManager.registerUser(p);
                cout << "Registered\n"; cout << "Press Enter..."; cin.get();
            }
            else break;
        }
	}
}