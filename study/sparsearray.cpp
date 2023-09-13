/*
当一个数组中大部分元素为0或者为同一个值时，可以使用稀疏数组来保存该数组
稀疏数组的处理方式：记录数组一共有几行几列，有多少个不同值，把具有不同值的元素和行列及其值记录在一个小规模的数组中，从而压缩数组
原始数组：
{
	0 0 1 0 0，
	0 0 0 2 0，
	0 0 0 0 0，
	0 0 0 0 0，
	0 0 0 0 0，
}
稀疏数组(固定3列)：
{
	行(row) 列(col) 值(value)
	5		5		2，		//5行5列2个值
	0		2		1，		//第一个值在0行2列值为1
	1		3		2，		//第二个值在1行3列值为2
}
5行5列压缩为3行3列

将二维数组转稀疏数组
1、先遍历二维数组得到非0数据的个数
2、创建稀疏数组

将稀疏数组转为原始数组
1、先取稀疏数组第一行恢复原始数组默认值
2、读取稀疏数组后面几行，填入真实数据
*/

#include "sparsearray.h"
#include <algorithm>




void SparseArry::PrintVec(vector<vector<int>> &vec)
{
	for (vector<vector<int>>::iterator itv = vec.begin(); itv != vec.end(); itv++)
	{
		for (vector<int>::iterator it = (*itv).begin(); it != (*itv).end(); it++)
		{
			cout << *it <<"   ";
		}
		cout << endl;
	}
}



//获取数值个数
int SparseArry::GetValueNumber(vector<vector<int>> &vec)
{
	int num = 0;
	for (vector<vector<int>>::iterator itv = vec.begin(); itv != vec.end(); itv++)
	{
		for (vector<int>::iterator it = (*itv).begin(); it != (*itv).end(); it++)
		{
			if (*it != 0)
			{
				num++;
			}
		}
	}
	m_num = num;
	return num;
}

void SparseArry::CreatSparseArry(vector<vector<int>> &sourvec, vector<vector<int>> &destvec)
{
	destvec[0][0] = sourvec.size();
	destvec[0][1] = sourvec[0].size();
	destvec[0][2] = m_num;

	int i = 0;	//行
	int j = 0;	//列
	int count = 0;	//用于记录第几个有效值
	for (vector<vector<int>>::iterator itv = sourvec.begin(); itv != sourvec.end(); itv++, i++)
	{
		j = 0;
		for (vector<int>::iterator it = (*itv).begin(); it != (*itv).end(); it++, j++)
		{
			if (*it != 0)
			{
				count++;
				destvec[count][0] = i;
				destvec[count][1] = j;
				destvec[count][2] = *it;
			}
		}
	}
	
}