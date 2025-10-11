#pragma once

#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>

#include "MyFunctions.h"
#include "mylibrary.h"
#include "myStructures.h"
#include "anyTypeArray.h"
#include "Bank.h"
#include"Menu.h"

struct Currency
{
	unsigned int size = 3;
	char* name = new char[4];
};

struct Account 
{
	Currency currency;
	int balance = 0;
	int creditLimit = 500;
	int creditBalance = 0;

	void menu()
	{
		system("cls");
		cout << " User: " << currency.name << endl;
		cout << "----------------" << endl;
		int c = Menu::select_vertical({ "Add sum", "Withdraw sum", "Exit" }, HorizontalAlignment::Left, 2);
		switch (c)
		{
		case 0:
			addSum();
			break;
		case 1:
			WithdrawSum();
			break;
		case 2:
			return;
		default:
			break;
		}
	}

	void addSum()
	{
		system("cls");
		int sum;
		cout << "Balance: " << balance << " " << currency.name;
		cout << "Enter Sum : ";
		cin >> sum;
		cin.ignore();
		balance += sum;
		cout << "Sum added" << endl << endl;
		system("pause");

	}

	void WithdrawSum()
	{
		system("cls");
		int sum;
		cout << "Balance: " << balance << " " << currency.name;
		cout << "Enter Sum : ";
		cin >> sum;
		cin.ignore();
		if (balance < sum) 
		{
			if (creditBalance + sum > creditLimit) 
			{
				cout << "А А А, Вы достигли кредитного лимита";
				system("pause");
			}
			else {
				creditBalance = creditBalance + sum - balance;
				balance = 0;
			}
		}
		else
		{
			balance -= sum;
			cout << "Sum wihtrawed" << endl << endl;
			system("pause");
		}
	}

	void print()
	{
		cout << "Balance: " << balance << " " << currency.name << " | CreditBalance - " << creditBalance << " " << currency.name << endl;
	}
};

struct Client 
{
	char currencys[3][4] = {"UAH", "USD", "EUR"};
	char* name;
	Account* accounts = nullptr;
	unsigned int size = 0;

	void addAccount()
	{
		system("cls");
		cout << name << " : Add Account" << endl;
		cout << "----------------------------" << endl;
		cout << "       Choose currency plz";
		Account account;
		int c = Menu::select_vertical({ currencys[0], currencys[1], currencys[2]}, HorizontalAlignment::Left, 2);
		switch (c)
		{
		case 0:
			strcpy_s(account.currency.name, 4, currencys[0]);
			break;
		case 1:
			strcpy_s(account.currency.name, 4, currencys[1]);
			break;
		case 2:
			strcpy_s(account.currency.name, 4, currencys[2]);
			break;
		default:
			break;
		}
		add(accounts, size, account);
		cout << "Account added" << endl;
		cout << endl;
		system("pause");
	}

	void delAccount()
	{
		system("cls");
		cout << "Delete Account" << endl;
		cout << "-------------" << endl;
		cout << "Account list" << endl;
		cout << "-------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 << " " << accounts[i].currency.name << endl;
		}
		cout << endl;
		cout << "Enter Number";
		int number;
		cin >> number;
		cin.ignore();
		if (accounts[number - 1].balance > 0)
			cout << "Сперва снимите маней";
			system("pause");
			return;
		pop(accounts, size, number - 1);
		cout << "Account deleted" << endl;
		cout << endl;
		system("pause");
	}

	void workWithAccount()
	{
		printAccount();
		cout << "Enter Number";
		int number;
		cin >> number;
		cin.ignore();
		accounts[number - 1].menu();
	}

	void printAccount(bool withPause = false)
	{
		system("cls");
		cout << "Account list" << endl;
		cout << "-----------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 << " - ";
			accounts[i].print();
		}
		cout << endl;
		if(withPause)
		{
			system("pause");
		}
	}

	void menu()
	{
		do
		{
			system("cls");
			cout << name << endl;
			cout << "-----------" << endl;
			int c = Menu::select_vertical({ "Add account", "Del account", "Print account", "Work with account", "Exit" }, HorizontalAlignment::Left, 1);
			switch (c)
			{
			case 0:
				addAccount();
				break;
			case 1:
				delAccount();
				break;
			case 2:
				printAccount(true);
				break;
			case 3:
				workWithAccount();
				break;
			case 4:
				return;
				break;
			default:
				break;
			}

		} while (true);
	}
};

struct Bank 
{
	Client* clients = nullptr;
	unsigned int size = 0;

	void addClient() 
	{
		system("cls");
		cout << "Add Client" << endl;
		cout << "-------------" << endl;
		char buffer[80];
		cout << "Enter Name: ";
		cin.getline(buffer, 80);
		Client client;
		client.name = new char[strlen(buffer) + 1];
		strcpy_s(client.name, strlen(buffer) + 1, buffer);
		add(clients, size, client);
		cout << "Client added" << endl;
		cout << endl;
		system("pause");
	}

	void delClient()
	{
		system("cls");
		cout << "Delete Client" << endl;
		cout << "-------------" << endl;
		cout << "Client list" << endl;
		cout << "-------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 << " " << clients[i].name << endl;
		}
		cout << endl;
		cout << "Enter Number: ";
		int number;
		cin >> number;
		cin.ignore();
		pop(clients, size, number - 1);
		cout << "Client deleted" << endl;
		cout << endl;
		system("pause");
	}

	void printClients()
	{
		cout << "Client list" << endl;
		cout << "-------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << clients[i].name << endl;
		}
		system("pause");
	}

	void workWithClient()
	{
		system("cls");
		cout << "Client list" << endl;
		cout << "-------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 << " - " << clients[i].name << endl;
		}
		cout << endl;
		cout << "Enter Number: ";
		int number;
		cin >> number;
		cin.ignore();
		clients[number - 1].menu();
	}

	void menu()
	{
		do
		{
			system("cls");
			cout << "----Bank----" << endl;
			int c = Menu::select_vertical({ "Add client", "Del client", "Print clients", "Work with clients", "Exit"}, HorizontalAlignment::Left, 1);
			switch (c)
			{
			case 0:
				addClient();
				break;
			case 1:
				delClient();
				break;
			case 2:
				printClients();
				break;
			case 3:
				workWithClient();
				break;
			case 4:
				exit(0);
			default:
				break;
			}
		} while (true);
	}
};