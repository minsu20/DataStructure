//--------------------------------------------------------------------
//
// 2020112377 ��ǻ�Ͱ������� ��μ�
//  Laboratory 10                                        heap.cpp
//
//  Actual implementation of class in the Heap ADT
//--------------------------------------------------------------------

#include "heap.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------------


template<class DT>
Heap<DT>::Heap(int maxNumber)
    :maxSize(maxNumber), size(0)
{
    dataItems = new DT[maxSize];
}

template < class DT >
Heap<DT>::~Heap()
{
    clear();
    delete[] dataItems;
}

//--------------------------------------------------------------------

template < class DT >
void Heap<DT>::insert(const DT& newDataItem)
{
    if (isFull()) {
        cout << "Heap is Full" << endl;
    }
    else {
        size++;
        int n = size - 1;
        dataItems[n] = newDataItem; //���� �������� �߰��Ѵ�
        while (n != 0 && dataItems[(n - 1) / 2].pty() < dataItems[n].pty()) { //n�� 0�� �ƴϰ�, �θ��庸�� �� ũ��
            swap(dataItems[n], dataItems[(n - 1) / 2]); //swap
            n = (n - 1) / 2; //�ؿ������� root���� �ö󰣴�
        }
    }
}

template < class DT >
DT Heap<DT>::removeMax()
{
    if (isEmpty()) { //�����������
        cout << "Heap is Empty" << endl;
        dataItems[0].setPty(-1); //priority�� -1
        return dataItems[0];
    }

    else if (size == 1) {
        size--;
        return(dataItems[0]);
    }

    else {
        DT data = dataItems[0];
        dataItems[0] = dataItems[size - 1];   // �ؿ� �ִ� �ָ� ���� �÷��� �� �ٽ� ���� 
        int i = 0;
        int max;
        size--;

        while (!(2 * i + 1 > size)) {   // �ڽĳ�尡 ������� ũ�� ���� �������̶�� ��
            if (2 * i + 1 == size) {
                max = 2 * i + 1;
            }
            else { // �ڽ� �ΰ�
                if (dataItems[2 * i + 1].pty() < dataItems[2 * i + 2].pty())
                    max = 2 * i + 2;
                else
                    max = 2 * i + 1;
            }
            if (dataItems[i].pty() < dataItems[max].pty()) {
                swap(dataItems[i], dataItems[max]);
                i = max;
            }
            else
                break;

        }
        return data;    // �����Ǵ� ������ 
    }

}

template < class DT >
void Heap<DT>::clear()
{
    size = 0;
}

//--------------------------------------------------------------------

template < class DT >
bool Heap<DT>::isEmpty() const
{
    return size == 0;
}

template < class DT >
bool Heap<DT>::isFull() const
{
    return size == maxSize;
}

//--------------------------------------------------------------------

template < class HD >
void Heap<HD>::showStructure() const

// Outputs the priorities of the data in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if (size == 0)
        cout << "Empty heap" << endl;
    else
    {
        cout << "size = " << size << endl;       // Output array form
        for (j = 0; j < maxSize; j++)
            cout << j << "\t";
        cout << endl;
        for (j = 0; j < size; j++)
            cout << dataItems[j].pty() << "\t";
        cout << endl << endl;
        showSubtree(0, 0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void Heap<DT>::showSubtree(int index, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in dataItems[index]. Argument
// level is the level of this dataItems within the tree.

{
    int j;   // Loop counter

    if (index < size)
    {
        showSubtree(2 * index + 2, level + 1);        // Output right subtree
        for (j = 0; j < level; j++)        // Tab over to level
            cout << "\t";
        cout << " " << dataItems[index].pty();   // Output dataItems's pty
        if (2 * index + 2 < size)                // Output "connector"
            cout << "<";
        else if (2 * index + 1 < size)
            cout << "\\";
        cout << endl;
        showSubtree(2 * index + 1, level + 1);        // Output left subtree
    }
}