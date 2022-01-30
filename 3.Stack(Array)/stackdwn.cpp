//--------------------------------------------------------------------
// 2020112377 ��ǻ�Ͱ��а� ��μ�
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
	element = new DT[maxNumber](); //������
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
	delete[] element; //�Ҹ���
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newElement) //�ֱ�
{
	if (isFull() == true)
		cout << "Stack is full" << endl; //�� ä���������� ����
	else {
		element[top--] = newElement; 
	}
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop() //����
{
	if (isEmpty() == true)
	{
		cout << "Stack is empty" << endl; //����������� ����
	}
	else {
		return element[++top];
	}
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear() //����
{
	top = maxSize-1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const //�� ������ִ��� üũ
{
	return top == maxSize-1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const //�� ä�����ִ��� üũ
{
	return top == -1;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const //���� �����ֱ�
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