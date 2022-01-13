//��ǻ�Ͱ��а� 20200965 Ȳ����
#define _CRT_SECURE_NO_WARNINGS
#include "AccountManager.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int AccountManager::Search(int accountNo) const
{
	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
			return i;
		
	}
	throw MalformedData();
	
	return 0;
}


AccountManager::~AccountManager(void)
{
	for (int i = 0; i < 100; i++)
	{
		delete accounts[i];
	}
	delete []accounts;
}

void AccountManager::CreateAccount(void)
{
	int n;
	int accountNo;
	char* name = new char[100];
	int balance;
	int interRate;
	char special;

	cout << "[���°���]" << endl;
	cout << "1. ���뿹�� ����" << endl;
	cout << "2. �ſ�ŷ� ����" << endl;
	cout << "> �����ϰ��� �ϴ� ���� ������? ";
	cin >> n;

	if (n == 1)
	{
		cout << "���¹�ȣ: ";
		cin >> accountNo;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "�⺻����: ";
		cin >> interRate;

		accounts[size] = new NormalAccount(accountNo, name, balance, interRate);
		size++;
	}
	else if (n == 2)
	{
		cout << "���¹�ȣ: ";
		cin >> accountNo;
		cout << "�̸�: ";
		cin >> name;
		cout << "�Աݾ�: ";
		cin >> balance;
		cout << "�⺻����: ";
		cin >> interRate;
		cout << "�ſ���: ";
		cin >> special;

		accounts[size] = new HighCreditAccount(accountNo, name, balance, interRate, special);
		size++;
	}
	else
	{
		cout << "\n1, 2�� ������ �ٸ� ���� �Է��� �� �����ϴ�.\n" << endl;
	}

	cout << "\n���� ���� �Ϸ�\n" << endl;
	
}
void AccountManager::Deposit(void)
{
	int amount;
	int accountNo;
	cout << "[�Ա�]" << endl;
	cout << "���¹�ȣ: ";
	cin >> accountNo;
	cout << "�Աݾ�: ";
	cin >> amount;

	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
		{
			accounts[i]->Deposit(amount);
			cout << "\n[�ԱݿϷ�]\n" << endl;

		}
	}

	
}
void AccountManager::Withdraw(void)
{
	int amount;
	int accountNo;
	cout << "[���]" << endl;
	cout << "���¹�ȣ: ";
	cin >> accountNo;
	

	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
		{
			cout << "��ݾ�: ";
			cin >> amount;
			if (amount > accounts[i]->GetBalance())
				throw BalanceOutOfBoundsException();
			else
			{
				accounts[i]->Account::Withdraw(amount);
				cout << amount<<"�� �����Ͽ����ϴ�." << endl;
				cout << "\n[��ݿϷ�]\n" << endl;
			}

			
			return;
		}
	}

	throw MalformedData();
}

void AccountManager::DisplayAll(void) const
{
	cout << "[��ȸ]" << endl;
	
	for (int i = 0; i < size; i++)
	{
		accounts[i]->Check();
		cout << endl;

		cout << "\n\n" << endl;
	}
}
void AccountManager::DisplayOne(void) const
{
	int an;
	int ind;
	cout << "������ �˰���� ���¹�ȣ�� �Է��ϼ���: ";
	cin >> an;
	ind=Search(an);
	accounts[ind]->Check();
	cout << endl;
}


void AccountManager::CloseAccount(void) {// ���� ����
	int accountNo;
	char* name = new char[100];
	cout << "[��������]" << endl;
	cout << "���¹�ȣ : ";
	cin >> accountNo;
	cout << "������ : ";
	cin >> name;
	int ind = Search(accountNo);

	for (int i = 0; i < size; i++) {
		if ((accounts[i]->GetAccountNo()) == accountNo && (strcmp(accounts[i]->GetName(), name) == 0)) {
			for (int i = ind; i < size; i++)
			{
				accounts[i] = accounts[i + 1];
			}
		}
		size = size - 1;
	}
	cout << "\n[�������� �Ϸ�]\n" << endl;
}

