//--------------------------------------------------------------------------
// 
//      2020112377 컴퓨터공학전공 김민수
//
//		Project02 - Micro Facebook.  main.cpp
// 
// 
//-------------------------------------------------------------------------

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "microFB.h"

void print_help()   //Print Commands
{
    cout << "P <Name> - Create a person record of the specified name." << endl;
    cout << "F <Name1> <Name2> - Record that the two specified people are friends." << endl;
    cout << "U <Name1> <Name2> - Record that the two specified people are no longer friends." << endl;
    cout << "L <Name> - Print out the friends of the specified person." << endl;
    cout << "Q <Name1> <Name2> - Check whether the two people are friends." << endl;
    cout << "X - terminate the program." << endl;
    cout << endl;
}



int main()
{
    Facebook test;                     
    string inputName1, inputName2;       
    char cmd;                             

    print_help();

    do
    {
        cout << endl;

        cout << endl << "Command: ";                  // 입력
        cin >> cmd;
        if (cmd == 'P' || cmd == 'p' || cmd == 'L' || cmd == 'l')
            cin >> inputName1;
        else if (cmd == 'F' || cmd == 'f' || cmd == 'U' || cmd == 'u' || cmd == 'Q' || cmd == 'q')
            cin >> inputName1 >> inputName2;

        switch (cmd)
        {
        case 'H': case 'h':
            print_help();
            break;

        case 'P': case 'p':
            test.createPerson(inputName1);
            break;

        case 'F': case 'f':
            test.beFriend(inputName1, inputName2);
            break;

        case 'U': case 'u':
            test.unFriend(inputName1, inputName2);
            break;

        case 'L': case 'l':
            test.printFriend(inputName1);
            break;

        case 'Q': case 'q':
        {
            if (test.isFriend(inputName1, inputName2))
                cout << "Yes";
            else
                cout << "No";
        }
        break;

        case 'X': case 'x':
            test.fileWrite();
            break;

        default:                               // Invalid command
            cout << "Inactive or invalid command" << endl;
        }
    } while (cmd != 'X' && cmd != 'x');

}

