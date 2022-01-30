//--------------------------------------------------------------------
//
// 2020112377 ��ǻ�Ͱ������� ��μ�
//  Laboratory 9, In-lab Exercise 1                      logitree.cpp
//
//  The linked implementation of the Logic
//  Expression Tree ADT -- including the recursive partners of the
//  public member functions
//
//--------------------------------------------------------------------

#include "logitree.h"
#include <iostream>

using namespace std;
//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
    :dataItem(elem), left(leftPtr), right(rightPtr)
{

}

//--------------------------------------------------------------------

ExprTree::ExprTree()
    :root(NULL)
{

}

ExprTree::~ExprTree()
{
    clear();
}

//--------------------------------------------------------------------

void ExprTree::build()
{
    buildSub(root);
}

void ExprTree::buildSub(ExprTreeNode*& p)
{
    char prefix;
    cin >> prefix;
    while (prefix != '\n') 
    {
        p = new ExprTreeNode(prefix, NULL, NULL);

        if (p->dataItem == '+' || p->dataItem == '*') //OR �����ڿ� AND ������
        {
            buildSub(p->left);
            buildSub(p->right);
            return;
        }
        else if (p->dataItem == '-') //NOT ������
        {
            buildSub(p->right);
            return;
        }
        else //������ ���
        {
            return;
        }
    }
}

//--------------------------------------------------------------------

void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != 0)
    {
        if (p->left != 0 && p->right != 0)  //OR �����ڿ� AND ������
        {
            cout << '(';
            exprSub(p->left);
            cout << p->dataItem;
            exprSub(p->right);
            cout << ')';
        }
        else if (p->left == 0 && p->right != 0) //NOT ������
        {
            cout << '(';
            cout << p->dataItem;
            exprSub(p->right);
            cout << ')';
        }
        else //������ ���
            cout << p->dataItem;
    }
}

//--------------------------------------------------------------------

int ExprTree::evaluate() const
{
    if (root == 0) 
    {
        cout << "Expression tree is empty." << endl;
        return 0;
    }
    else
    {
        int temp = evaluateSub(root);
        return temp;
    }
}

int ExprTree::evaluateSub(ExprTreeNode* p) const
{
    if (p->dataItem == '+' || p->dataItem == '-' || p->dataItem == '*')
    {//operator�̸�
        switch (p->dataItem)
        {
        case '+': return(evaluateSub(p->left) or evaluateSub(p->right));
        case '-': return(not(evaluateSub(p->right)));
        case '*': return(evaluateSub(p->left) and evaluateSub(p->right));
        }
    }
    else
    {//���ڸ�
        return p->dataItem - '0';
    }
}

//--------------------------------------------------------------------

void ExprTree::clear()
{
    if (root != 0)
    {
        clearSub(root);
        root = 0;
    }
}

void ExprTree::clearSub(ExprTreeNode* p)
{
    if (p != 0)
    {
        clearSub(p->left);
        clearSub(p->right);
        delete p;
    }
}

//--------------------------------------------------------------------

void ExprTree::showStructure() const

// Outputs an expression tree. The tree is output rotated counter-
// clockwise 90 degrees from its conventional orientation using a
// "reverse" inorder traversal. This operation is intended for testing
// and debugging purposes only.

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void ExprTree::showSub(ExprTreeNode* p, int level) const

// Recursive partner of the showStructure() function. Outputs the
// subtree whose root node is pointed to by p. Parameter level is the
// level of this node within the expression tree.

{
    int j;

    if (p != 0)
    {
        showSub(p->right, level + 1);
        for (j = 0; j < level; j++)
            cout << "\t";
        cout << " " << p->dataItem;
        if ((p->left != 0) &&
            (p->right != 0))
            cout << "<";
        else if (p->right != 0)
            cout << "/";
        else if (p->left != 0)
            cout << "\\";
        cout << endl;
        showSub(p->left, level + 1);
    }
}