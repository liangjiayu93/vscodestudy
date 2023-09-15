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
//ĳ��������indexλ�ã����ϼ����ƶ�
void heapInsert(int arr[], int index)
{
	//arr[index] = date;
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

void heapSort(int arr[], int heapSize)
{
	if (arr == nullptr || heapSize < 2)
		return;
	for (int i = 1; i < heapSize; i++)
	{
		heapInsert(arr,i);
	}

	while (heapSize > 0)
	{
		swapArr(arr, 0, --heapSize);
		heapify(arr, 0, heapSize);
	}
}

//�ҳ����������Ǹ����ж���λ
int maxbits(int arr[], int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		max = max > arr[i] ? max : arr[i];
	}
	int res = 0;
	while (max != 0)
	{
		max = max / 10;
		res++;
	}
	return res;
}

//��������
//����10��Ͱ�����У����Ѹ�λ��ʮλ����λ�����ֱַ���Ͱ���ٳ�Ͱ��ֱ�����λΪֹ�����ݾ�������
//������һ��count[10]���������10��Ͱ
//arr[left......right]����digit��ʾ������������ж���λ���ж���λ�ͽ���Ͱ���ٴ�
void radixSort(int arr[], int left, int right, int digit)
{
	const int radix = 10;
	int *bucket = new int[right - left + 1]; //�����ռ䣬��arrһ����С

	int j = 0;
	for (int d = 1; d <= digit; d++) //�ж���λ�ͽ������ٴ�
	{

		//count[0]��ʾ��ǰλ��dλ����0�������ж��ٸ�
		//count[1]��ʾ��ǰλ��dλ���ǣ�0��1���������ж��ٸ�
		//count[2]��ʾ��ǰλ��dλ���ǣ�0��1��2���������ж��ٸ�
		//count[i]��ʾ��ǰλ��dλ���ǣ�0��i���������ж��ٸ�
		int count[radix] = { 0 };
		for (int i = 0; i < right - left + 1; i++)  //��¼��ǰλ�ĸ���
		{
			j = getDigit(arr[i], d);
			count[j]++;
		}

		for (int i = 1; i < radix; i++) //����count���飬ʹ���Ϊ�ۼ�
		{
			count[i] = count[i] + count[i - 1];
		}

		//���ҵ����arr�����ݵ����������ռ�bucket��ģ����У������ȳ�ԭ��
		for (int i = right; i >= left; i--)
		{
			j = getDigit(arr[i], d);
			bucket[count[j] - 1] = arr[i];
			count[j]--;
		}

		for (int i = left, j = 0; i <= right; i++, j++) //bucket�������ݵ�arr�����һ�λ�������
		{
			arr[i] = bucket[j];
		}
	}
}

//��ȡ��ǰλ��������
//d��ʾλ����1�Ǹ�λ��2��ʮλ���Դ�����
int getDigit(int num, int d)
{
	d--;
	int pow = 1;
	while (d != 0)
	{
		pow = pow * 10;
		d--;
	}
	return (num / pow) % 10;
}