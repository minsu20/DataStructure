//--------------------------------------------------------------------
//
//  Laboratory 7                                          stacklnk.cpp
// 2020112377 ��ǻ�Ͱ��а� ��μ�
//  linked list implementation of the
//  Stack ADT
// StackWriteMirror()�� ���� �Լ��� ����
//
//--------------------------------------------------------------------
#include "stacklnk.h"
#include <iostream>

using namespace std;

template<class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
    :dataItem(nodeData), next(nextPtr)
{
    //StackNode ������
}


template<class DT>
Stack<DT>::Stack(int ignored) :top(nullptr)
{
    //Stack ������
}

//------------------------------------------------

template<class DT>
Stack<DT>::~Stack()
{
    clear(); //Stack �Ҹ���
}

//------------------------------------------------


template<class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull()) {
        cout << "Stack is Full. Element cannot be inserted." << endl;
        return; //�� ä���� ���
    }
    else {
        StackNode<DT>* location = new StackNode<DT>(newDataItem, top);
        top = location;
    }
}

//------------------------------------------------


template<class DT>
DT Stack<DT>::pop()
{
    if (isEmpty()) {
        cout << "Stack is Empty.Element cannot be removed." << endl;
        return 0; //����� �ִ� ���
    }
    else {
        StackNode<DT>* tempPtr = top;
        DT returnStack = tempPtr->dataItem;
        top = tempPtr->next;
        delete tempPtr;
        return returnStack;
    }
}


//------------------------------------------------

template<class DT>
void Stack<DT>::clear()
{
    while (top != nullptr) {
        pop();
    }
}

//------------------------------------------------


template<class DT>
bool Stack<DT>::isEmpty() const
{
    return top == nullptr;
}

//------------------------------------------------


template<class DT>
bool Stack<DT>::isFull() const
{
    StackNode<DT>* tempPtr= new StackNode<DT>(NULL, nullptr);
    if (tempPtr == nullptr)
        return true; //�� ��尡 ������ �ȵǸ� true
    else {
        delete tempPtr;
        return false;
    }
}

//------------------------------------------------

