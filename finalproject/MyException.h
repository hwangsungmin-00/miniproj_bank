#ifndef MyException_h
#define MyException_h
#include <cstring>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyException {
public:
	string message;
	string getMessage()
	{
		string message = "¿À·ù";
		return message;
	}
};

#endif