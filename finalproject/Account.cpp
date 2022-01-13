//��ǻ�Ͱ��а� 20200965 Ȳ����
#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int accountNo, char* name, int balance)
{
	this->accountNo = accountNo;
	this->balance = balance;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Account::Account(const Account& a)
{
	accountNo = a.accountNo;
	balance = a.balance;

	name = new char[strlen(a.name) + 1];
	strcpy(name, a.name);
}
Account::~Account(void)
{
	delete[] name;
}

void Account::Deposit(int amount)
{
	balance = balance + amount;
	
}//�Ա�
int Account::Withdraw(int amount)
{
	balance -= amount;
	return balance;
}
//����
void Account::Check(void) const
{
	cout << "�̸�: " << name << endl;
	cout << "���¹�ȣ: " << accountNo << endl;
	cout << "�ܾ�: " << balance << endl;
}
//�ܾ���ȸ

bool Account::operator==(int a) const
{
	if (this->accountNo == a)
		return true;
	else
		return false;
}
Account& Account::operator=(const Account& a)
{
	this->accountNo = a.accountNo;
	this->balance = a.balance;
	this->name = new char[strlen(a.name) + 1];
	strcpy(this->name, a.name);

	return *this;
}