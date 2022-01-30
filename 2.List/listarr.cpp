//컴퓨터공학과 2020112377 김민수

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)
	: maxSize(maxNumber), size(0), cursor(-1) //멤버 변수 초기화

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

{
	// pre-lab
	dataItems = new DataType[maxNumber](); //널 값으로 초기화
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull() == true)
		cout << "Element cannot be inserted." << endl;
	else if (cursor == size - 1) {
		dataItems[++cursor] = newDataItem;
		size++;
	}
	else {
		for (int i = size; i > cursor; i--) {
			dataItems[i] = dataItems[i - 1];
		}
		dataItems[++cursor] = newDataItem;
		size++;
	}
}

//--------------------------------------------------------------------

void List::remove()

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab

	if (isEmpty() == true) {
		cout << "Element cannot be deleted" << endl;
	}
	else if (size == 1) {
		dataItems[cursor--] = NULL;
		size--;
	}

	else if (cursor == size - 1) {
		dataItems[cursor] = NULL;
		size--;
		cursor = 0;
	}
	else{
		for (int i = cursor; i < size-1; i++) {
			dataItems[i] = dataItems[i + 1];
		}
		size--;
	}
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty()) {
		cout << "Empty List" << endl;
		return;
	}
	dataItems[cursor] = newDataItem;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	for (int i = 0; i < size; i++) {
		dataItems[i] = NULL;
	}
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns true if a list is empty. Otherwise, returns false.
{
	if (size == 0)
		return true;
	else
		return false;
	// pre-lab
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns true if a list is full. Otherwise, returns false.
{
	if (size == maxSize)
		return true;
	else
		return false;
	// pre-lab

}

//--------------------------------------------------------------------

bool List::gotoBeginning()
// Moves the cursor to the beginning of the list.
{
	if (isEmpty() == false) {
		cursor = 0;
		return true;
	}
	else
		return false;
	// pre-lab

}

//--------------------------------------------------------------------

bool List::gotoEnd()

// Moves the cursor to the end of the list.

{
	if (isEmpty() == false) {
		cursor = size - 1;
		return true;
	}
	else
		return false;
	// pre-lab
}

//--------------------------------------------------------------------

bool List::gotoNext()

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	if (cursor == size - 1 || size == 0)
		return false;
	else {
		cursor++;
		return true;
	}
	// pre-lab

}

//--------------------------------------------------------------------

bool List::gotoPrior()

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.
{
	if (cursor == 0 || size == 0)
		return false;
	else {
		cursor--;
		return true;
	}
	// pre-lab
}

//--------------------------------------------------------------------

DataType List::getCursor() const
// Returns the item marked by the cursor

{
	return dataItems[cursor];
	// pre-lab

}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	cout << "size = " << size << "\t" << "cursor = " << cursor << endl;
	for (int i = 0; i < maxSize; i++)
	{
		cout << "[ " << i << " ]\t";
	}
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << dataItems[i] << "  \t";
	}
	cout << endl;
}