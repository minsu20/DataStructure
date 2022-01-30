//--------------------------------------------------------------------
//202011237 ��ǻ�Ͱ��а� ��μ�
//
//                                        phonebooks_birthdays.cpp
//
//--------------------------------------------------------------------
// 



#include "phonebooks_birthdays.h"
#include <iostream>
#include <fstream>
#include <string>

ifstream readFile;

ofstream writeFile;

ListNode::ListNode(string &_name, string &_number, string &_birth, ListNode* nextPtr)
:name(_name), number(_number), birth(_birth), next(nullptr)
{
	//ListNode ������
}

List::List(int ignored)
	:head(nullptr), cursor(nullptr)
{
	//list ������
}

List::~List() {
	ListNode* tempPtr;

	cursor = head;
	while (cursor!= nullptr) {
		tempPtr = cursor;
		cursor = tempPtr->next;
		delete tempPtr;
	}
	cursor = nullptr;
	head = nullptr;
	//list �Ҹ���
}

void List::read() {
	cout << "       Enter the name of the file: ";
	string _filename;
	cin.ignore();
	getline(cin, _filename);
	string str = _filename + ".txt";
	readFile.open(str);//���� ����
	if (readFile.is_open()) {
		while (!readFile.eof()) {
			if (isEmpty()) {
				//ù��° ��
				string name, num, birth;
				getline(readFile, name);
				getline(readFile, num);
				getline(readFile, birth);
				ListNode* location = new ListNode(name, num, birth, nullptr);
				head = location;
				cursor = location;
				location->month = location->birth.substr(0, 2);
			}
			else {
				//�ι�°, ����° ��
				string name, num, birth;
				getline(readFile, name);
				if (name == "")
				getline(readFile, name);//�̸����� �ٹٲ��� �ִ� ���
				getline(readFile, num);
				getline(readFile, birth);
				ListNode* location = new ListNode(name, num, birth, nullptr);
				cursor->next = location;
				cursor = location;
				location->month = location->birth.substr(0, 2);
			}
		}
	}
	else {
		cout << "       File cannot be readed"<<endl;
		return;
	}
	readFile.close();
}

void List::write() {
	//���ݱ��� ������ list �� ���Ϸ� �ٽ� ����
	cout << "       Enther the name of the file:";
	string newfilename;
	cin.ignore();
	getline(cin, newfilename);
	string str = newfilename + ".txt";

	writeFile.open(str);//���� ����
	if (writeFile.is_open()) {
		cursor = head;
		while (cursor != nullptr) {
			writeFile << cursor->name << endl;
			writeFile << cursor->number << endl;
			writeFile << cursor->birth << endl<<endl;//�̸�, ��ȣ, ���� ����
			cursor = cursor->next;
		}
	}
	else {
		cout << "       File cannot be written";
	}
	writeFile.close();//���� �ݱ�
}

void List::search() {
	cout << "       Enter the selected month:";
	string e_month;
	int count=0;
	cin >> e_month;
	cursor = head;
	while (cursor != nullptr) {
		if ((cursor->englishmonth) == e_month)
			count++;
		cursor = cursor->next; //�Է��� �ް� ���� ���� ������ �ִ� ���� ��������
	}
	cout << "       Total number of birthdays in  " << e_month << ":"<< count<<endl;
	cursor = head;
	while (cursor != nullptr) {
		if ((cursor->englishmonth) == e_month) {
			cout << "       "<<cursor->name<<endl;
			cout << "       "<<cursor->number << endl;
			cout << "       "<<cursor->birth << endl<<endl;
		}
		cursor = cursor->next;
	}
}

void List::insert() {
	if (isFull()) {
		cout << "       List is ful<<endll";
		return;
	}
	else {
		cout << "       Add an entry" << endl;
		cout << "       Name:";
		string newname, newnumber, newbirthday;
		cin.ignore();
		getline(cin, newname);
		cout << "       Phone:";
		getline(cin, newnumber);
		cout <<"       Birthday:";
		getline(cin, newbirthday);
		if (isEmpty()) { //������ִ� ���
		ListNode* location = new ListNode(newname, newnumber, newbirthday, nullptr);
		head = location;
		cursor = location;
		location->month = location->birth.substr(0, 2);
		return; 
	}
	else {
	cursor = head;

	while (cursor->next!= nullptr)
		cursor = cursor->next;//Ŀ�� �� �ڷ� �ű��

	ListNode* location = new ListNode(newname, newnumber, newbirthday, nullptr);
	cursor->next = location;
	cursor = location;
	location->month = location->birth.substr(0, 2);
	}
	}
}

