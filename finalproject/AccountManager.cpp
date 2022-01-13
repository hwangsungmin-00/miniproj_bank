//컴퓨터공학과 20200965 황성민
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

	cout << "[계좌개설]" << endl;
	cout << "1. 보통예금 계좌" << endl;
	cout << "2. 신용신뢰 계좌" << endl;
	cout << "> 개설하고자 하는 계좌 종류는? ";
	cin >> n;

	if (n == 1)
	{
		cout << "계좌번호: ";
		cin >> accountNo;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "기본이율: ";
		cin >> interRate;

		accounts[size] = new NormalAccount(accountNo, name, balance, interRate);
		size++;
	}
	else if (n == 2)
	{
		cout << "계좌번호: ";
		cin >> accountNo;
		cout << "이름: ";
		cin >> name;
		cout << "입금액: ";
		cin >> balance;
		cout << "기본이율: ";
		cin >> interRate;
		cout << "신용등급: ";
		cin >> special;

		accounts[size] = new HighCreditAccount(accountNo, name, balance, interRate, special);
		size++;
	}
	else
	{
		cout << "\n1, 2를 제외한 다른 수는 입력할 수 없습니다.\n" << endl;
	}

	cout << "\n계좌 생성 완료\n" << endl;
	
}
void AccountManager::Deposit(void)
{
	int amount;
	int accountNo;
	cout << "[입금]" << endl;
	cout << "계좌번호: ";
	cin >> accountNo;
	cout << "입금액: ";
	cin >> amount;

	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
		{
			accounts[i]->Deposit(amount);
			cout << "\n[입금완료]\n" << endl;

		}
	}

	
}
void AccountManager::Withdraw(void)
{
	int amount;
	int accountNo;
	cout << "[출금]" << endl;
	cout << "계좌번호: ";
	cin >> accountNo;
	

	for (int i = 0; i < size; i++)
	{
		if (accountNo == accounts[i]->GetAccountNo())
		{
			cout << "출금액: ";
			cin >> amount;
			if (amount > accounts[i]->GetBalance())
				throw BalanceOutOfBoundsException();
			else
			{
				accounts[i]->Account::Withdraw(amount);
				cout << amount<<"원 인출하였습니다." << endl;
				cout << "\n[출금완료]\n" << endl;
			}

			
			return;
		}
	}

	throw MalformedData();
}

void AccountManager::DisplayAll(void) const
{
	cout << "[조회]" << endl;
	
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
	cout << "정보를 알고싶은 계좌번호를 입력하세요: ";
	cin >> an;
	ind=Search(an);
	accounts[ind]->Check();
	cout << endl;
}


void AccountManager::CloseAccount(void) {// 계좌 해지
	int accountNo;
	char* name = new char[100];
	cout << "[계좌해지]" << endl;
	cout << "계좌번호 : ";
	cin >> accountNo;
	cout << "소유주 : ";
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
	cout << "\n[계좌해지 완료]\n" << endl;
}

