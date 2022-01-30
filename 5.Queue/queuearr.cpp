//--------------------------------------------------------------------
// 2020112377 ÄÄÇ»ÅÍ°øÇÐ°ú ±è¹Î¼ö
//  Laboratory 6                                          queueArr.cpp
//
//  Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include "queuearr.h"
#include <iostream>

using namespace std;

template < class DT >
Queue<DT>::Queue(int maxNumber) :maxSize(maxNumber),front(-1),rear(-1)
{
	element = new DT[maxSize];
}

template < class DT >
Queue<DT>::~Queue()
{
	delete[] element;
}

template < class DT >
void Queue<DT>::enqueue(const DT& newData)
{
	if (isFull())
		cout << "Full Queue" << endl;
	else {
		if (front == -1)
			front = 0;
		rear = (rear + 1) % maxSize;
		element[rear] = newData;
	}
}

template < class DT >
DT Queue<DT>::dequeue()
{
	if (isEmpty()) {
		cout << "Empty Queue" << endl;
		return NULL;
	}
	else {
		DT array = element[front];
		if (getLength() == 1) {
			element[front] = NULL;
			front = -1;
		}
		else {
			element[front] = NULL;
			front = (front + 1) % maxSize;
		}
		return array;
	}
}

template < class DT >
void Queue<DT>::clear()
{
	for (int i = 0; i < maxSize; i++)
	{
		element[i] = NULL;
	}
	rear = - 1;
	front = -1;
}

template < class DT >
bool Queue<DT>::isEmpty() const
{
	return front == -1;
}

template < class DT >
bool Queue<DT>::isFull() const
{
	return (rear + 1) % maxSize == front;
}

template < class DT >
void Queue<DT>::showStructure() const
{
	int j;   // Loop counter

	if (front == -1)
		cout << "Empty queue" << endl;
	else
	{
		cout << "front = " << front << "  rear = " << rear << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		if (rear >= front)
			for (j = 0; j < maxSize; j++)
				if ((j >= front) && (j <= rear))
					cout << element[j] << "\t";
				else
					cout << " \t";
		else
			for (j = 0; j < maxSize; j++)
				if ((j >= front) || (j <= rear))
					cout << element[j] << "\t";
				else
					cout << " \t";
		cout << endl;
	}

}

// In-lab operations

template < class DT >
void Queue<DT>::putFront(const DT& newDataItem)
{
	if (isFull())
		cout << "Full Queue" << endl;
	else {
		if (front == -1) {
			front = 0;	
			rear = 0;
		}
		else
			front = (front + maxSize-1) % maxSize;
		element[front] = newDataItem;
	}
}

template < class DT >
DT Queue<DT>::getRear()
{
	if (isEmpty()) {
		cout << "Empty Queue" << endl;
		return NULL;
	}
	else {
		DT array= element[rear];
		if (getLength() == 1) {
			element[rear] = NULL;
			rear = -1;
			front = -1;
		}
		else {
			element[rear] = NULL;
			rear = (rear - 1 + maxSize) % maxSize;
		}
		return array;
	}
}

template < class DT >
int Queue<DT>::getLength() const
{
	int count = 0;
	int i;
	if (rear < front)
	{
		for (i = front; i <= rear + maxSize; i++)
			count++;
		return count;
	}
	else {
		return rear - front+1;
	}
}