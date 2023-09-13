/*
��һ�������д󲿷�Ԫ��Ϊ0����Ϊͬһ��ֵʱ������ʹ��ϡ�����������������
ϡ������Ĵ���ʽ����¼����һ���м��м��У��ж��ٸ���ֵͬ���Ѿ��в�ֵͬ��Ԫ�غ����м���ֵ��¼��һ��С��ģ�������У��Ӷ�ѹ������
ԭʼ���飺
{
	0 0 1 0 0��
	0 0 0 2 0��
	0 0 0 0 0��
	0 0 0 0 0��
	0 0 0 0 0��
}
ϡ������(�̶�3��)��
{
	��(row) ��(col) ֵ(value)
	5		5		2��		//5��5��2��ֵ
	0		2		1��		//��һ��ֵ��0��2��ֵΪ1
	1		3		2��		//�ڶ���ֵ��1��3��ֵΪ2
}
5��5��ѹ��Ϊ3��3��

����ά����תϡ������
1���ȱ�����ά����õ���0���ݵĸ���
2������ϡ������

��ϡ������תΪԭʼ����
1����ȡϡ�������һ�лָ�ԭʼ����Ĭ��ֵ
2����ȡϡ��������漸�У�������ʵ����
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



//��ȡ��ֵ����
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

	int i = 0;	//��
	int j = 0;	//��
	int count = 0;	//���ڼ�¼�ڼ�����Чֵ
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