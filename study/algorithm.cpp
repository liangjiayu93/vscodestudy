#include "algorithm.h"


using namespace std;
/*������*/
/*	
	���^����ͬΪ0����ͬΪ1��
	���ʣ�a^0=a, a^a=0 
	���Ϸ����ɣ�a^b^c = a^(b^c)
*/

//һ������arr��ֻ��һ��������������������ż�����ҳ�������
int findOddnumberone(int arr[], int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor^arr[i];
	}
	return eor;
}

//һ������arr��������������������������ż�����ҳ�������
int findOddnumbertwo(int arr[], int len, int &a, int &b)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ arr[i];
	}
	//eor�����eor=a^b   a��b��������

	/*a��b����ȣ���eorһ��������0����������һλ��1���ҳ����ұ�Ϊ1��λ*/
	int OneRight = eor & (~eor + 1); //��ȡ�����ҵ�1

	int onlyone = 0;
	//���������·��飬OneRight������^�õ��������ݣ�a��b�ֱ��ڲ�ͬ��һ��
	for (int i = 0; i < len; i++)
	{
		if ((OneRight & arr[i]) == 0)
		{
			onlyone = onlyone^arr[i];
		}
	}

	a = onlyone;
	b = eor ^ onlyone;
	return 0;
}

//���������������������
int* generateRandomArry(int maxSize, int maxValue, int& len)
{

	random_device example; //�����

	len = example() % (maxSize + 1);
	int* arr = new int[len]; //�������������

	for (int i = 0; i < len; i++)
	{
		arr[i] = (example() % (maxValue + 1)) - (example() % maxValue);
	}

	return arr;

}

void printfArry(int* arr, int len)
{
	cout << "arr=[";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << "]" << endl;
}

//�鲢�����ȵݹ��ϲ�
void process(int arr[], int left, int right)
{
	if (left > right)
		return;
	if (left == right)
		return;
	int mid = left + ((right - left) >> 1);
	process(arr, left, mid);
	process(arr, mid + 1, right);
	merge(arr, left, mid, right); 
}

void merge(int arr[], int left, int mid, int right)
{
	int* arrtemp = new int[right - left + 1];
	int i = 0;
	int p1 = left;
	int p2 = mid + 1;
	while (p1 <= mid && p2 <= right)
	{
		arrtemp[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
	}
	while (p1 <= mid)
	{
		arrtemp[i++] = arr[p1++];
	}
	while (p2 <= right)
	{
		arrtemp[i++] = arr[p2++];
	}
	int len = right - left + 1;
	for (i = 0; i < len; i++)
	{
		arr[left + i] = arrtemp[i];
	}
	delete[] arrtemp;
}

//����
void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		//random_device example;  //�����
		//int temp = example() % (right - left + 1);
		//swapArr(arr, temp, right);
		int less = 0; //<���߽�
		int more = 0; //>���߽�
		less = partition(arr, left, right);
		//more = more - less + 1;
		quickSort(arr, left, less - 1);
		quickSort(arr, less + 1, right);
	}
}
 
void swapArr(int arr[], int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

int partition(int arr[], int left, int right)
{
	int less = left - 1;
	//more = right;
	while (left < right)
	{
		if (arr[left] < arr[right])
		{
			swapArr(arr, ++less, left++);
		}
		else 
		{
			left++;
		}
	}
	swapArr(arr, ++less, right);
	return less;
}

//��Ѳ���
void heapInsert(int arr[], int index, int date)
{
	arr[index] = date;
	while (index != 0 && arr[index] > arr[(index - 1) / 2])
	{
		swapArr(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

//�������
//ĳ������indexλ�ã��ܷ������ƶ�
void heapify(int arr[], int index, int heapSize)
{
	int left = index * 2 + 1;  //���ӽڵ�
	while (left < heapSize)  //index�к���
	{
		int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
		largest = arr[largest] > arr[index] ? largest : index;

		if (index == largest)
			break;

		swapArr(arr, index, largest);
		index = largest;
		left = index * 2 + 1;
	}
}