#pragma once

#include "IUser.h"

#include "Test.h"
#include "Question.h"

#include "String.h"

namespace TestingSystem {

	class Admin : public IUser
	{
		String login;
		String password;
	public:
		Admin() = default;

		void save(ofstream& out) const override;
		void load(ifstream& in) override;
		void changePassword(const String& newPassword) override;

		const String& getLogin() const { return login; }
		const String& getPasswordHash() const { return password; }
		void setLogin(const String& l) { login = l; }
		void setPasswordHash(const String& p) { password = p; }

		bool isEmpty() const { return login.is_empty(); }
	};

	inline void Admin::save(ofstream& out) const
	{
		login.save(out);
		password.save(out);
	}

	inline void Admin::load(ifstream& in)
	{
		login.load(in);
		password.load(in);
	}

	inline void Admin::changePassword(const String& newPassword) {
		password = newPassword;
	}
}