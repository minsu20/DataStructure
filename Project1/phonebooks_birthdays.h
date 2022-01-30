//--------------------------------------------------------------------
//202011237 ��ǻ�Ͱ��а� ��μ�
//
//                                        phonebooks_birthdays.h
//
//--------------------------------------------------------------------
// 

#include <iostream>

using namespace std;

class ListNode {
private:
	//������
	ListNode(string &_name, string &_number, string &_birth, ListNode* nextPtr);

	//�������
	string name,
		number,
		birth, month, englishmonth; //englishmonths�� ���ڸ� ����� �ٲ� ��
	
	ListNode* next; //���� ����Ʈ ����Ŵ

	friend class List;
};

class List
{
public:

	// ������
	List(int ignored = 0);

	// �Ҹ���
	~List();

	// ���� �����
	void read();
	void write();

	//�߰�, ����, �˻�
	void search();
	void insert();
	void remove();

	//����Ʈ ����
	bool isEmpty();
	bool isFull();

	//�����ֱ�
	void showMonth() ; 
	void showStructure();


private:
	ListNode* head,
		* cursor;
};

