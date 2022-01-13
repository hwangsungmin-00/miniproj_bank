//컴퓨터공학과 20200965 황성민
#ifndef _ACCOUNT_H
#define _ACCOUNT_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Account {
protected:
	int accountNo;
	int balance;
	char* name;
public:
	Account(int accountNo, char* name, int balance=0);
	Account(const Account&);
	~Account(void);

	int GetAccountNo(void) const
	{
		return accountNo;
	}
	int GetBalance(void) const
	{
		return balance;
	}
	char* GetName(void) const
	{
		return name;
	}

	virtual void Deposit(int amount); //입금
	int Withdraw(int amount); //인출
	virtual void Check(void) const; //잔액조회

	bool operator==(int) const;
	Account& operator=(const Account&);
};
#endif