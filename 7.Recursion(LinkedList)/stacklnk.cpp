//--------------------------------------------------------------------
//
//  Laboratory 7                                          stacklnk.cpp
// 2020112377 컴퓨터공학과 김민수
//  linked list implementation of the
//  Stack ADT
// StackWriteMirror()에 쓰일 함수만 구현
//
//--------------------------------------------------------------------
#include "stacklnk.h"
#include <iostream>

using namespace std;

template<class DT>
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr)
    :dataItem(nodeData), next(nextPtr)
{
    //StackNode 생성자
}


template<class DT>
Stack<DT>::Stack(int ignored) :top(nullptr)
{
    //Stack 생성자
}

//------------------------------------------------

template<class DT>
Stack<DT>::~Stack()
{
    clear(); //Stack 소멸자
}

//------------------------------------------------


template<class DT>
void Stack<DT>::push(const DT& newDataItem)
{
    if (isFull()) {
        cout << "Stack is Full. Element cannot be inserted." << endl;
        return; //다 채워진 경우
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
        return 0; //비워져 있는 경우
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
        return true; //새 노드가 생성이 안되면 true
    else {
        delete tempPtr;
        return false;
    }
}

//------------------------------------------------

