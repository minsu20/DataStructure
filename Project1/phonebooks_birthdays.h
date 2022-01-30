//--------------------------------------------------------------------
//202011237 컴퓨터공학과 김민수
//
//                                        phonebooks_birthdays.h
//
//--------------------------------------------------------------------
// 

#include <iostream>

using namespace std;

class ListNode {
private:
	//생성자
	ListNode(string &_name, string &_number, string &_birth, ListNode* nextPtr);

	//멤버변수
	string name,
		number,
		birth, month, englishmonth; //englishmonths는 숫자를 영어로 바꾼 것
	
	ListNode* next; //다음 리스트 가리킴

	friend class List;
};

class List
{
public:

	// 생성자
	List(int ignored = 0);

	// 소멸자
	~List();

	// 파일 입출력
	void read();
	void write();

	//추가, 제거, 검색
	void search();
	void insert();
	void remove();

	//리스트 상태
	bool isEmpty();
	bool isFull();

	//보여주기
	void showMonth() ; 
	void showStructure();


private:
	ListNode* head,
		* cursor;
};

