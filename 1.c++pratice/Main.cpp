#include "Account.h"

void main(void)
{
    Bank obj;
    int choice = 1;
    while (choice != 0)
    {
        cout << "Enter 0 to exit\n1. Initialize a new acc.\n2. Deposit\n3. Withdraw\n4. See A / c Status\n";
        cin >> choice;
        cin.ignore();
        cout << endl;
        switch (choice)
        {
        case 0:
            obj.disp_det();
            cout << "EXITING PROGRAM." << endl;
            break;
        case 1:
            obj.init();
            cout << endl;
            break;
        case 2:
            obj.deposit();
            cout << endl;
            break;
        case 3:
            obj.withdraw();
            cout << endl;
            break;
        case 4:
            obj.disp_det();
            cout << endl;
            break;
        default:
            cout << "Illegal Option" << endl;
            cout << endl;
        }
    }
    
    system("PAUSE");
}