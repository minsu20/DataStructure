//--------------------------------------------------------------------------
// 
//      2020112377 ��ǻ�Ͱ������� ��μ�
//
//		Project03 - Tree Application.  tree.h
// 
// 
//-------------------------------------------------------------------------

#pragma once
#include <string>
#include <vector>
using namespace std;

class TreeNode {
private:
	string name;
	vector<TreeNode*> subordinate; //�������� vector

public:

	TreeNode() {}; 
	TreeNode(string name); 	// Constructor

	string getName();
	friend class HierarchyTree;
};

class HierarchyTree {
public:
	// Constructor
	HierarchyTree();

	// Destructor
	~HierarchyTree();

	// Tree manipulation operations
	void hire(string boss, string sub);	  //�߰�
	void fire(string name);	//����
	void clear(); //clear�Լ�

	// Tree status operations
	bool isEmpty() const; //����ִ��� üũ

	// Output the tree structure
	void showStructure();

private:
	TreeNode* find(TreeNode* curr, string target);	// target�̸��� ���� TreeNodeã��
	TreeNode* superior(string name);  //���ӻ�� ���ϱ�
	void promoted(TreeNode* target);	// tree������ (���� ���� ���Ӻ��� ����)
	void showStructureSub(TreeNode* curr, int level);

	// Data member
	TreeNode* root;
	int cnt;

};