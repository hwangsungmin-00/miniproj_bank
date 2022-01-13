//컴퓨터공학과 20200965 황성민

#define _CRT_SECURE_NO_WARNINGS
#include "AccountManager.h"
#include "Menu.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "MalformedData.h"
#include "BalanceOutOfBoundsException.h"
#include <iostream>
using namespace std;

int main(void)
{
	AccountManager accMgr;
	int choice;
	enum MenuN { MENUITEM_CREATE = 1, MENUITEM_DEPOSIT, MENUITEM_WITHDRAW, MENUITEM_DISPLAY_ALL, MENUITEM_DISPLAY, MENUITEM_CLOSE, MENUITEM_EXIT=7 };

	do {
		Menu::ShowMenu();
		choice = Menu::InputMenu();

		try {
			switch (choice) {
			case MenuN::MENUITEM_CREATE:
				accMgr.CreateAccount();
				break;

			case MenuN::MENUITEM_DEPOSIT:
				accMgr.Deposit();
				break;

			case MenuN::MENUITEM_WITHDRAW:
				accMgr.Withdraw();
				break;
			case MenuN::MENUITEM_DISPLAY_ALL:
				accMgr.DisplayAll();
				break;
			case MenuN::MENUITEM_DISPLAY:
				accMgr.DisplayOne();
				break;
			case MenuN::MENUITEM_CLOSE:
				accMgr.CloseAccount();
				break;
			}
		}
			catch (MalformedData& e)
			{
				cout << e.getMessage() << endl;
			}
			catch (BalanceOutOfBoundsException& e)
			{
				cout << e.getMessage() << endl;
			}
		
		
	} while (choice != MenuN::MENUITEM_EXIT);
	
	
	
	

	
	accMgr.~AccountManager();
	return 0;
}