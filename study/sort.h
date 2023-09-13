#pragma once

/*
	排序算法
	1、交换排序：冒泡排序、快速排序
	2、选择排序：简单选择排序、堆排序
	3、插入排序：直接插入排序、希尔排序
	4、归并排序
	5、基数排序
	堆排序：生成最大堆，把堆顶元素和最后的元素交换，重新调整最大堆，直到剩余数组元素为0
*/

namespace mysort
{
	void myprint(int arr[], int maxsize);

	//冒泡排序，时间复杂度是n^2
	void bubblesort(int arr[],int len); 

	//选择排序，时间复杂度是n^2
	void selectsort(int arr[],int len);

	//堆排序(大顶堆)
	//node:非叶子节点在数组中的索引
	void adjustheap(int arr[], int node, int len);
	void creatheap(int arr[], int len);
	void heapsort(int arr[], int len);

	
}