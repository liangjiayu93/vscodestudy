#include "sort.h"
#include <iostream>

void mysort::bubblesort(int arr[],int len)
{
	int temp = 0;
	bool flag = false;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
		if (!flag)
			break;
		else
			flag = false;
	}
}

void mysort::selectsort(int arr[], int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		int min = arr[i];

		for (int j = i + 1; j < len; j++)
		{
			if (min > arr[j])
			{
				minIndex = j;
				min = arr[j];
			}
		}
		if (minIndex != i)
		{
			arr[minIndex] = arr[i];
			arr[i] = min;
		}
	}

}


void mysort::myprint(int arr[], int maxsize)
{
	int len = maxsize;
	std::cout << "[";
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}


//�������ѣ���������
void mysort::adjustheap(int arr[], int node, int len)
{
	int temp = arr[node]; //��ȡ����ǰԪ�أ�������ʱֵ
	for (int i = node * 2 + 1; i < len; i = i * 2 + 1)
	{
		if (i + 1 < len && arr[i] < arr[i + 1])
		{
			i++; //iָ���ӽڵ�����ֵ
		}
		if (arr[i] > temp)
		{
			arr[node] = arr[i]; //�����ֵ������ǰ�ڵ�
			node = i;
		}
		else
		{
			break;  //��ǰ�ڵ��������ֵ������Ҫ�������˳�ѭ��
		}
	}
	arr[node] = temp;
}

void mysort::creatheap(int arr[], int len)
{
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		adjustheap(arr,i,len);
	}
}

void mysort::heapsort(int arr[], int len)
{
	creatheap(arr,len);

	int temp = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		adjustheap(arr,0,i);
	}
}
