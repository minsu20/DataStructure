//--------------------------------------------------------------------
//
//  Laboratory 6                                           listdbl.cpp
// 2020112377 컴퓨터공학과 김민수
// Circular Doubly linked list implementation of the List ADT
// 
//--------------------------------------------------------------------

#include <iostream>
#include "listdbl.h"

using namespace std;

template < class DT >
ListNode<DT>::ListNode(const DT& data, ListNode* priorPtr, ListNode* nextPtr)
    :dataItem(data), prior(priorPtr), next(nextPtr)
{
    //ListNode 생성자
}

// Constructor
template < class DT >
List<DT>::List(int ignored)
    :head(NULL), cursor(NULL)
{

}

// Destructor
template < class DT >
List<DT>::~List()
{
    clear();
}


//------------ List manipulation operations ------------------

// Insert after cursor
template < class DT >
void List<DT>::insert(const DT& newDataItem)
{
    if (isFull()) {
        cout << "List is FULL" << endl;
        return;
    }
    else if (head == NULL) {
        ListNode <DT>* newNode = new ListNode <DT>(newDataItem, NULL, NULL);
        head = newNode;
        cursor = newNode;
        newNode->next = newNode;
        newNode->prior = newNode;
        return;
    }//empty인 경우

    else if (cursor->next == head) {
        ListNode <DT>* newNode = new ListNode <DT>(newDataItem, cursor, head);
        cursor->next = newNode;
        head->prior = newNode;
        cursor = newNode;
        return;
    }//커서가 맨 뒤에

    ListNode <DT>* newNode = new ListNode <DT>(newDataItem, cursor, cursor->next);
    cursor->next->prior = newNode;
    cursor->next = newNode;
    cursor = newNode;

}

// Remove data item
template < class DT >
void List<DT>::remove()
{
    if (isEmpty()) {
        cout << "List is EMPTY" << endl;
        return;
    } //empty인경우

    else if (cursor == head && cursor->next == head) {
        ListNode<DT>* temPtr = cursor;
        cursor = NULL;
        head = NULL;
        delete  temPtr;
        return;
    }//원소 1개

    else if (cursor->next == head) {
        ListNode<DT>* temPtr = cursor;
        cursor->prior->next = head;
        head->prior = cursor->prior;
        cursor->next = NULL;
        cursor->prior = NULL;
        cursor = head;
        delete temPtr;
        return;
    }//커서가 맨 뒤

    else if (cursor == head) {
        ListNode<DT>* temPtr = cursor;
        cursor->next->prior = cursor->prior;
        cursor->prior->next = cursor->next;
        cursor = cursor->next;
        head->next = NULL;
        head->prior = NULL;
        head = cursor;
        delete temPtr;
        return;
    } //커서가 맨 앞에

    else {
        cursor->prior->next = cursor->next;
        cursor->next->prior = cursor->prior;
        ListNode<DT>* temPtr = cursor;
        cursor = cursor->next;
        delete temPtr;
    }//커서가 중간에
}

// Replace data item
template < class DT >
void List<DT>::replace(const DT& newElement)
{
    if (isEmpty()) {
        cout << "List is EMPTY" << endl;
        return;
    }
    cursor->dataItem = newElement;
}

// Clear list
template < class DT >
void List<DT>::clear()
{
    if (isEmpty())
        return;
    else {
        ListNode<DT>* temPtr;
        gotoEnd();
        while (cursor != head) {
            temPtr = cursor;
            cursor = cursor->prior;
            delete temPtr;
        }
        head = NULL;
    }
}


//------------ List status operations ------------------

// List is empty
template < class DT >
bool List<DT>::isEmpty() const
{
    return head == NULL;
}

// List is full
template < class DT >
bool List<DT>::isFull() const
{
    ListNode <DT>* newNode = new ListNode <DT>(NULL, NULL, NULL);
    if (newNode == NULL)
        return true;
    else {
        delete newNode;
        return false;
    }
}


//------------ List manipulation operations ------------------

// Go to beginning
template < class DT >
void List<DT>::gotoBeginning()
{
    if (isEmpty()) {
        cout << "List is EMPTY" << endl;
        return;
    }
    while (cursor != head) {
        cursor = cursor->prior;
    }
}

// Go to end
template < class DT >
void List<DT>::gotoEnd()
{
    if (isEmpty()) {
        cout << "List is EMPTY" << endl;
        return;
    }
    while (cursor->next != head) {
        cursor = cursor->next;
    }
}

// Go to next data item
template < class DT >
bool List<DT>::gotoNext()
{
    if (isEmpty() || cursor->next == head) {
        return false;
    }
    else {
        cursor = cursor->next;
        return true;
    }
}

// Go to prior data item
template < class DT >
bool List<DT>::gotoPrior()
{
    if (isEmpty() || cursor == head) {
        return false;
    }
    else {
        cursor = cursor->prior;
        return true;
    }
}


template < class DT >
DT List<DT>::getCursor() const
{
    if (isEmpty()) {
        cout << "List is EMPTY" << endl;
        return NULL;
    }
    return cursor->dataItem;
}


//-----------------------------------------------------------

template<class DT>
void List<DT>::showStructure() const
{
    ListNode<DT>* p;   // Iterates through the list

    if (head == NULL)
        cout << "Empty list" << endl;
    else
    {
        p = head;
        do
        {
            if (p == cursor)
                cout << "[" << p->dataItem << "] ";
            else
                cout << p->dataItem << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
}


//-----------------------------------------------------------

// In-lab opertions
template < class DT >
void List<DT>::reverse()
{

    if (isEmpty()) {
        cout << "List is EMPTY"<<endl;
        return;
    }
    else {
        int size = 1, csize = 1;

        ListNode <DT>* temPtr = head;
        while (temPtr != cursor) {
            temPtr = temPtr->next;
            csize++;
        }//커서 위치

        cursor = head;
        while (cursor->next != head) {
            cursor = cursor->next;
            size++;
        } //리스트 크기

        char* item = new char[size];
        gotoEnd();
        for (int i = 0; i < size; i++) {
            item[i] = cursor->dataItem;
            cursor = cursor->prior;
        }
        clear();
        for (int i = 0; i < size; i++)
            insert(item[i]); //리스트 데이터 reverse

        cursor = head;
        for (int i = 0; i < size - csize; i++) {
            cursor = cursor->next;//커서 reverse
        }
    }
}