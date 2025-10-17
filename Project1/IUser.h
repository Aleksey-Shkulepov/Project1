#pragma once

#include <fstream>
#include "String.h"

namespace TestingSystem {

	class IUser
	{
	public:
		virtual ~IUser() {}

		/// <summary>
		/// Сохраняет данные пользователя в поток вывода.
		/// </summary>
		/// <param name="out">- поток вывода</param>
		virtual void save(ofstream& out) const = 0;

		/// <summary>
		/// Загружает данные пользователя из потока ввода.
		/// </summary>
		/// <param name="in">- поток ввода</param>
		virtual void load(ifstream& in) = 0;

		/// <summary>
		/// Изменяет текущий пароль пользователя на новый.
		/// </summary>
		/// <param name="newPassword">- Новый пароль</param>
		virtual void changePassword(const String& newPassword) = 0;
	};

}