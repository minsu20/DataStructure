//--------------------------------------------------------------------
//
// 2020112377 컴퓨터공학전공 김민수
//  Laboratory B, In-lab Exercise 2                     heapsort.cpp
//
//   heapSort() function
//
//--------------------------------------------------------------------
using namespace std;

template < class DT >
void moveDown(DT dataItem[], int root, int size)

// Restores the binary tree that is rooted at root to a heap by moving
// dataItem[root] downward until the tree satisfies the heap property.
// Parameter size is the number of data items in the array.

{
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int max;
    if (left >= size){ //left노드가 사이즈보다 크면 내가 마지막이라는 것
        return;
    }
    else if (right >= size) { //right노드가 사이즈보다 크면
        max = left; //left노드 인덱스를 max로
    }
    else { //pty()값이 더 큰 노드 인덱스를 max로
        if (dataItem[left].pty() > dataItem[right].pty())
            max = left;
        else
            max = right;
    }

    if (dataItem[max].pty() > dataItem[root].pty()) { //max인덱스 pty()값이 root인덱스 pty()값보다 더 크면
        DT tmp;
        swap(dataItem[root], dataItem[max]); //swap();
        moveDown(dataItem, max, size); 
    }
}

//--------------------------------------------------------------------

template < class DT >
void heapSort(DT dataItems[], int size)

// Heap sort routine. Sorts the data items in the array in ascending
// order based on priority.

{
    DT temp;   // Temporary storage
    int j;     // Loop counter

    // Build successively larger heaps within the array until the
    // entire array is a heap.

    for (j = (size - 1) / 2; j >= 0; j--)
        moveDown(dataItems, j, size);

    // Swap the root data item from each successively smaller heap with
    // the last unsorted data item in the array. Restore the heap after
    // each exchange.

    for (j = size - 1; j > 0; j--)
    {
        temp = dataItems[j];
        dataItems[j] = dataItems[0];
        dataItems[0] = temp;
        moveDown(dataItems, 0, j);
    }
}