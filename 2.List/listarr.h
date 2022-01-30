//--------------------------------------------------------------------
//
//                                                          listarr.h
//
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------
// #pragma warning( disable : 4290 )

#include <iostream>

using namespace std;

const int defMaxListSize = 10;   // Default maximum list size

typedef char DataType;

class List
{
public:

	// Constructor
	List(int maxNumber = defMaxListSize);

	// Destructor
	~List();

	// List manipulation operations
	void insert(const DataType& newDataItem);    // Insert after cursor
	void remove();                                 // Remove data item
	void replace(const DataType& newDataItem);   // Replace data item
	void clear();                                 // Clear list

	// List status operations
	bool isEmpty() const;                    // List is empty
	bool isFull() const;                     // List is full

	// List iteration operations
	bool gotoBeginning();                     // Go to beginning
	bool gotoEnd();                           // Go to end
	bool gotoNext();                          // Go to next data item
	bool gotoPrior();                         // Go to prior data item
	DataType getCursor() const;              // Return data item

	// Output the list structure -- used in testing/debugging
	void showStructure() const;

private:
	// Data members
	int maxSize,
		size,             // Actual number of data item in the list
		cursor;           // Cursor array index
	DataType* dataItems;  // Array containing the list data item
};

