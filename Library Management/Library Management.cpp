#include <iostream>
#include <string>
#include <vector>
#include "Utility.h"
#include "LibarayDatabase.h"
#include "Librarian.h"
#include "Member.h"

using namespace std;

int main()
{
	LibarayDatabase libarayDatabase;

	Librarian test("Yuba","Neupane","4125556656","555 main street", "Pittsburgh","PA","15227","Baldwin");
	test.setPassword("password");
	test.setId(1002);

	libarayDatabase.addLibrarian(test);

	Utility utility(&libarayDatabase);

	utility.toggleFullScreen();

	while (true) {
		int choice = utility.displayMainMenu();
		if (choice == 1) {
			//Member Login
			bool isLogined = utility.displayMemberLoginScreen();
			if (isLogined) { 
				utility.displayMemberMenu();
			}
			else {
				cout << "Sorry, couldn't login you in...." << endl;
				Sleep(1500);
			}

		}
		else if (choice == 2) {
			//Admin Login
			bool isLogined = utility.displayLibrarianLoginScreen();
			if (isLogined) {
				utility.displayLibrarianMenu();
			}
		}
		else if (choice == 3) {
			utility.displaySettingMenu();
		}
		else if (choice == 4) {
			//Exit
			break;
		}
	}

	return 0;
}
