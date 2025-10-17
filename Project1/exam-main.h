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
            String l, p; 
            cout << "Admin login: "; cin >> l;
            cout << "Admin password: "; cin >> p;
            userManager.setAdmin(l,p);
            userManager.saveAll();

            cout << endl << "Congractulations!" << endl;
            cout << "Press Enter..."; cin.get();
        }
        while (true) {
            system("cls");
            cout << "Hey! Glad to see you." << endl << "So register or login to continue.";
            int selectedAction = Menu::select_vertical({ "Login", "Register", "Exit" }, Left, 3);
            if (selectedAction == 0) {
                String l, p; 
                cout << "Login: "; cin >> l;
                cout << "Password: "; cin >> p;
                bool isAdmin = false;
                Participant* pt = userManager.loginUser(l, p, isAdmin);
                if (isAdmin)
                    AdminMenu::open(userManager, testManager);
                else if (pt) {
                    ParticipantMenu::open(userManager, testManager, pt);
                }
                else { cout << "Bad credentials" << endl << "Press Enter..."; cin.get(); }
            }
            else if (selectedAction == 1) {
                String fn, adr, ph, l, p;
                cout << "Full name: "; cin >> fn;
                cout << "Address: ";   cin >> adr;
                cout << "Phone: ";     cin >> ph;
                cout << "Login: ";     cin >> l;
                if (!userManager.isLoginUnique(l)) { 
                    cout << "Login taken" << endl;
                    cout << "Press Enter..."; cin.get(); continue; 
                }
                cout << "Password: "; cin >> p;
                Participant pt(fn, adr, ph, l, Hash::MD5(p));
                userManager.registerUser(pt);
                cout << "Registration completed successfully." 
                    << endl << "You may now sign in." 
                    << endl << endl << "Press Enter..."; 
                cin.get();
            }
            else break;
        }
	}
}