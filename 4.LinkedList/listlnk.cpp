//--------------------------------------------------------------------
// 2020112377 김민수 컴퓨터공학과
//  Laboratory 4                                           listlnk.cpp
//
//  SOLUTION: Implementation of the List ADT using a singly linked list
// Pre-lab+In-lab2+In-lab3
//--------------------------------------------------------------------

#include "listlnk.h"
#include <iostream>

using namespace std;

template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr)
    :dataItem(nodeData), next(nextPtr)
{
    //ListNode 생성자
}


template<class DT>
List<DT>::List(int ignored):head(nullptr),cursor(nullptr)
{
    //List 생성자
}

//------------------------------------------------

template<class DT>
List<DT>::~List()
{
    clear(); //List 소멸자
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT& newData)
{
    if (isFull()) {
        cout << "List is Full. Element cannot be inserted." << endl;
        return; //다 채워진 경우
    }
    else if (isEmpty()) {
           ListNode<DT>* location= new ListNode<DT>(newData, nullptr);
           head = location;
           cursor = location;
            return; //비워져 있는 경우 
        }
    else{
        ListNode<DT>* location= new ListNode<DT>(newData, cursor->next);
        cursor->next = location;
        cursor = location;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()
{
    if (isEmpty()) {
        cout << "List is Empty.Element cannot be removed." << endl;
        return; //비워져 있는 경우
    }
    else {
        if (head == cursor) {
            ListNode<DT>* tempPtr = head;
            head = head->next;
            cursor = cursor->next;
            delete tempPtr;
            return; //커서가 헤드에 있는 경우
            }
        ListNode<DT>* tempPtr = cursor;
        if(gotoPrior()){
            cursor->next = tempPtr->next;
            delete tempPtr;
            cursor = cursor->next;
            if (cursor == nullptr) {
                cursor = head; //커서가 끝에 있는 경우 헤드로
            }
        }
       
    }
}


//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT& newData)
{
    if (isEmpty()) {
        cout << "List is Empty. Element cannot be replaced." << endl;
        return; //비워져있는 경우
    }
    cursor->dataItem = newData;
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
    ListNode<DT>* tempPtr;
    cursor = head;
    while (cursor != nullptr) {
        tempPtr = cursor;
        cursor = tempPtr->next;
        delete tempPtr;
    }
    cursor = nullptr;
    head = nullptr;
 }

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
    return cursor == nullptr;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
    ListNode<DT>* tempPtr;
    tempPtr=new ListNode<DT>(NULL, nullptr);
    if (tempPtr == nullptr)
        return true; //새 노드가 생성이 안되면 true
    else {
        delete tempPtr;
        return false;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoBeginning()
{
    if (isEmpty() || cursor == head) {
        cout << "Either at the beginning of the list or the list is empty" << endl;
        return;
    }
    cursor = head;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoEnd()
{
    if (isEmpty()||cursor->next==nullptr) {
        cout << "Either at the end of the list or the list is empty" << endl;
        return;
    }
    while (cursor->next != nullptr) //커서 다음이 nullptr를 가리킬때까지 커서를 뒤로 옮김
        cursor = cursor->next;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoNext()
{
    if (isEmpty() || cursor->next == nullptr)
        return false;
    cursor = cursor->next;
    return true;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
    if (isEmpty()||cursor==head) {
        return false;
    }
    ListNode<DT>* tempPtr = head;
    while (tempPtr->next != cursor) //tempPtr다음이 cursor를 가리킬 때까지 tempPtr를 뒤로 옮김 
        tempPtr = tempPtr->next;
    cursor = tempPtr;
    return true;
}

//------------------------------------------------


template<class DT>
DT List<DT>::getCursor() const
{
    if (isEmpty()) {
        cout << "Failed--List is Empty" << endl;
        return NULL;
    }
    return cursor->dataItem;
}

template<class DT>
void List<DT>::showStructure() const
{
    if (head == nullptr)
        cout << "Empty list" << endl;
    else
    {
        for (ListNode<DT>* p = head; p != nullptr; p = p->next)
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
        cout << endl;
    }
}

//------------------------------------------------

//in-lab
template<class DT>
void List<DT>::moveToBeginning()
{
    if (isEmpty() || cursor == head) {
        cout << "Either at the beginning of the list or the list is empty" << endl;
        return; //비워져있거나 이미 커서가 헤드에 있는 경우
    }
    DT beginData = cursor->dataItem;
    remove();
    ListNode<DT>* tempPtr = new ListNode<DT>(beginData, head);
    head = tempPtr;
    cursor = head;// in-lab 2
}

template<class DT>
void List<DT>::insertBefore(const DT& newElement)
{
    if (isFull()) {
        cout << "Faied--List is Full" << endl;
        return; //다 채워져 있는 경우
    }
    else {
        if (isEmpty()) {
            ListNode<DT>* location = new ListNode<DT>(newElement, nullptr);
            head = location;
            cursor = location;
            return; //비워져 있는 경우 
        }
        ListNode<DT>* tempPtr = new ListNode<DT>(cursor->dataItem,cursor->next);
        cursor->next=tempPtr;
        cursor->dataItem = newElement;
        return; 
    }// in-lab 3

}