#ifndef _BalanceOutOfBoundsException_h
#define _BalanceOutOfBoundsException_h
#include <cstring>
#include <string>
#include "MyException.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class BalanceOutOfBoundsException :public MyException {
public:
	string message;
	string getMessage()
	{
		string message = "잔액이 부족합니다!\n";
		return message;
	}

};

#endif