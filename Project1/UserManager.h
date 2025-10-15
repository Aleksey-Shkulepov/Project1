#pragma once

#include "Admin.h"
#include "Participant.h"

#include "String.h"
#include "Vector.h"

#include "Hash.h"

namespace TestingSystem {

	class UserManager
	{
		Admin admin;
		Vector<Participant> participants;
		String usersFile;
		String adminFile;
	public:
        UserManager(const String& usersFile = "users.bin", const String& adminFile = "admin.bin");
        ~UserManager() = default;

        void loadAll();
        void saveAll();

        bool isLoginUnique(const String& login) const;

        bool registerUser(const Participant& p);
        bool deleteUser(const String& login);

        Participant* findParticipant(const String& login);

        Participant* loginUser(const String& login, const String& passwordPlain, bool& isAdmin);

        Admin* getAdmin();

        Vector<String> listUserLogins() const;

        void setAdmin(const String& login, const String& passwordPlain);
	};

    UserManager::UserManager(const String& usersFile_, const String& adminFile_)
        : usersFile(usersFile_), adminFile(adminFile_) {}

    void UserManager::loadAll() {
        ifstream in(usersFile.to_char(), ios::binary);
        if (in) {
            size_t s; in.read((char*)&s, sizeof(s));
            participants.clear();
            for (size_t i = 0; i < s; ++i) {
                Participant p; p.load(in); participants.push_back(p);
            }
            in.close();
        }
        ifstream ain(adminFile.to_char(), ios::binary);
        if (ain) {
            admin.load(ain);
            ain.close();
        }
    }

    void UserManager::saveAll() {
        ofstream out(usersFile.to_char(), ios::binary);

        size_t s = participants.get_size();
        out.write((const char*)&s, sizeof(s));
        for (size_t i = 0; i < s; ++i)
            participants.at(i).save(out);

        out.close();

        ofstream aout(adminFile.to_char(), ios::binary);
        admin.save(aout);
        aout.close();
    }

    bool UserManager::isLoginUnique(const String& login) const {
        if (!admin.isEmpty())
            if (admin.getLogin() == login) return false;
        for (const auto& p : participants)
            if (p.getLogin() == login) return false;
        return true;
    }

    bool UserManager::registerUser(const Participant& p) {
        if (!isLoginUnique(p.getLogin())) return false;
        participants.push_back(p); 
        saveAll(); return true;
    }

    Participant* UserManager::findParticipant(const String& login) {
        for (auto& p : participants)
            if (p.getLogin() == login) return &p;
        return nullptr;
    }

    bool UserManager::deleteUser(const String& login) {
        for (auto& p : participants) {
            if (p.getLogin() == login) {
                participants.erase(&p); saveAll(); return true;
            }
        }
        return false;
    }

    Participant* UserManager::loginUser(const String& login, const String& password, bool& isAdmin) {
        if (!admin.isEmpty()) {
            if (admin.getLogin() == login) {
                if (admin.getPasswordHash() == Hash::MD5(password)) {
                    isAdmin = true; 
                    return nullptr;
                }
                else {
                    isAdmin = false; 
                    return nullptr;
                }
            }
        }

        for (auto& p : participants) {
            if (p.getLogin() == login) {
                if (p.getPassword() == Hash::MD5(password)) {
                    isAdmin = false;
                    return &p;
                }
                else {
                    break;
                }
            }
        }
        isAdmin = false;
        return nullptr;
    }

    Admin* UserManager::getAdmin() {
        return &admin;
    }

    Vector<String> UserManager::listUserLogins() const {
        Vector<String> res;
        for (const auto& p : participants) res.push_back(p.getLogin());
        return res;
    }

    void UserManager::setAdmin(const String& login, const String& passwordPlain) {
        admin.setLogin(login);
        admin.setPasswordHash(Hash::MD5(passwordPlain));
        saveAll();
    }
}