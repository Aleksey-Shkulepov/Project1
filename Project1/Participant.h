#pragma once

#include "IUser.h"

#include "Test.h"
#include "TestResult.h"

#include "String.h"
#include "Vector.h"

namespace TestingSystem {

	class Participant : public IUser
	{
		String fullName;
		String address;
		String phone;
		String login;
		String password;
		Vector<TestResult> results;
	public:
		Participant() = default;

		Participant (
			const String& fullName_,
			const String& address_,
			const String& phone_,
			const String& login_,
			const String& password_
		);

		void save(ofstream& out) const override;
		void load(ifstream& in) override;
		void changePassword(const String& newPassword) override;

		void viewResults() const;

		const String& getLogin() const    { return login; }
		const String& getPassword() const { return password; }
		void setPassword(const String& h) { password = h; }


		const String& getFullName() const { return fullName; }
		void setFullName(const String& s) { fullName = s; }
		void setAddress(const String& s)  { address = s; }
		void setPhone(const String& s)    { phone = s; }

		Vector<TestResult>& getResults() { return results; }
		void addResult(const TestResult& r)			 { results.push_back(r); }
		void deleteResult(const size_t i) { results.pop(i); }
	};

	Participant::Participant (
		const String& fullName_, 
		const String& address_, 
		const String& phone_, 
		const String& login_, 
		const String& password_
	) : 
		fullName(fullName_), 
		address(address_), 
		phone(phone_), 
		login(login_), 
		password(password_) 
	{}

	inline void Participant::save(ofstream& out) const
	{
		fullName.save(out);
		address.save(out);
		phone.save(out);
		login.save(out);
		password.save(out);

		size_t s = results.get_size();
		out.write((const char*)&s, sizeof(s));
		for (size_t i = 0; i < s; ++i)
			results.at(i).save(out);
	}

	inline void Participant::load(ifstream& in)
	{
		fullName.load(in);
		address.load(in);
		phone.load(in);
		login.load(in);
		password.load(in);

		size_t s; in.read((char*)&s, sizeof(s));
		results.clear();
		for (size_t i = 0; i < s; ++i) {
			TestResult tr; tr.load(in); results.push_back(tr);
		}
	}

	void Participant::changePassword(const String& newPassword) {
		password = newPassword;
	}

	void Participant::viewResults() const {
		if (results.is_empty()) {
			cout << "No results." << endl;
			return;
		}
		for (const auto& tr : results) {
			tr.print();
		}
	}
}