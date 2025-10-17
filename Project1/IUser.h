#pragma once

#include <fstream>
#include "String.h"

namespace TestingSystem {

	class IUser
	{
	public:
		virtual ~IUser() {}

		/// <summary>
		/// ��������� ������ ������������ � ����� ������.
		/// </summary>
		/// <param name="out">- ����� ������</param>
		virtual void save(ofstream& out) const = 0;

		/// <summary>
		/// ��������� ������ ������������ �� ������ �����.
		/// </summary>
		/// <param name="in">- ����� �����</param>
		virtual void load(ifstream& in) = 0;

		/// <summary>
		/// �������� ������� ������ ������������ �� �����.
		/// </summary>
		/// <param name="newPassword">- ����� ������</param>
		virtual void changePassword(const String& newPassword) = 0;
	};

}