//컴퓨터공학과 2020112377 김민수

#include <iostream>
#include <cstring>
#include <string>
#include<fstream>

using namespace std;

class Employee {
public:
	void StoreEmployee();
	void DeleteEmployee(string theEmployee);
	void showEmployee();
	int num;
	int findNum;
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
		for (int i = findNum; i < num - 1; i++) {
			info[i] = info[i + 1];
		}
		info[num - 1] = '\0';
		num--;
	}
}

void Employee::showEmployee() {
	cout << "There are " << num << " employees:" << endl;
	for (int i = 0; i < num; i++)
		cout << info[i] << endl;

}

int main() {
	Employee myemployee;
	string deleteE;
	myemployee.StoreEmployee();
	ifstream readFile;    
	string str;
	readFile.open("text.txt");//읽기모드로 파일 열기
	if (readFile.is_open()) {
		getline(readFile, str);
		myemployee.DeleteEmployee(str);
		cout << "remove " << str<<endl;
		myemployee.showEmployee();
	}
	readFile.close();    //파일  닫기

	ofstream writeFile("text.txt"); //쓰기모드로 파일열기
	if (writeFile.is_open()) {
		for (int i = 0; i < myemployee.num; i++)
		{
			writeFile.write(myemployee.info[i].c_str(), myemployee.info[i].size()); //삭제 후 결과물 쓰기
			writeFile << endl;
		}
		writeFile.close(); //파일닫기
	}
	return 0;
}

