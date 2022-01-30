//--------------------------------------------------------------------
//
//  Laboratory 8                                          bstree.cpp
// 컴퓨터공학과 2020112377 김민수
//  linked implementation of the
//  Binary Search Tree ADT -- including the recursive partners of
//  the public member functions
//
//--------------------------------------------------------------------

#include <iostream>
#include "bstree.h"

using namespace std;

//--------------------------------------------------------------------
 // Constructor
template < class DT, class KF >
BSTreeNode<DT, KF>::BSTreeNode(const DT& nodeDataItem, BSTreeNode* leftPtr, BSTreeNode* rightPtr)
    :dataItem(nodeDataItem), left(leftPtr), right(rightPtr)
{

}

template < class DT, class KF >
BSTree<DT, KF>::BSTree()
    :root(NULL)
{

}
//--------------------------------------------------------------------
// Destructor
template < class DT, class KF >
BSTree<DT, KF>::~BSTree()
{
    clear();
}
//--------------------------------------------------------------------
 // Binary search tree manipulation operations
//--------------------------------------------------------------------
//insert
template < class DT, class KF >
void BSTree<DT, KF>::insert(const DT& newDataItem)
{   // Insert data item
    if (isFull())
        cout << "Tree is Full" << endl;
    else
        insertSub(root, newDataItem);
}

template < class DT, class KF >
void BSTree<DT, KF>::insertSub(BSTreeNode<DT, KF>*& p, const DT& newDataItem)
{
    if (p == NULL) {    //base case
        p = new BSTreeNode<DT, KF>(newDataItem, NULL, NULL);
    }
    else if (newDataItem.key() < (p->dataItem).key()) 
        insertSub(p->left, newDataItem);
    else if (newDataItem.key() > (p->dataItem).key())
        insertSub(p->right, newDataItem);
    else                        //중복하는 경우(newDataItem.key()==p->dataItem.key())
        p->dataItem = newDataItem;
}
//--------------------------------------------------------------------
//retrieve
template < class DT, class KF >
bool BSTree<DT, KF>::retrieve(KF searchKey, DT& searchDataItem) const
{
    return retrieveSub(root, searchKey, searchDataItem);
}

template < class DT, class KF >
bool BSTree<DT, KF>::retrieveSub(BSTreeNode<DT, KF>* p, KF searchKey, DT& searchDataItem) const
{
    if (p==NULL)     //찾는 값이 없는 경우 base case 1
        return false;
    else if (searchKey < (p->dataItem).key())
        return retrieveSub(p->left, searchKey, searchDataItem);
    else if (searchKey > (p->dataItem).key())
        return retrieveSub(p->right, searchKey, searchDataItem);
    else {               //searchKey==p->dataItem.key()인 경우 base case 2
        searchDataItem = p->dataItem;
        return true;
    }
}
//--------------------------------------------------------------------
//remove
template < class DT, class KF >
bool BSTree<DT, KF>::remove(KF deleteKey)
{
   return removeSub(root, deleteKey);
}

