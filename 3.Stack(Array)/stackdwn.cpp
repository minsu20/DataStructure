//--------------------------------------------------------------------
// 2020112377 컴퓨터공학과 김민수
//  Laboratory 5                                        stackdwn.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber) :maxSize(maxNumber), top(maxNumber-1)
{
	element = new DT[maxNumber](); //생성자
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
	delete[] element; //소멸자
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newElement) //넣기
{
	if (isFull() == true)
		cout << "Stack is full" << endl; //다 채워져있으면 에러
	else {
		element[top--] = newElement; 
	}
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop() //빼기
{
	if (isEmpty() == true)
	{
		cout << "Stack is empty" << endl; //비워져있으면 에러
	}
	else {
		return element[++top];
	}
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear() //비우기
{
	top = maxSize-1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const //다 비워져있는지 체크
{
	return top == maxSize-1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const //다 채워져있는지 체크
{
	return top == -1;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const //구조 보여주기
{
	if (isEmpty())
		cout << "Empty Stack" << endl;
	else
	{
		for (int i = 0; i<top; i++)
		{
			cout << "| Empty |";
		}
		for (int i=top; i<maxSize; i++)
		{
			cout << "| "<<element[i]<<" |";
		}
		cout << endl;
	}
}