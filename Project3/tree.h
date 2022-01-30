//--------------------------------------------------------------------------
// 
//      2020112377 컴퓨터공학전공 김민수
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
	vector<TreeNode*> subordinate; //부하직원 vector

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
	void hire(string boss, string sub);	  //추가
	void fire(string name);	//삭제
	void clear(); //clear함수

	// Tree status operations
	bool isEmpty() const; //비어있는지 체크

	// Output the tree structure
	void showStructure();

private:
	TreeNode* find(TreeNode* curr, string target);	// target이름을 가진 TreeNode찾기
	TreeNode* superior(string name);  //직속상사 구하기
	void promoted(TreeNode* target);	// tree재정리 (가장 높은 직속부하 승진)
	void showStructureSub(TreeNode* curr, int level);

	// Data member
	TreeNode* root;
	int cnt;

};