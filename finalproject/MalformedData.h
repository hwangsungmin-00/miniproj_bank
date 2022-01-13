#ifndef _MalformedData_h
#define _MalformedData_h

#include <cstring>
#include <string>
#include "MyException.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

class MalformedData :public MyException {
public:
	string message;
	string getMessage()
	{
		string message = "일치하는 계좌가 존재하지 않습니다!\n";
		return message;
	}

};

#endif