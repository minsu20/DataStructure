//--------------------------------------------------------------------
//
//  Laboratory 7                                         listrec.cpp
// 2020112377 컴퓨터공학과 김민수
//  Partial linked list implementation of the List ADT with
//  additional recursive linked list functions
//
//--------------------------------------------------------------------

#include <iostream>
#include "stacklnk.cpp"
#include "listrec.h"

using namespace std;

//--------------------------------------------------------------------
 // Constructor
template < class DT >
ListNode <DT>::ListNode(const DT& initData, ListNode* nextPtr) 
    :dataItem(initData), next(nextPtr)
{
}

template < class DT >
List <DT>::List(int ignored)
    :head(nullptr), cursor(nullptr)
{
}
//--------------------------------------------------------------------
// Destructor
template < class DT >
List <DT>::~List() 
{
    clear();
}
//--------------------------------------------------------------------
// List status operations
template<class DT>
bool List <DT>:: isEmpty()
{
    return cursor == nullptr;
}

template<class DT>
bool List <DT>:: isFull()
{
    ListNode<DT>* tempPtr;
    tempPtr = new ListNode<DT>(NULL, nullptr);
    if (tempPtr == nullptr)
        return true; //새 노드가 생성이 안되면 true
    else {
        delete tempPtr;
        return false;
    }
}
//--------------------------------------------------------------------
// List manipulation functions
template < class DT >
void List <DT>::insert(const DT& newData) 
{    // Insert after cursor
    if (isFull()) {
        cout << "List is Full. Element cannot be inserted." << endl;
        return; //다 채워진 경우
    }
    else if (isEmpty()) {
        ListNode<DT>* location = new ListNode<DT>(newData, nullptr);
        head = location;
        cursor = location;
        return; //비워져 있는 경우 
    }
    else {
        ListNode<DT>* location = new ListNode<DT>(newData, cursor->next);
        cursor->next = location;
        cursor = location;
    }

}

