#pragma once

/*
	�����㷨
	1����������ð�����򡢿�������
	2��ѡ�����򣺼�ѡ�����򡢶�����
	3����������ֱ�Ӳ�������ϣ������
	4���鲢����
	5����������
	�������������ѣ��ѶѶ�Ԫ�غ�����Ԫ�ؽ��������µ������ѣ�ֱ��ʣ������Ԫ��Ϊ0
*/

namespace mysort
{
	void myprint(int arr[], int maxsize);

	//ð������ʱ�临�Ӷ���n^2
	void bubblesort(int arr[],int len); 

	//ѡ������ʱ�临�Ӷ���n^2
	void selectsort(int arr[],int len);

	//������(�󶥶�)
	//node:��Ҷ�ӽڵ��������е�����
	void adjustheap(int arr[], int node, int len);
	void creatheap(int arr[], int len);
	void heapsort(int arr[], int len);

	
}