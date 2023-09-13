#pragma once
#include <iostream>


using namespace std;
struct treeNode
{
	int number;
	treeNode* left;
	treeNode* right;
};

//二叉排序树
class SearchTree
{
public:
	SearchTree();
	virtual ~SearchTree();

	//创建
	treeNode* CreatSearchTree(treeNode target);

	//添加节点
	void AddSearchTree(treeNode* root, treeNode target);

	//中序遍历
	void InorderTraversal(treeNode* root);

	//查找节点
	treeNode* FindNode(treeNode* root, int target);

	//删除节点
	treeNode* DeleNode(treeNode* root, int target);

	//返回根节点
	treeNode* GetRootTree();

	//查找父节点
	treeNode* FindParNode(treeNode* root, int target);

private:
	//根节点
	treeNode* root;

};