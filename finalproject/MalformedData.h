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
		string message = "��ġ�ϴ� ���°� �������� �ʽ��ϴ�!\n";
		return message;
	}

};

#endif