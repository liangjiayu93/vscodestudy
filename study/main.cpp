#include "sparsearray.h"
#include "queue.h"
#include "herolist.h"
#include "reversepolish.h"
#include "sort.h"
#include <time.h>
#include "tree.h"
#include <regex>
#include "pinyin.h"  
#include "algorithm.h"

void bubblesort(int arr[], int arrsize)
{
	cout << "arrsize=" << arrsize << endl;

	for (int i = 0; i < arrsize - 1; i++)
	{
		for (int j = 0; j < arrsize -i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
}

//稀疏数组
void sparse()
{
	vector<vector<int>> vtest(5);
	for (int i = 0; i < 5; i++)
	{
		vtest[i].resize(5);
	}
	vtest[0][2] = 1;
	vtest[0][4] = 3;
	vtest[1][3] = 2;
	SparseArry sparse;
	int num = 0;
	sparse.PrintVec(vtest);
	num = sparse.GetValueNumber(vtest);
	cout << num << endl;
	cout << "-----------" << endl;
	vector<vector<int>> vsparsearry(num + 1);
	for (int i = 0; i < num + 1; i++)
	{
		vsparsearry[i].resize(3);
	}
	sparse.CreatSparseArry(vtest, vsparsearry);
	sparse.PrintVec(vsparsearry);
}

//循环队列
void mqueue()
{
	Queue mque(3);
	while (1)
	{
		cout << "请输入a添加数据" << std::endl;
		cout << "请输入g获取数据" << std::endl;
		cout << "请输入p查看队列" << std::endl;
		char a;
		cin >> a;
		int data = 0;
		switch (a)
		{
		case 'a':
			cin >> data;
			mque.addQueue(data);
			break;
		case 'g':
			data = mque.getQueue();
			break;
		case 'p':
			mque.showQueue();
			break;
		default:
			return;
		}
	}
	
}


void mlist()
{
	Herolist mherolist;
	struct Hero* phero;
	phero = mherolist.creathero(1,"宋江","及时雨");
	mherolist.addhero(phero);
	phero = mherolist.creathero(14, "武松", "行者");
	mherolist.addhero(phero);
	phero = mherolist.creathero(13, "鲁智深", "花和尚");
	mherolist.addhero(phero);
	phero = mherolist.creathero(9, "花荣", "小李广");
	mherolist.addhero(phero);

	mherolist.showherolist();
	std::cout << "链表长度=" << mherolist.getlength() << std::endl;
	std::cout << "------------" << std::endl;
	mherolist.reversetlist();
	mherolist.showherolist();
	std::cout << "链表长度=" << mherolist.getlength() << std::endl;
}


void mstack()
{
	Stack mstack(3);
	
	mstack.Push("liang");
	mstack.Push("jia");
	mstack.Push("yu");
	mstack.Push("yu1111");

	for (int i = 0; i < 10; i++)
	{
		if (mstack.isEmpty())
			break;
		else
		{
			std::cout << mstack.Pop() << " ";
		}
	}
	std::cout << std::endl;
	
}

void mreversepolish()
{
	ReversePolish mmreversepolish;


	string postfix = "1 2 3 + 4 * + 5 - 4 /";
	//string postfix = "1 2 +";
	vector<string> vec;
	mmreversepolish.Split(postfix,' ',vec);
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int result = mmreversepolish.Calculation(vec);
	cout << "计算结果=" << result << endl;
}

void mpostfixexpression()
{
	string postfix = "11+((2+3)*4)-5";
	//string postfix = "1+(2+3)*4-5";
	PostfixExpression mmpostfixexpression(postfix.size());
	string result = mmpostfixexpression.Process(postfix);
	cout << "mpostfixexpression result = " << result << endl;


	ReversePolish mmreversepolish;
	vector<string> vec;
	mmreversepolish.Split(result, ' ', vec);
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int resultnum = mmreversepolish.Calculation(vec);
	cout << "计算结果=" << resultnum << endl;
}

/*
void myprint(int arr[], int maxsize)
{
	int len = maxsize;
	cout << "[";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout <<"]"<< endl;
}
*/
void my_sort()
{
	int maxsize = 10;
	int *arr = new int[maxsize];
	srand(time(0));
	for (int i = 0; i < maxsize; i++)
	{
		arr[i] = rand() % maxsize;
	}
	cout << "排序前：";
	mysort::myprint(arr, maxsize);

	//int brr[5] = {4,6,8,5,9};
	//mysort::bubblesort(arr, maxsize);
	//mysort::selectsort(arr, maxsize);
	mysort::heapsort(arr,maxsize);
	cout << "排序后：";
	mysort::myprint(arr, maxsize);
}

void my_tree()
{
	struct treeNode arr[8];
	arr[0].number = 7;
	arr[1].number = 4;
	arr[2].number = 20;
	arr[3].number = 2;
	arr[4].number = 6;
	arr[5].number = 11;
	arr[6].number = 22;
	arr[7].number = 5;

	SearchTree mTree;
	for (int i = 0; i < 8; i++)
	{
		mTree.CreatSearchTree(arr[i]);
	}
	cout << "mTree.GetRootTree()" << mTree.GetRootTree() << endl;
	mTree.InorderTraversal(mTree.GetRootTree());

	struct treeNode* temp = nullptr;
	int targe = 7;
	temp = mTree.FindNode(mTree.GetRootTree(), targe);
	if (temp == nullptr)
		cout << "FindNode未找到" << targe << endl;
	else
		cout << "FindNode找到了" << temp->number << endl;

	temp = mTree.FindParNode(mTree.GetRootTree(), targe);
	if (temp == nullptr)
		cout << "FindParNode未找到父节点" << targe << endl;
	else
		cout << "FindParNode找到了父节点" << temp->number << endl;

	mTree.DeleNode(mTree.GetRootTree(), targe);
	cout << "mTree.GetRootTree()" << mTree.GetRootTree() << endl;
	mTree.InorderTraversal(mTree.GetRootTree());
}


//正则表达式使用例子
int myregex(string &expel, string &desc)
{
	std::cout << "myregex expel=" << expel << std::endl;
	smatch ms;
	bool ret = std::regex_match(expel,ms,regex("(.*)count(.*\\D+)(\\d+)(.*)"));
	std::cout << "ret="<< ret << std::endl;
	if (ret)
	{
		std::cout << ms.str() << std::endl;
		std::cout << ms.length() << std::endl;
	}
	for(int i = 0; i < ms.size(); i++)
	{
		std::cout << i<<"="<<ms[i].str() << std::endl;
	}

	int num = stoi(ms[3]);
	std::cout <<"num="<< num << std::endl;

	std::cout << "-------------"<< std::endl;

	string datatype;
	smatch ms1;
	string ee = "datatype=\\\"8\\\"> datai";

	//string ee = "<aatalist datatype=\"84\"> dataid=\"d5";
	ret = std::regex_match(ee, ms1, regex("datatype(.*\\D+)(\\d+)(.*)"));
	std::cout << "ret=" << ret << std::endl;
	if (ret)
	{
		std::cout << "ms[0]=" << ms1[0] << std::endl;
		std::cout << "ms[1]=" << ms1[1] << std::endl;
		std::cout << "ms[2]=" << ms1[2] << std::endl;
		std::cout << "ms[3]=" << ms1[3] << std::endl;
		datatype = ms1[2];
		std::cout << "datatype=" << datatype << std::endl;
	}

	return 0;
}



int main()
{
	//稀疏数组
	//sparse();
	//mqueue();
	//mlist();

	//mstack();
	//mreversepolish();
	//mpostfixexpression();


	//my_sort();

	//my_tree();

	//string expel = "<aatalist count=\"345\">ssssss";
	//std::cout << "expel=" << expel << std::endl;

	//string desc;
	//myregex(expel, desc);
	//std::cout << "desc=" << desc << std::endl;

	/*
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << rand() << std::endl;
	}
	
	*/

	/*
	uint32_t bufLen = 0;
	char pinyinBuf[MAXBUFLEN] = { 0 };
	const char* szChinese = "测试中华人民共和国 People's Republic of China";
	string ce("马");
	getPinyin(ce.c_str(), pinyinBuf, MAXBUFLEN, &bufLen, enmPinyinMode_AllLower);
	printf("%s %d\n", pinyinBuf, bufLen);
	*/

	int arrtemp[5] = {2,5,3,8,6};


	int *arr = nullptr;
	int len = 0;
	arr = generateRandomArry(30, 10000,len);
	printfArry(arr,len);
	cout <<"-----------原始数据--------------"<<len<< endl;

	//int arrt[5] = { 3,5,2};
	//printfArry(arrt, 3);
	//process(arr,0,len-1);
	//quickSort(arr, 0, len - 1);
	//printfArry(arr, len);

	int arr1[30] = { 0 };
	for (int i = 0; i < len; i++)
	{
		heapInsert(arr1, i, arr[i]);
	}
	printfArry(arr1, len);
	cout << "----------插入大堆--------------" << len << endl;

	for (int i= 0; i < len;)
	{
		cout << arr1[0] << " ";
		arr1[0] = arr1[--len];
		heapify(arr1, 0, len);
	}
	cout << endl;
	cout << "----------打印大堆排序--------------" << len << endl;


	delete[] arr;
	system("pause");
	return 0;
}