void List::remove() {
	if(isEmpty()) {
		cout << "List is empty" << endl;
		return;//������ִ°��
	}
	else {
		cout << "       Remove an entry :";
		string entry;
		cout << "\n       Name: ";
		cin.ignore();
		getline(cin, entry);

		cursor = head;

		while (cursor->name != entry) {
			cursor = cursor->next;
			if (cursor == nullptr) {
				cout << "       cannot found" << endl;
				return;
			}
		}
		if (cursor == head) {//Ŀ���� ��忡 �ִ� ���
			ListNode* tempPtr = head;
			head = head->next;
			cursor = cursor->next;
			delete tempPtr;
			return;
		}
		else {
			ListNode* tempPtr2 = cursor; //������ �ϴ� entry�� Ŀ���� ����Ŵ
			ListNode* tempPtr = head;
			while (tempPtr->next != cursor) { //tempPtr������ cursor�� ����ų ������ tempPtr�� �ڷ� �ű� 
				tempPtr = tempPtr->next;
			}
			cursor = tempPtr; //Ŀ�� ��ĭ ������
				cursor->next = tempPtr2->next;
				delete tempPtr2;
		}
	}
}

bool List::isEmpty() {
	return head == nullptr;
}

bool List::isFull() {
	string str1 = "";
	string str2 = "";
	string str3 = "";
	ListNode* tempPtr = new ListNode(str1, str2, str3, nullptr);
	if (tempPtr == nullptr)
		return true; //�� ��尡 ������ �ȵǸ� true
	else {
		delete tempPtr;
		return false;
	}
}

void List::showStructure() {
	cursor = head;
	while (cursor != nullptr) {
		cout <<"       "<< cursor->name << endl;
		cout << "       "<<cursor->number << endl;
		cout <<"       "<< cursor->birth << endl;
		cursor = cursor->next;
	}
}

void List::showMonth() {
	string t_month[12] =  { "January" , "February" , "March" , "April" , "May" , "June" ,"July", "August", "September", "October", "November", "December"};
	int monthlist[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	int listsize=0;
	cursor = head;
	//���ڷ� �� ���� ����� �ٽ� ����
	while (cursor != nullptr) {
		if (cursor->month == "01") {
			cursor->englishmonth = t_month[0];
			monthlist[0]++;
			listsize++;
		}
		else if (cursor->month == "02") {
			cursor->englishmonth = t_month[1];
			monthlist[1]++;
			listsize++;
		}
		else if (cursor->month == "03") {
			cursor->englishmonth = t_month[2];
			monthlist[2]++;
			listsize++;
		}
		else if (cursor->month == "04") {
			cursor->englishmonth = t_month[3];
			monthlist[3]++;
			listsize++;
		}
		else if (cursor->month == "06") {
			cursor->englishmonth = t_month[4];
			monthlist[4]++;
			listsize++;
		}
		else if (cursor->month == "06") {
			cursor->englishmonth = t_month[5];
			monthlist[5]++;
			listsize++;
		}
		else if (cursor->month == "07") {
			cursor->englishmonth = t_month[6];
			monthlist[6]++;
			listsize++;
		}
		else if (cursor->month == "08") {
			cursor->englishmonth = t_month[7];
			monthlist[7]++;
			listsize++;
		}
		else if (cursor->month == "09") {
			cursor->englishmonth = t_month[8];
			monthlist[8]++;
			listsize++;
		}
		else if (cursor->month == "10") {
			cursor->englishmonth = t_month[9];
			monthlist[9]++;
			listsize++;
		}
		else if (cursor->month == "11") {
			cursor->englishmonth = t_month[10];
			monthlist[10]++;
			listsize++;
		}
		else if (cursor->month == "12") {
			cursor->englishmonth = t_month[10];
			monthlist[10]++;
			listsize++;
		}

		cursor = cursor->next;
	}

	if (isEmpty()) {
		cout << "       List is empty"<<endl;
	}
	else {
		cout << "       Total number of entries in the list:" << listsize << endl;
		cout << "       Number of birthdays in" << endl;
		for (int i = 0; i < 12; i++) {
			if (monthlist[i] != 0) {
				cout << "                   " << t_month[i] << ":" << monthlist[i] << endl;
			}
		}
	}
}