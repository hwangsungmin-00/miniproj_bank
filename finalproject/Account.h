//��ǻ�Ͱ��а� 20200965 Ȳ����
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

	virtual void Deposit(int amount); //�Ա�
	int Withdraw(int amount); //����
	virtual void Check(void) const; //�ܾ���ȸ

	bool operator==(int) const;
	Account& operator=(const Account&);
};
#endif