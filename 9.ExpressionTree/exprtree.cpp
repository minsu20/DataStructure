//--------------------------------------------------------------------
//
// 2020112377 컴퓨터공학전공 김민수		
// Lab 9									exprtree.cpp
//  the linked implementation of the
//  Expression Tree ADT -- including the recursive partners of the
//  public member functions
//
//--------------------------------------------------------------------

#include "exprtree.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Constructor
ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode* leftPtr, ExprTreeNode* rightPtr)
    :dataItem(elem), left(leftPtr), right(rightPtr)
{

}

//--------------------------------------------------------------------
// Constructor
ExprTree::ExprTree()
    :root(NULL)
{

}
// Destructor
ExprTree::~ExprTree()
{
    clear();
}

//--------------------------------------------------------------------
// Build tree from prefix expression
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

        if (prefix=='+'||prefix=='-'||prefix=='*'||prefix=='/') 
        { //operator이면
            buildSub(p->left);
            buildSub(p->right);
            return;
        }
        else 
        {
            return;
        }
    }
}

//--------------------------------------------------------------------
//Outputs the corresponding arithmetic expression in fully parenthesized infix form.
void ExprTree::expression() const
{
    exprSub(root);
}

void ExprTree::exprSub(ExprTreeNode* p) const
{
    if (p != 0) 
    {
        if (p->left != 0 && p->right != 0) 
        {
            cout << '(';
            exprSub(p->left);
            cout << p->dataItem;
            exprSub(p->right);
            cout << ')';
        }
        else
            cout << p->dataItem;
    }
}

//--------------------------------------------------------------------
//Returns the value of the corresponding arithmetic expression.
float ExprTree::evaluate() const
{
    if (root == 0) 
    { //Requirements: Expression tree is not empty.
        cout << "Expression tree is empty." << endl;
        return 0;
    }
    else 
    {
        float temp=evaluateSub(root);
        return temp;
    }
}

float ExprTree::evaluateSub(ExprTreeNode* p) const
{

    if (p->dataItem == '+' || p->dataItem == '-' || p->dataItem == '*' || p->dataItem == '/') 
    {//operator이면
        switch (p->dataItem) 
        {
        case '+': return(evaluateSub(p->left) + evaluateSub(p->right));
        case '-': return(evaluateSub(p->left) - evaluateSub(p->right));
        case '*': return(evaluateSub(p->left) * evaluateSub(p->right));
        case '/': return(evaluateSub(p->left) / evaluateSub(p->right));
        }
    }
    else 
    {//숫자면
        return p->dataItem - '0';
    }
}

//--------------------------------------------------------------------
// Clear tree
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

void ExprTree::showSub(ExprTreeNode* p, int level) const
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

//--------------------------------------------------------------------
ExprTree::ExprTree(const ExprTree& valueTree)
    :root(NULL)
{
    if (valueTree.root != 0) 
    {
        copySub(root, valueTree.root);
    }
}


void ExprTree::copySub(ExprTreeNode*& dest, ExprTreeNode* source)
{
    dest = new ExprTreeNode(source->dataItem, NULL, NULL);
    if (source->dataItem == '+' || source->dataItem == '-' || source->dataItem == '*' || source->dataItem == '/') 
    {
        copySub(dest->left, source->left);
        copySub(dest->right, source->right);
        return;
    }
    else 
    {
        return;
    }

}