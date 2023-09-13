#pragma once
#include <iostream>


using namespace std;
struct treeNode
{
	int number;
	treeNode* left;
	treeNode* right;
};

//����������
class SearchTree
{
public:
	SearchTree();
	virtual ~SearchTree();

	//����
	treeNode* CreatSearchTree(treeNode target);

	//��ӽڵ�
	void AddSearchTree(treeNode* root, treeNode target);

	//�������
	void InorderTraversal(treeNode* root);

	//���ҽڵ�
	treeNode* FindNode(treeNode* root, int target);

	//ɾ���ڵ�
	treeNode* DeleNode(treeNode* root, int target);

	//���ظ��ڵ�
	treeNode* GetRootTree();

	//���Ҹ��ڵ�
	treeNode* FindParNode(treeNode* root, int target);

private:
	//���ڵ�
	treeNode* root;

};