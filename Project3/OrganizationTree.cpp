//--------------------------------------------------------------------------
// 
//      2020112377 컴퓨터공학전공 김민수
//
//		Project03 - Tree Application.  OrganizationTree.cpp
// 
// 
//-------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <queue>
#include "tree.h"
using namespace std;

TreeNode::TreeNode(string name) {
	this->name = name;
}

string TreeNode::getName() {
	return name;
}

//--------------------------------------------------------------------

HierarchyTree::HierarchyTree() {
	root = NULL;
	cnt = 0;
}

HierarchyTree::~HierarchyTree() {
	clear();
}

//--------------------------------------------------------------------
//hire

void HierarchyTree::hire(string boss, string sub) {

	if (cnt == 1000) {
		cout << "Cannot hire more than 1000 people" << endl;
		return;
	}

	TreeNode* employee = new TreeNode(sub);

	if (isEmpty()) {
		root = employee; //CEO
	}
	else {
		TreeNode* super = find(root, boss); //boss(고용하는 사람)찾기
		if (super != NULL) { //boss가 있으면 (있어야 고용 가능)
			for (int i = 0; i < super->subordinate.size(); i++) {
				if (super->subordinate[i]->getName() == sub) {//sub(고용당하는 사람)이미 있음
					cout << "employee \"" << sub << "\" already exist" << endl;
					return;
				}
			}
			super->subordinate.push_back(employee); //boss의 (direct) subordinate vector에 추가
			cnt++; //멤버 수 증가
		}
		else { //boss가 없으면
			cout << "employee \"" << boss << "\" not exist" << endl;
		}
	}
}

//--------------------------------------------------------------------
//fire 

void HierarchyTree::fire(string name) {
	if (isEmpty())
		return;

	TreeNode* target = find(root, name); //이름이 name인 사람 찾기
	if (target == NULL) { //해당 사람 없으면 (fire 못함)
		cout << "employee \"" << name << "\" not exist" << endl;
		return;
	}

	TreeNode* super = superior(name); //victom 직속 상사

	if (target->subordinate.size() == 0) {	// victom이 subordniate이 아무도 없을 경우
		if (super == NULL) {		// 직속 상사도 없는 경우->victom이 CEO
			root = NULL; //root를 NULL로
		}
		else { //직속 상사는 있음
			for (int i = 0; i < super->subordinate.size(); i++) {
				if (super->subordinate[i]->getName() == name) {//직속상사 subordinate에서 victom찾으면
					super->subordinate.erase(super->subordinate.begin() + i); //fire(원소 삭제)
				}
			}
		}
	}
	else {	//victom이 subordinate이 있는 경우
		promoted(target); //victom이 한단계 더 승진->victom의 부하 중 서열 가장 높은 한명 줄줄이 다 승진

		if (super == NULL) { //직속 상사는 없음->victom이 CEO
			root = target->subordinate[0]; //victom의 가장 첫 번째 부하(서열이 가장 높음)를 root로
			return;
		}

		for (int i = 0; i < target->subordinate.size(); i++) { //victom의 부하 super의 부하로 copy
			super->subordinate.push_back(target->subordinate[i]);
		}

		for (int i = 0; i < super->subordinate.size(); i++) { //target은 fire
			if (super->subordinate[i]->getName() == name) {
				super->subordinate.erase(super->subordinate.begin() + i);
			}
		}

	}

	delete target;
}

//--------------------------------------------------------------------
//clear

void HierarchyTree::clear() {
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* element = q.front();
		q.pop();
		for (int i = 0; i < element->subordinate.size(); i++) {
			q.push(element->subordinate[i]);
		}
		delete element;
	}
}

//--------------------------------------------------------------------
//이름이 target인 멤버 찾기

TreeNode* HierarchyTree::find(TreeNode* curr, string target) {

	if (curr->getName() == target) {
		return curr;
	}

	int num = curr->subordinate.size();
	for (int i = 0; i < num; i++) {
		TreeNode* found = find(curr->subordinate[i], target);
		if (found != NULL) return found;
	}

	return NULL;
}

//--------------------------------------------------------------------
//직속 상사 구하기

TreeNode* HierarchyTree::superior(string name) { //name인 사람의 직속 상사 구하기

	if (root->getName() == name) return NULL;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* element = q.front();
		q.pop();
		for (int i = 0; i < element->subordinate.size(); i++) {
			if (element->subordinate[i]->getName() == name)
				return element;
			else
				q.push(element->subordinate[i]);
		}
	}
}

//--------------------------------------------------------------------
//target TreeNode 승진시키고 직속 부하도 쭉 승진시킴

void HierarchyTree::promoted(TreeNode* target) { //victom을 한단계 더 높이 승진->가장 서열 높은 부하 줄줄이 승진

	if (target->subordinate.size() != 0)
	{
		promoted(target->subordinate[0]);
	}

	TreeNode* super = superior(target->getName());
	if (super == NULL) {
		return;
	}
	else {
		while (super->subordinate.size() != 1) {
			target->subordinate.push_back(super->subordinate[1]);
			super->subordinate.erase(super->subordinate.begin() + 1);
		}
	}
}

//--------------------------------------------------------------------
//print

void HierarchyTree::showStructure() {
	if (isEmpty()) {
		cout << "[Empty]" << endl;
		return;
	}
	cout << "[OutPut]" << endl;
	showStructureSub(root, 0);
	for (int i = 0; i < 60; i++) {
		cout << "-";
	}
	cout << endl;
}


void HierarchyTree::showStructureSub(TreeNode* curr, int level) {


	for (int i = 0; i < level; i++) {
		cout << "+";
	}
	cout << curr->getName() << endl;

	for (int i = 0; i < curr->subordinate.size(); i++) {
		showStructureSub(curr->subordinate[i], level + 1);
	}
}

//--------------------------------------------------------------------
//empty인지 체크

bool HierarchyTree::isEmpty() const {
	return root == NULL;
}


