//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 1                      search.cpp
//
//  Implementation of a set of searching routines
//
//--------------------------------------------------------------------

template < class DT >
int linearSearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Linear search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns -1 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
   
    int result;
    index = 0;
    while (index < numKeys && searchKey > keyList[index])
        index++;

    if (index < numKeys && searchKey == keyList[index])
        result = 1;
    else
    {
        index--;
        result = -1;
    }

    return result;
}

//--------------------------------------------------------------------

template < class DT >
int binarySearch(DT keyList[], int numKeys,
    DT searchKey, int& index)

    // Binary search routine. Searches the first numKeys keys in keyList
    // for searchKey. If searchKey is found, then returns 1 with index
    // returning the array index of the entry containing searchKey.
    // Otherwise, returns -1 with index returning the array index of the
    // entry containing the largest key that is smaller than searchKey
    // (or -1 if there is no such key).

{
   
    int start = 0;
    int end = numKeys - 1;
    int result;

    while (start <= end)
    {
        index = (start + end) / 2;

        if (searchKey < keyList[index])
            end = index - 1;
        else if (searchKey > keyList[index])
            start = index + 1;
        else
            break;
    }

    if (start <= end)
        result = 1;
    else
    {
        index = end;
        result = -1;
    }

    return result;
}