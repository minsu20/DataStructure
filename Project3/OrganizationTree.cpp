//--------------------------------------------------------------------------
// 
//      2020112377 ��ǻ�Ͱ������� ��μ�
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
		TreeNode* super = find(root, boss); //boss(����ϴ� ���)ã��
		if (super != NULL) { //boss�� ������ (�־�� ��� ����)
			for (int i = 0; i < super->subordinate.size(); i++) {
				if (super->subordinate[i]->getName() == sub) {//sub(�����ϴ� ���)�̹� ����
					cout << "employee \"" << sub << "\" already exist" << endl;
					return;
				}
			}
			super->subordinate.push_back(employee); //boss�� (direct) subordinate vector�� �߰�
			cnt++; //��� �� ����
		}
		else { //boss�� ������
			cout << "employee \"" << boss << "\" not exist" << endl;
		}
	}
}

//--------------------------------------------------------------------
//fire 

void HierarchyTree::fire(string name) {
	if (isEmpty())
		return;

	TreeNode* target = find(root, name); //�̸��� name�� ��� ã��
	if (target == NULL) { //�ش� ��� ������ (fire ����)
		cout << "employee \"" << name << "\" not exist" << endl;
		return;
	}

	TreeNode* super = superior(name); //victom ���� ���

	if (target->subordinate.size() == 0) {	// victom�� subordniate�� �ƹ��� ���� ���
		if (super == NULL) {		// ���� ��絵 ���� ���->victom�� CEO
			root = NULL; //root�� NULL��
		}
		else { //���� ���� ����
			for (int i = 0; i < super->subordinate.size(); i++) {
				if (super->subordinate[i]->getName() == name) {//���ӻ�� subordinate���� victomã����
					super->subordinate.erase(super->subordinate.begin() + i); //fire(���� ����)
				}
			}
		}
	}
	else {	//victom�� subordinate�� �ִ� ���
		promoted(target); //victom�� �Ѵܰ� �� ����->victom�� ���� �� ���� ���� ���� �Ѹ� ������ �� ����

		if (super == NULL) { //���� ���� ����->victom�� CEO
			root = target->subordinate[0]; //victom�� ���� ù ��° ����(������ ���� ����)�� root��
			return;
		}

		for (int i = 0; i < target->subordinate.size(); i++) { //victom�� ���� super�� ���Ϸ� copy
			super->subordinate.push_back(target->subordinate[i]);
		}

		for (int i = 0; i < super->subordinate.size(); i++) { //target�� fire
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
//�̸��� target�� ��� ã��

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
//���� ��� ���ϱ�

TreeNode* HierarchyTree::superior(string name) { //name�� ����� ���� ��� ���ϱ�

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
//target TreeNode ������Ű�� ���� ���ϵ� �� ������Ŵ

void HierarchyTree::promoted(TreeNode* target) { //victom�� �Ѵܰ� �� ���� ����->���� ���� ���� ���� ������ ����

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
//empty���� üũ

bool HierarchyTree::isEmpty() const {
	return root == NULL;
}


