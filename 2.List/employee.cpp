//ÄÄÇ»ÅÍ°øÇÐ°ú 2020112377 ±è¹Î¼ö

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Employee {
public:
	void StoreEmployee();
	void DeleteEmployee(string theEmployee);
	void showEmployee();

private:
	int num;
	int findNum;
	int deletenum;
	string info[5];
};

void Employee::StoreEmployee() {
	num = 5;
	info[0] = "Hong Gildong";
	info[1] = "Kim Dongguk";
	info[2] = "Lee Hangook";
	info[3] = "Park Hanbyul";
	info[4] = "Choi Jiyoung";
}

void Employee::DeleteEmployee(string theEmployee) {
	int findNum = 10;
	for (int i = 0; i < 5; i++) {
		if (info[i] == theEmployee)
			findNum = i;
	}
	if (findNum == 10) {
		cout << "Eroor: There is no that name" << endl;
		return;
	}
	else if (findNum == num - 1) {
		info[findNum] = '\0';
		num--;
	}
	else {
		for (int i = findNum; i < num-1; i++) {
			info[i] = info[i + 1];
		}
		info[num-1] = '\0';
		num--;
	}
}

void Employee::showEmployee(){
	cout << "There are " <<num << " employees:" << endl;
	for (int i = 0; i < num; i++)
			cout << info[i] << endl;
}

int main() {
	Employee myemployee;
	string deleteE;
	myemployee.StoreEmployee();
			myemployee.showEmployee();
	do {
		cout << "Enter an employee name to remove: (if you want to stop, enter the \"stop\")";
		getline(cin, deleteE);
		myemployee.DeleteEmployee(deleteE);
		myemployee.showEmployee();
	} while (deleteE !="stop");
}