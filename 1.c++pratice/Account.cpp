#include "Account.h"

Bank::Bank()
{

}

//�Է¹ޱ�
void Bank::init()
{
	cout << "New Account" << endl;
	cout << "Enter the Name of the depsoitor :";
	cin >> name;
	cout << "Enter the Account Number :";
	cin >> acno;
	cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT)";
	cin >> actype;
	cout << "Enter the Amount to Deposit :";
	cin >> balance;
}
//����
void Bank::deposit()
{
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit :";
	float depositMoney = 0;
	cin >> depositMoney;
	//����� �ޱ�
	if (depositMoney > 0)
	{
		balance += depositMoney;
	}
	else
		cout << "input error. Only positive numbers";
}

//����
void Bank::withdraw()
{
	cout << "Withdrwal" << endl;
	cout << "Enter the amount to withdraw :";
	float withdrawMoney = 0;
	cin >> withdrawMoney;
	//����� �ޱ�
	if (withdrawMoney < 0)
		cout << "input error. Only positive numbers";
	//������� �ܾ׺��� ���� ��츸 �����ϱ�
	else if (balance > withdrawMoney)
		balance -= withdrawMoney;
	//������� �ܾ׺��� ū ��� �ܾ� ���� ���
	else if(balance < withdrawMoney)
		cout << "Insufficient funds.";
}

//��ȸ�ϱ�
void Bank::disp_det()
{
	cout << "Account Details"<<endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number        : " << acno << endl;
	cout << "Account Type          :" << actype << endl;
	cout << "Balance               : $" << balance << endl;
}