//��ǻ�Ͱ��а� 20200965 Ȳ����
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::ShowMenu(void)
{
	cout << "���� ���� �ý���(1�ܰ�)" << endl;
	cout << "===========================" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. ��ü �������� ���" << endl;
	cout << "5. Ư�� ���� ��ȸ" << endl;
	cout << "6. ���� ����" << endl;
	cout << "7. ����" << endl;
	cout << "===========================" << endl;
}
int Menu::InputMenu(void)
{
	cout << "����: ";
	static int n;
	cin >> n;
	cout << endl;
	return n;
}