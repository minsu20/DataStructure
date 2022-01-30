//--------------------------------------------------------------------------
// 
//      2020112377 컴퓨터공학전공 김민수
//
//		Project03 - Tree Application.  main.cpp
// 
// 
//-------------------------------------------------------------------------

#include <iostream>
#include "tree.h"
using namespace std;

void print_help()
{
	cout << "<Rules of syntax>" << endl;
	cout << "[Existing member] hires [new member] " << endl;
	cout << "fire [existing member] " << endl;
	cout << "Print " << endl;
}

int main() {
	HierarchyTree org;
	cout << " -------------------------------------------------------------------------------------------" << endl;
	cout << "| All names in the input file consist of 2-20 characters,                                   | " << endl;
	cout << "| which may be upper - or lowercase letters, apostrophes, and hyphens (but no blank spaces).| " << endl;
	cout << "| Each name contains at least one uppercaseand at least one lowercase letter.               |" << endl;
	cout<< " -------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the name of the CEO: ";
	string ceo;
	cin >> ceo;
	org.hire("", ceo);
	cout << endl;
	print_help();
	string cmd;
	while (true) {
		cout << endl<< "Command: ";
			cin >> cmd;
			if (cmd == "Fire" || cmd == "fire") {
				string target;
				cin >> target;
				org.fire(target);
			}
			else if (cmd == "Print" || cmd == "print") {
				cout << endl;
				org.showStructure();
			}
			else if (cmd == "Q" || cmd == "q") {
				break;
			}
			else {
				string cmd2;
				cin >> cmd2;
				if (cmd2 == "Hires" || cmd2 == "hires")
				{
					string sub;
					cin >> sub;
					org.hire(cmd, sub);
				}
				else
					cout << "Inactive or invalid command" << endl;
				}
	}

	system("pause");
}