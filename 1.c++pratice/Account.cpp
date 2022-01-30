#include "Account.h"

Bank::Bank()
{

}

//입력받기
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
//예금
void Bank::deposit()
{
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit :";
	float depositMoney = 0;
	cin >> depositMoney;
	//양수만 받기
	if (depositMoney > 0)
	{
		balance += depositMoney;
	}
	else
		cout << "input error. Only positive numbers";
}

//인출
void Bank::withdraw()
{
	cout << "Withdrwal" << endl;
	cout << "Enter the amount to withdraw :";
	float withdrawMoney = 0;
	cin >> withdrawMoney;
	//양수만 받기
	if (withdrawMoney < 0)
		cout << "input error. Only positive numbers";
	//인출액이 잔액보다 작은 경우만 인출하기
	else if (balance > withdrawMoney)
		balance -= withdrawMoney;
	//인출액이 잔액보다 큰 경우 잔액 부족 출력
	else if(balance < withdrawMoney)
		cout << "Insufficient funds.";
}

//조회하기
void Bank::disp_det()
{
	cout << "Account Details"<<endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number        : " << acno << endl;
	cout << "Account Type          :" << actype << endl;
	cout << "Balance               : $" << balance << endl;
}