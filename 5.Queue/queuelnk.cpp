//--------------------------------------------------------------------
// 2020112377 ÄÄÇ»ÅÍ°øÇÐ°ú ±è¹Î¼ö
//  Laboratory 6                                          queueLnk.cpp
//
//  Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------
#include "queueLnk.h"
#include <iostream>

using namespace std;

template <class DT>
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr)
    :dataItem(nodeData), next(nextPtr)
{
}

template <class DT>
Queue<DT>::Queue(int ignored)
    : front(nullptr), rear(nullptr)
{
}


template<class DT>
Queue<DT>::~Queue()
{
    clear();
}

template<class DT>
void Queue<DT>::enqueue(const DT& newData)
{
    if (isFull())
        cout << "Full Queue" << endl;
    else{
        QueueNode<DT>* newNode = new QueueNode<DT>(newData, nullptr);
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}

template<class DT>
DT Queue<DT>::dequeue()
{
    if (isEmpty())
        cout << "Empty Queue" << endl;
    else {
        QueueNode<DT>* tempPtr = front;
        DT item = front->dataItem;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        return item;
    }
}

template <class DT>
void Queue<DT>::clear()
{
    QueueNode<DT>* tempPtr;
    while (front != nullptr) {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = nullptr;
}

template<class DT>
bool Queue<DT>::isEmpty() const
{
    return front == nullptr;
}

template<class DT>
bool Queue<DT>::isFull() const
{
    QueueNode<DT>* tempPtr = new QueueNode<DT>(NULL,nullptr);
    if (tempPtr == nullptr)
        return true;
    else {
        delete tempPtr;
        return false;
    }
}

template<class DT>
void Queue<DT>::showStructure() const
{
    QueueNode<DT>* p;   // Iterates through the queue

    if (front == nullptr)
        cout << "Empty queue" << endl;
    else
    {
        cout << "front ";
        for (p = front; p != nullptr; p = p->next)
            cout << p->dataItem << " ";
        cout << "rear" << endl;
    }
}


// In-lab operations
template<class DT>
void Queue<DT>::putFront(const DT& newDataItem)
{
    if (isFull())
        cout << "Full Queue" << endl;
    else{
        QueueNode<DT>* newNode = new QueueNode<DT>(newDataItem, front);
        if (rear == NULL)
            rear = newNode;
        else
            front = front->next;
        front = newNode;
    }
}

template <class DT>
DT Queue<DT>::getRear()
{
    if (isEmpty()){
        cout << "Empty Queue" << endl;
        return NULL;
    }
    QueueNode<DT>* tempPtr = front;
    while (tempPtr->next != rear)
        tempPtr = tempPtr->next;
    QueueNode<DT>* rearPtr = rear;
    rear = tempPtr;
    rear->next = nullptr;
    return rearPtr->dataItem;
}

template <typename DT>
int Queue<DT>::getLength() const
{
    if (isEmpty()) {
        return 0;
    }
    int count = 1;
    QueueNode<DT>* tempPtr = front;
    while (tempPtr != rear)
    {
        tempPtr = tempPtr->next;
        count++;
    }
    return count;
}