template < class DT, class KF >
bool BSTree<DT, KF>::removeSub(BSTreeNode<DT, KF>*& p, KF deleteKey)
{
    if (p == NULL)          
        return false;
    else if (deleteKey < (p->dataItem).key())
       return removeSub(p->left, deleteKey); 
    else if (deleteKey > (p->dataItem).key())
        return removeSub(p->right, deleteKey);
    else
    {    //deleteKey==p->dataItem.key()
        BSTreeNode<DT, KF>* tempPtr = p;
        if (p->left == NULL) {         //right child만 있는 경우
            p = p->right;
        }
        else if (p->right == NULL) {   //left child만 있는 경우
            p = p->left;
        }
        else {                                      //child가 2개
            cutRightmost(p->left, tempPtr);
        }
        delete tempPtr;
        return true;
    }
}
//left subtree에서 가장 right node의 dataItem을 delPtr의 dataItem에 copy 해주고
//delPtr이 그 node를 가리키게 함
template < class DT, class KF >
void BSTree<DT, KF>::cutRightmost(BSTreeNode<DT, KF>*& r, BSTreeNode<DT, KF>*& delPtr)
{
    if (r->right != NULL)
        cutRightmost(r->right, delPtr);   // Continue down to the right
    else
    {
        delPtr->dataItem = r->dataItem;
        delPtr = r;
        r = r->left;
    }
}
//--------------------------------------------------------------------
// Write Keys--오름차순으로 tree의 dataItem 출력
template < class DT, class KF >
void BSTree<DT, KF>::writeKeys() const
{
    if (isEmpty())
        cout << "Tree is Empty" << endl;
    else
    {
        writeKeysSub(root);
        cout << endl;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::writeKeysSub(BSTreeNode<DT, KF>* p) const
{
    if (p != NULL) {
        writeKeysSub(p->left);
        cout << (p->dataItem).key() << " ";
        writeKeysSub(p->right);
    }
}
//--------------------------------------------------------------------
// Clear
template < class DT, class KF >
void BSTree<DT, KF>::clear()
{
    clearSub(root);
    root = NULL;
}

template < class DT, class KF >
void BSTree<DT, KF>::clearSub(BSTreeNode<DT, KF>* p)
{
    if (p != NULL)
    {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}
//--------------------------------------------------------------------
// Binary search tree status operations
//--------------------------------------------------------------------
// Empty / Full
template < class DT, class KF >
bool BSTree<DT, KF>::isEmpty() const
{
    return root == NULL;
}

template < class DT, class KF >
bool BSTree<DT, KF>::isFull() const
{
    DT test;
    BSTreeNode <DT, KF>* tmp = new BSTreeNode <DT, KF>(test, NULL, NULL);
    if (tmp == NULL)
        return true;
    else {
        delete tmp;
        return false;
    }

}
//--------------------------------------------------------------------
// Show Structure
template < class DT, class KF >
void BSTree<DT, KF>::showStructure() const
{
    if (root == 0)
        cout << "Empty tree" << endl;
    else
    {
        cout << endl;
        showSub(root, 1);
        cout << endl;
    }
}

template < class DT, class KF >
void BSTree<DT, KF>::showSub(BSTreeNode<DT, KF>* p, int level) const
{
    int j;   // Loop counter

    if (p != 0)
    {
        showSub(p->right, level + 1);         // Output right subtree
        for (j = 0; j < level; j++)    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.key();  // Output key
        if ((p->left != 0) &&           // Output "connector"
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);          // Output left subtree
    }
}
//--------------------------------------------------------------------
// In-lab 2
template < class DT, class KF >
int BSTree<DT, KF>::getHeight() const
{
    return getHeightSub(root);
}

template < class DT, class KF >
int BSTree<DT, KF>::getHeightSub(BSTreeNode<DT, KF>* p) const
{
    if (p == NULL)
        return 0;
    else {
        int leftSub = getHeightSub(p->left)+1;
        int rightSub = getHeightSub(p->right)+1;
        if (leftSub >= rightSub)
            return leftSub;
        else
            return rightSub;
    }
}
//--------------------------------------------------------------------
// In-lab 3 - 입력한 searhKey값보다 작은 값을 오름차순으로 반환
template < class DT, class KF >
void BSTree<DT, KF>::writeLessThan(KF searchKey) const
{
    writeLTSub(root, searchKey);
}

template < class DT, class KF >
void BSTree<DT, KF>::writeLTSub(BSTreeNode <DT, KF>* p, const KF searchKey) const
{
    if (p != NULL) {
        writeLTSub(p->left, searchKey);
        if (searchKey > p->dataItem.key()) {
            cout << p->dataItem.key() << " ";
            writeLTSub(p->right, searchKey);
        }
    }
}