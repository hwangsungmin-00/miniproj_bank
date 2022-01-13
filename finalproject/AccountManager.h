//컴퓨터공학과 20200965 황성민
#ifndef _ACCOUTMANAGER_H
#define _ACCOUNTMANAGER_H
#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "MalformedData.h"
#include "BalanceOutOfBoundsException.h"
#include <iostream>
using namespace std;

class AccountManager {
	static const int MAX_ACCOUNTS = 100;

	Account* accounts[MAX_ACCOUNTS];
	int size=0;

	int Search(int accountNo) const;
public:
	AccountManager(void)
	{
		size = 0;
	}
	~AccountManager(void);

	void CreateAccount(void);
	void Deposit(void);
	void Withdraw(void);
	void DisplayAll(void) const;
	void DisplayOne(void) const;
	void CloseAccount(void);
};
#endif
/*class MyException {
protected:
	string message;
public:
	string getMessage();
};

class MalformedData : public MyException {
protected:
	string message;
public:
	string getMessage();
};

class BalanceOutOfBoundsException : public MyException {
protected:
	string message;
public:
	string getMessage();
};*/