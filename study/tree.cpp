#include "tree.h"

SearchTree::SearchTree()
{
	root = nullptr;
}

SearchTree::~SearchTree()
{
	root = nullptr;
}


//����
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


//��ӽڵ�
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

//�������
void SearchTree::InorderTraversal(treeNode* root)
{
	if (root == nullptr)
		return;
	InorderTraversal(root->left);
	cout << " " << root->number << " ";
	InorderTraversal(root->right);
}

//���ҽڵ�
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

//���Ҹ��ڵ�
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

//ɾ���ڵ�
treeNode* SearchTree::DeleNode(treeNode* root, int target)
{
	if (root == nullptr)
		return nullptr;
	treeNode* temp = nullptr;
	treeNode* partemp = nullptr;
	temp = FindNode(root, target);
	if (temp == nullptr)
		cout << "δ�ҵ��ýڵ㣬ֵΪ" << target << endl;
	else
	{
		//û���ӽڵ�
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
		//ֻ��һ�����ӽڵ�
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
		//ֻ��һ�����ӽڵ�
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
		//�������ӽڵ�
		else
		{
			partemp = FindParNode(root, target);
			if (partemp != nullptr)
			{
				treeNode* rightmin = temp; //���������ҳ���Сֵ����ֵ�ض�ΪҶ�ӽڵ�
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
			//ɾ�����ڵ�
			else
			{
				treeNode* rightmin = temp; //���������ҳ���Сֵ����ֵ�ض�ΪҶ�ӽڵ�
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

//���ظ��ڵ�
treeNode* SearchTree::GetRootTree()
{
	return root;
}
