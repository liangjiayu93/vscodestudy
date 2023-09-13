#include "tree.h"

SearchTree::SearchTree()
{
	root = nullptr;
}

SearchTree::~SearchTree()
{
	root = nullptr;
}


//创建
treeNode* SearchTree::CreatSearchTree(treeNode target)
{
	if (root == nullptr)
	{
		root = new treeNode;
		root->number = target.number;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		AddSearchTree(root, target);
	}
	return root;
}


//添加节点
void SearchTree::AddSearchTree(treeNode* root, treeNode target)
{
	if (root == nullptr)
		return;
	if (root->number > target.number)
	{
		if (root->left == nullptr)
		{
			treeNode* temp = new treeNode;
			temp->number = target.number;
			temp->left = nullptr;
			temp->right = nullptr;
			root->left = temp;
		}
		else
		{
			AddSearchTree(root->left, target);
		}
	}
	if (root->number < target.number)
	{
		if (root->right == nullptr)
		{
			treeNode* temp = new treeNode;
			temp->number = target.number;
			temp->left = nullptr;
			temp->right = nullptr;
			root->right = temp;
		}
		else
		{
			AddSearchTree(root->right, target);
		}
	}
}

//中序遍历
void SearchTree::InorderTraversal(treeNode* root)
{
	if (root == nullptr)
		return;
	InorderTraversal(root->left);
	cout << " " << root->number << " ";
	InorderTraversal(root->right);
}

//查找节点
treeNode* SearchTree::FindNode(treeNode* root, int target)
{
	if (root == nullptr)
		return nullptr;
	if (root->number == target)
	{
		return root;
	}
	else if (root->number > target)
	{
		FindNode(root->left, target);
	}
	else
	{
		FindNode(root->right, target);
	}
}

//查找父节点
treeNode* SearchTree::FindParNode(treeNode* root, int target)
{
	if (root == nullptr)
		return nullptr;
	if (root->number == target)
	{
		return nullptr;
	}
	else if (root->left != nullptr && root->left->number == target)
	{
		return root;
	}
	else if (root->right != nullptr && root->right->number == target)
	{
		return root;
	}
	else if (root->number > target)
	{
		FindParNode(root->left, target);
	}
	else
	{
		FindParNode(root->right, target);
	}
}

//删除节点
treeNode* SearchTree::DeleNode(treeNode* root, int target)
{
	if (root == nullptr)
		return nullptr;
	treeNode* temp = nullptr;
	treeNode* partemp = nullptr;
	temp = FindNode(root, target);
	if (temp == nullptr)
		cout << "未找到该节点，值为" << target << endl;
	else
	{
		//没有子节点
		if (temp->left == nullptr && temp->right == nullptr)
		{
			partemp = FindParNode(root, target);
			if (partemp != nullptr)
			{
				if (partemp->left != nullptr && partemp->left->number == target)
				{
					partemp->left = nullptr;
					delete temp;
				}
				else if (partemp->right != nullptr && partemp->right->number == target)
				{
					partemp->right = nullptr;
					delete temp;
				}
			}
			else
			{
				delete temp;
			}
		}
		//只有一个左子节点
		else if (temp->left != nullptr && temp->right == nullptr)
		{
			partemp = FindParNode(root, target);
			if (partemp != nullptr)
			{
				if (partemp->left->number == target)
				{
					partemp->left = temp->left;
					delete temp;
				}
				if (partemp->right->number == target)
				{
					partemp->right = temp->left;
					delete temp;
				}
			}
			else
			{
				root = temp->left;
			}
		}
		//只有一个右子节点
		else if (temp->right != nullptr && temp->left == nullptr)
		{
			partemp = FindParNode(root, target);
			if (partemp != nullptr)
			{
				if (partemp->left->number == target)
				{
					partemp->left = temp->right;
					delete temp;
				}
				if (partemp->right->number == target)
				{
					partemp->right = temp->right;
					delete temp;
				}
			}
			else
			{
				root = temp->right;
			}
		}
		//有两个子节点
		else
		{
			partemp = FindParNode(root, target);
			if (partemp != nullptr)
			{
				treeNode* rightmin = temp; //从右子树找出最小值，该值必定为叶子节点
				while (rightmin->left)
				{
					rightmin = rightmin->left;
				}
				treeNode* rightminpar = nullptr;
				rightminpar = FindParNode(root, rightmin->number);
				rightminpar->left = nullptr;

				if (partemp->left->number == target)
				{
					partemp->left = rightmin;
				}
				if (partemp->right->number == target)
				{
					partemp->right = rightmin;
				}
				rightmin->left = temp->left;
				rightmin->right = temp->right;
				delete temp;
			}
			//删除根节点
			else
			{
				treeNode* rightmin = temp; //从右子树找出最小值，该值必定为叶子节点
				while (rightmin->left)
				{
					rightmin = rightmin->left;
				}

				treeNode* rightminpar = nullptr;
				rightminpar = FindParNode(root, rightmin->number);
				rightminpar->left = nullptr;

				rightmin->left = temp->left;
				rightmin->right = temp->right;
				this->root = rightmin;
				delete temp;
			}
		}
	}
	return nullptr;
}

//返回根节点
treeNode* SearchTree::GetRootTree()
{
	return root;
}
