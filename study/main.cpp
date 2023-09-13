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

//ϡ������
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

//ѭ������
void mqueue()
{
	Queue mque(3);
	while (1)
	{
		cout << "������a�������" << std::endl;
		cout << "������g��ȡ����" << std::endl;
		cout << "������p�鿴����" << std::endl;
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
	phero = mherolist.creathero(1,"�ν�","��ʱ��");
	mherolist.addhero(phero);
	phero = mherolist.creathero(14, "����", "����");
	mherolist.addhero(phero);
	phero = mherolist.creathero(13, "³����", "������");
	mherolist.addhero(phero);
	phero = mherolist.creathero(9, "����", "С���");
	mherolist.addhero(phero);

	mherolist.showherolist();
	std::cout << "������=" << mherolist.getlength() << std::endl;
	std::cout << "------------" << std::endl;
	mherolist.reversetlist();
	mherolist.showherolist();
	std::cout << "������=" << mherolist.getlength() << std::endl;
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
	cout << "������=" << result << endl;
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
	cout << "������=" << resultnum << endl;
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
	cout << "����ǰ��";
	mysort::myprint(arr, maxsize);

	//int brr[5] = {4,6,8,5,9};
	//mysort::bubblesort(arr, maxsize);
	//mysort::selectsort(arr, maxsize);
	mysort::heapsort(arr,maxsize);
	cout << "�����";
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
		cout << "FindNodeδ�ҵ�" << targe << endl;
	else
		cout << "FindNode�ҵ���" << temp->number << endl;

	temp = mTree.FindParNode(mTree.GetRootTree(), targe);
	if (temp == nullptr)
		cout << "FindParNodeδ�ҵ����ڵ�" << targe << endl;
	else
		cout << "FindParNode�ҵ��˸��ڵ�" << temp->number << endl;

	mTree.DeleNode(mTree.GetRootTree(), targe);
	cout << "mTree.GetRootTree()" << mTree.GetRootTree() << endl;
	mTree.InorderTraversal(mTree.GetRootTree());
}


//������ʽʹ������
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
	//ϡ������
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
	const char* szChinese = "�����л����񹲺͹� People's Republic of China";
	string ce("��");
	getPinyin(ce.c_str(), pinyinBuf, MAXBUFLEN, &bufLen, enmPinyinMode_AllLower);
	printf("%s %d\n", pinyinBuf, bufLen);
	*/

	int arrtemp[5] = {2,5,3,8,6};


	int *arr = nullptr;
	int len = 0;
	arr = generateRandomArry(30, 10000,len);
	printfArry(arr,len);
	cout <<"-----------ԭʼ����--------------"<<len<< endl;

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
	cout << "----------������--------------" << len << endl;

	for (int i= 0; i < len;)
	{
		cout << arr1[0] << " ";
		arr1[0] = arr1[--len];
		heapify(arr1, 0, len);
	}
	cout << endl;
	cout << "----------��ӡ�������--------------" << len << endl;


	delete[] arr;
	system("pause");
	return 0;
}

