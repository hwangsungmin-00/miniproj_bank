//��ǻ�Ͱ��а� 20200965 Ȳ����
#ifndef _NormalAccount_h
#define _NormalAccount_h
#include "Account.h"

class NormalAccount : public Account {
private:
	int interRate;
public:
	NormalAccount(int accountNo, char* name, int balance, int interRate) : Account(accountNo, name, balance)
	{
		this->interRate = interRate;
	}

	int GetinterRate(void) const
	{
		return interRate;
	}
	void Check(void) const
	{
		Account::Check();
		cout << "�⺻ ����: " << interRate << " %";
	}

	void Deposit(int amount)
	{
		Account::Deposit(amount);
		Account::Deposit(amount * (interRate / 100.0));
	}
};
#endif