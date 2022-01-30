//--------------------------------------------------------------------
// 2020112377 ÄÄÇ»ÅÍ°øÇÐÀü°ø ±è¹Î¼ö
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template<class DT>
void swap(DT& a, DT& b)
{
    DT temp = a;
    a = b;
    b = temp;
}

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
    DT min;
    int idx = 0;
    for (int i = 0; i < numKeys - 1; i++) {
        min = keyList[i];
        for (int j = i; j <numKeys-1; j++) {
            if (keyList[j] < min) {
                min = keyList[j];
                idx = j;
            }
        }
        swap(keyList[i], keyList[idx]);
    }

}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    if (left < right) {
        int i = left + 1, j = right;

        int pivot = left;

        do
        {
            while ((keyList[i] < keyList[pivot]) && (i < right))
                i++;

            while ((keyList[pivot] < keyList[j]) && (j > left))
                j--;

            if (i <= j)

            {
                swap(keyList[i], keyList[j]);
                i++;
                j--;
            }

        } while (i <= j);
        swap(keyList[left], keyList[j]);
        quickPartition(keyList, numKeys, left, j - 1);
        quickPartition(keyList, numKeys, j + 1, right);
    }
}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)

{
    for (int i = 0; i < numKeys - 1; i++) {
        for (int j = 0; j < numKeys-i-1; j++) {
            if (keyList[j] > keyList[j + 1]) {
                DT temp = keyList[j];
                keyList[j] = keyList[j +1];
                keyList[j + 1] = temp;
            }
        }
    }
}
