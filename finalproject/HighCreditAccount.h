//컴퓨터공학과 20200965 황성민
#ifndef _HighCreditAccount_h
#define _HighCreditAccount_h
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	char special;
	int specialRate;
public:
	HighCreditAccount(int accountNo, char* name, int balance, int interRate, char special) : NormalAccount(accountNo, name, balance, interRate)
	{
		this->special = special;
		if (special == 'A')
			specialRate = 7;
		else if (special == 'B')
			specialRate = 4;
		else if (special == 'C')
			specialRate = 2;
	}
	
	char GetHighCreditAccount(void) const
	{
		return special;
	}
	void Check(void) const
	{
		NormalAccount::Check();

		cout << "특별 이율: " << specialRate << " %";
	}

	void Deposit(int amount)
	{
		if (special == 'A')
			specialRate = 7;
		else if (special == 'B')
			specialRate = 4;
		else if (special == 'C')
			specialRate = 2;

		NormalAccount::Deposit(amount);
		Account::Deposit(amount * (specialRate / 100.0));
	}
};
#endif