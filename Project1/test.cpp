//--------------------------------------------------------------------
//202011237 ��ǻ�Ͱ��а� ��μ�
//
//                                       test.cpp
//
//--------------------------------------------------------------------
// 

#include "phonebooks_birthdays.h"
#include <string>
void print_help() {
	cout << "Commands:" << endl;
	cout << "       R: read from a file" << endl;
	cout << "       +: add a new entry" << endl;
	cout << "       -: remove an entry" << endl;
	cout << "       W: write to a file" << endl;
	cout << "       M: select a month" << endl;
	cout << "       Q: quit the program" << endl;
}

void main() {

	List testList;
	char cmd;
    string _filename;


    do
    {
        print_help();                  // Read command
        cout << "       ";
        cin >> cmd;

        switch (cmd)
        {
        case 'R': case 'r': //�б�
            testList.read();
            testList.showMonth();
            break;

        case 'W': case 'w': //����
            testList.write();
            break;

        case 'M':  case 'm': //�˻�
            testList.search();
            break;

        case '+':   //�߰�
            testList.insert();
            testList.showMonth();
            break;

        case '-':   //����
            testList.remove();
            testList.showMonth();
            break;
          
        case 'Q':case 'q':
            break;

        case 's':
            testList.showStructure();
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'Q' && cmd != 'q');
}