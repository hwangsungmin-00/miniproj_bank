//컴퓨터공학과 20200965 황성민
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::ShowMenu(void)
{
	cout << "계좌 관리 시스템(1단계)" << endl;
	cout << "===========================" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 전체 계좌정보 출력" << endl;
	cout << "5. 특정 계좌 조회" << endl;
	cout << "6. 계좌 해지" << endl;
	cout << "7. 종료" << endl;
	cout << "===========================" << endl;
}
int Menu::InputMenu(void)
{
	cout << "선택: ";
	static int n;
	cin >> n;
	cout << endl;
	return n;
}