template <class DT>
void List <DT>::clear() 
{ // Clear list
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

template<class DT>
void List<DT>::remove(){  // Remove data item
    if (isEmpty()) 
    {
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
        if (gotoPrior()) {
            cursor->next = tempPtr->next;
            delete tempPtr;
            cursor = cursor->next;
            if (cursor == nullptr) {
                cursor = head; //커서가 끝에 있는 경우 헤드로
            }
        }

    }
}
//--------------------------------------------------------------------
// List iteration operations
template<class DT>
bool List<DT>::gotoPrior()
{
    if (isEmpty() || cursor == head) {
        return false;
    }
    ListNode<DT>* tempPtr = head;
    while (tempPtr->next != cursor) //tempPtr다음이 cursor를 가리킬 때까지 tempPtr를 뒤로 옮김 
        tempPtr = tempPtr->next;
    cursor = tempPtr;
    return true;
}
//-------------------------------------------------------------------------

// Output the list structure -- used in testing/debugging
template <class DT>
void List <DT>::showStructure() const {
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
//--------------------------------------------------------------------



//--------------------------------------------------------------------
//
// Recursively implemented linked list functions used in the Prelab
// Exercise
//
//--------------------------------------------------------------------

template < class DT >
void List<DT>::write() const

// Outputs the data in a list from beginning to end. Assumes that
// objects of type DT can be output to the cout stream.

{
    cout << "List : ";
    writeSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeSub(ListNode<DT>* p) const

// Recursive partner of the write() function. Processes the sublist
// that begins with the node pointed to by p.

{
    if (p != 0)
    {
        cout << p->dataItem;      // Output data
        writeSub(p->next);    // Continue with next node
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::insertEnd(const DT& newDataItem)

// Inserts newDataItem at the end of a list. Moves the cursor to
// newDataItem.

{
    insertEndSub(head, newDataItem);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::insertEndSub(ListNode<DT>*& p,
    const DT& newDataItem)

    // Recursive partner of the insertEnd() function. Processes the
    // sublist that begins with the node pointed to by p.

{
    if (p != 0)
        insertEndSub(p->next, newDataItem);    // Continue searching for
    else                                     // end of list
    {
        p = new ListNode<DT>(newDataItem, 0);  // Insert new node
        cursor = p;                           // Move cursor
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::writeMirror() const

// Outputs the data in a list from beginning to end and back
// again. Assumes that objects of type DT can be output to the cout
// stream.

{
    cout << "Mirror : ";
    writeMirrorSub(head);
    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::writeMirrorSub(ListNode<DT>* p) const

// Recursive partner of the writeMirror() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if (p != 0)
    {
        cout << p->dataItem;           // Output data (forward)
        writeMirrorSub(p->next);   // Continue with next node
        cout << p->dataItem;           // Output data (backward)
    }
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::reverse()

// Reverses the order of the data items in a list.

{
    reverseSub(0, head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::reverseSub(ListNode<DT>* p, ListNode<DT>* nextP)

// Recursive partner of the reverse() function. Processes the sublist
// that begins with the node pointed to by nextP.

{
    if (nextP != 0)
    {
        reverseSub(nextP, nextP->next);   // Continue with next node
        nextP->next = p;                 // Reverse link
    }
    else
        head = p;                        // Move head to end of list
}

//--------------------------------------------------------------------

template < class DT >
void List<DT>::deleteEnd()

// Deletes the data at the end of a list. Moves the cursor to the
// beginning of the list.

{
    deleteEndSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::deleteEndSub(ListNode<DT>*& p)

// Recursive partner of the deleteEnd() function. Processes the
// sublist that begins with the node pointed to by p.

{
    if (p->next != 0)
        deleteEndSub(p->next);   // Continue looking for the last node
    else
    {
        delete p;                // Delete node
        p = 0;                   // Set p (link or head) to null
    }
}

//--------------------------------------------------------------------

template < class DT >
int List<DT>::getLength() const

// Returns the number of data items in a list.

{
    return getLengthSub(head);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
int List<DT>::getLengthSub(ListNode<DT>* p) const

// Recursive partner of the length() function. Processes the sublist
// that begins with the node pointed to by p.

{
    int result;   // Result returned

    if (p == 0)
        result = 0;                            // End of list reached
    else
        result = (getLengthSub(p->next) + 1);   // Number of nodes after
                                               // this one + 1
    return result;
}

// inLab- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::iterReverse()
//uses iteration, in conjunction with a small set of pointers, in place of recursion.
{
    if(!isEmpty()){
        ListNode<DT>* tempPtr = head; //tempPtr head로 
            while (tempPtr->next != nullptr) {
                tempPtr = tempPtr->next; //맨 끝까지 이동
            }
        ListNode <DT>* newhead = tempPtr; //reverse 후 새로 head가 될 포인터
            ListNode<DT>* location;
            while (tempPtr != head) {
                location = head; //원래 head로 이동 
                    while (location->next != tempPtr)
                        location = location->next; //location은 tempPtr의 전을 가리킴
                    tempPtr->next = location; //tempPtr이 전의 위치를 next로 가리킴
                tempPtr = location;//tempPtr 한 칸 앞으로 가기
            }
        head->next = nullptr; //원래 head는 이제 맨 끝이 되었으므로 next는 nullptr
        head = newhead; //새로 head가 될 포인터로 head 바꿈
    } 
    else {
        cout << "Empty List. You cannot reverse";
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::stackWriteMirror() const //stacklnk이용해서
{
    Stack<ListNode<DT>*> tempStack;
    ListNode<DT>* p = new ListNode<DT>(NULL, nullptr); //ListNode 생성
    p = head; 
    cout << "Stack Mirror : ";
    while (p != 0) 
    {
        tempStack.push(p);
        cout << p->dataItem; 
        p = p->next;
    }

    while (!tempStack.isEmpty()) 
    {
        p = tempStack.pop();
        cout << p->dataItem; 
    }

    cout << endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Removes all the occurrences of the character ‘c’ from a list of characters.Moves the cursor to the
//beginning of the list.
template < class DT >
void List<DT>::cRemove()
{
    cRemoveSub(head);
    cursor = head;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void List<DT>::cRemoveSub(ListNode<DT>*& p)
{
    if (p != 0) {
        if (p->dataItem == 'c') {
            cursor = p;
            remove();
            p = cursor;
            cRemoveSub(p);
        }
        else {
            cRemoveSub(p->next);
        }
    }
}