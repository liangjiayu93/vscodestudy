#include "algorithm.h"


using namespace std;
/*面试题*/
/*	
	异或^（相同为0，不同为1）
	性质：a^0=a, a^a=0 
	符合分配律：a^b^c = a^(b^c)
*/

//一个数组arr，只有一种数字是奇数，其它是偶数，找出该奇数
int findOddnumberone(int arr[], int len)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor^arr[i];
	}
	return eor;
}

//一个数组arr，有两种数字是奇数，其它是偶数，找出该奇数
int findOddnumbertwo(int arr[], int len, int &a, int &b)
{
	int eor = 0;
	for (int i = 0; i < len; i++)
	{
		eor = eor ^ arr[i];
	}
	//eor结果是eor=a^b   a和b都是奇数

	/*a和b不相等，则eor一定不等于0，则至少有一位是1，找出最右边为1的位*/
	int OneRight = eor & (~eor + 1); //提取出最右的1

	int onlyone = 0;
	//将数组重新分组，OneRight与数组^得到两组数据，a和b分别在不同的一组
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

//对数器，生成随机数数组
int* generateRandomArry(int maxSize, int maxValue, int& len)
{

	random_device example; //随机数

	len = example() % (maxSize + 1);
	int* arr = new int[len]; //长度随机的数组

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

//归并排序，先递归后合并
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

//快排
void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		//random_device example;  //随机数
		//int temp = example() % (right - left + 1);
		//swapArr(arr, temp, right);
		int less = 0; //<区边界
		int more = 0; //>区边界
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

//大堆插入
//某个数处在index位置，往上继续移动
void heapInsert(int arr[], int index)
{
	//arr[index] = date;
	while (index != 0 && arr[index] > arr[(index - 1) / 2])
	{
		swapArr(arr, index, (index - 1) / 2);
		index = (index - 1) / 2;
	}
}

//调整大堆
//某个数在index位置，能否往下移动
void heapify(int arr[], int index, int heapSize)
{
	int left = index * 2 + 1;  //左子节点
	while (left < heapSize)  //index有孩子
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

//找出数组最大的那个数有多少位
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

//基数排序
//利用10个桶（队列），把个位、十位、百位的数字分别入桶，再出桶，直到最高位为止，数据就有序了
//这里用一个count[10]的数组代替10个桶
//arr[left......right]排序，digit表示该数组中最多有多少位，有多少位就进出桶多少次
void radixSort(int arr[], int left, int right, int digit)
{
	const int radix = 10;
	int *bucket = new int[right - left + 1]; //辅助空间，和arr一样大小

	int j = 0;
	for (int d = 1; d <= digit; d++) //有多少位就进出多少次
	{

		//count[0]表示当前位（d位）是0的数字有多少个
		//count[1]表示当前位（d位）是（0和1）的数字有多少个
		//count[2]表示当前位（d位）是（0、1、2）的数字有多少个
		//count[i]表示当前位（d位）是（0到i）的数字有多少个
		int count[radix] = { 0 };
		for (int i = 0; i < right - left + 1; i++)  //记录当前位的个数
		{
			j = getDigit(arr[i], d);
			count[j]++;
		}

		for (int i = 1; i < radix; i++) //调整count数组，使其变为累加
		{
			count[i] = count[i] + count[i - 1];
		}

		//从右到左把arr的数据导出到辅助空间bucket，模拟队列，先入先出原则
		for (int i = right; i >= left; i--)
		{
			j = getDigit(arr[i], d);
			bucket[count[j] - 1] = arr[i];
			count[j]--;
		}

		for (int i = left, j = 0; i <= right; i++, j++) //bucket导回数据到arr，完成一次基数排序
		{
			arr[i] = bucket[j];
		}
	}
}

//获取当前位数的数字
//d表示位数，1是个位，2是十位，以此类推
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