#include "reversepolish.h"


Stack::Stack(int maxsize)
{
	index = new string[maxsize];
	m_top = -1;
	m_maxsize = maxsize;
}


Stack::~Stack()
{
	delete[] index;
}

bool Stack::isEmpty()
{
		return m_top>=0?false:true;
}

string Stack::getTop()
{
	if (!isEmpty())
		return *(index + m_top);
}

string Stack::Pop()
{
	if (isEmpty())
		return "栈已空";
	return *(index + m_top--);
}

bool Stack::isFull()
{
	return m_maxsize-1 == m_top ? true : false;
}

bool Stack::Push(string str)
{
	if (isFull())
		return false;
	m_top++;
	*(index + m_top) = str;
	return true;
}

ReversePolish::ReversePolish()
{}

ReversePolish::~ReversePolish()
{}

//postfix="1 2 3 + 4 * + 5 -"
int ReversePolish::Calculation(vector<string> &vec)
{
	int result = 0;
	int num1 = 0;
	int num2 = 0;
	int vec_size = vec.size();
	Stack calcustack(vec_size);
	for (int i = 0; i < vec_size; i++)
	{
		if (vec[i][0] >= '0' && vec[i][0] <= '9')
		{
			calcustack.Push(vec[i]);
		}
		else if (!vec[i].compare("+"))
		{
			num1 = StringToInt(calcustack.Pop());
			num2 = StringToInt(calcustack.Pop());
			result = num1 + num2;
			calcustack.Push(to_string(result));
		}
		else if (!vec[i].compare("-"))
		{
			num1 = StringToInt(calcustack.Pop());
			num2 = StringToInt(calcustack.Pop());
			result = num2 - num1;
			calcustack.Push(to_string(result));
		}
		else if (!vec[i].compare("*"))
		{
			num1 = StringToInt(calcustack.Pop());
			num2 = StringToInt(calcustack.Pop());
			result = num1 * num2;
			calcustack.Push(to_string(result));
		}
		else if (!vec[i].compare("/"))
		{
			num1 = StringToInt(calcustack.Pop());
			num2 = StringToInt(calcustack.Pop());
			result = num2 / num1;
			calcustack.Push(to_string(result));
		}
	}
	result = StringToInt(calcustack.Pop());

	return result;
}

int ReversePolish::StringToInt(string str)
{
	int result = 0;
	int str_size = str.size();
	for (string::iterator it = str.begin();it!=str.end();it++)
	{
		if (*it >= '0' && *it <= '9')
		{
			int res = *it - '0';
			result = result * 10 + res;
		}
	}
	return result;
}

void ReversePolish::Split(string postfix, char separator, vector<string> &vec)
{
	string temp = postfix;
	//string::iterator it = postfix.begin();
	for (int i = 0; i < temp.size();)
	{
		
		int flag = temp.find(separator);
		if (flag != string::npos)
		{
			vec.push_back(temp.substr(0,flag));
		}
		else
		{
			vec.push_back(temp);
			break;
		}
		temp = temp.substr(flag + 1);
		i = 0;
	}
}

PostfixExpression::PostfixExpression(int maxsize)
{
	this->maxsize = maxsize;
	S1 = new Stack(maxsize);
	S2 = new Stack(maxsize);
}

PostfixExpression::~PostfixExpression()
{
	delete S1;
	delete S2;
}


//中缀表达式转后缀表达式
/*
1、初始化两个栈：运算符栈s1和储存中间结果的栈s2
2、从左到右扫描中缀表达式
3、遇到操作数压栈s2
4、遇到运算符时，比较其与s1栈顶运算符的优先级
	1、如果s1为空，或者栈顶运算符为（，则直接将运算符入栈
	2、否则，若优先级比s1栈顶运算符高，则将运算符入栈
	3、否则，将s1栈顶运算符弹出并压入s2中，再次转到4.1中与s1中的新栈顶运算符比较
5、遇到括号时
	1、如果是左括号（，则直接入栈s1
	2、如果是右括号），则一次弹出s1栈顶运算符并压入s2，知道出现左括号（，并把左括号丢掉
6、重复2到5步骤，直到表达式的最右边
7、将s1中剩余的运算符依次弹出并压入s2
8、依次弹出s2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式
*/

//str = 1+((2+3)*4)-5=16  -5+*4+321
string PostfixExpression::Process(string str)
{
	string temp;
	int ifront = 0;
	int iafter = 0;
	string::iterator itfront = str.begin();
	string::iterator itafter = str.begin();

	std::cout << "str = " << str << endl;

	for (; itfront != str.end(); itfront++, ifront++)
	{
		std::cout << "ifront = " << ifront << endl;
		std::cout << "iafter = " << iafter << endl;
		if (*itfront >= '0' && *itfront <= '9')
		{
			if (itfront + 1 == str.end())
			{
				if(ifront == iafter)
					S2->Push(str.substr(iafter, 1));
				else
					S2->Push(str.substr(iafter, ifront - iafter + 1));
			}
			else if (*(itfront + 1) < '0' || *(itfront + 1) > '9')
			{
				S2->Push(str.substr(iafter, ifront - iafter + 1));
				iafter = ifront;
				iafter++;
			}
		}

		if (*itfront == '+'|| *itfront == '-' || *itfront == '*' || *itfront == '/')
		{

			if (S1->isEmpty() || S1->getTop() == "(")
			{
				S1->Push(string(1,*itfront));
				iafter++;
			}
			else if (Operatorlevel(*itfront) >= Operatorlevel(S1->getTop()[0]) || S1->getTop()=="(")
			{
				S1->Push(string(1,*itfront));
				iafter++;
			}
			else
			{
				//S2->Push(S1->Pop());
				while (!S1->isEmpty() && Operatorlevel(S1->getTop()[0]) !=-1 && Operatorlevel(*itfront) < Operatorlevel(S1->getTop()[0]))
				{
					string tt = S1->Pop();
					S2->Push(tt);
				}
				S1->Push(string(1,*itfront));
				iafter++;
			}
		}
		if (*itfront == '(')
		{
			cout << "(  = " << *itfront << endl;
			S1->Push(string(1,*itfront));
			iafter++;
		}
		if (*itfront == ')')
		{
			cout << ")  = " << *itfront << endl;

			while (!S1->isEmpty() && '(' != S1->getTop()[0])
			{
				string tt = S1->Pop();
				cout << ") before = " << tt << endl;
				S2->Push(tt);
			}
			S1->Pop();
			iafter++;
		}
	}

	while (!S1->isEmpty())
	{
		string tt = S1->Pop();
		S2->Push(tt);
	}

	//std::cout << "S2 = ";
	//while (!S2->isEmpty())
	//{
	//	std::cout << S2->Pop()<<" ";
	//}
	//std::cout << endl;

	while (!S2->isEmpty())
	{
		temp += S2->Pop() + " ";
	}
	//temp = temp.substr(temp.size() - 1);
	std::cout << "temp = " << temp << endl;
	string result(temp.rbegin(), temp.rend());
	std::cout << "result" << result << endl;
	return result;
}

int PostfixExpression::Operatorlevel(char oper)
{
	if (oper == '+' || oper == '-')
		return 0;
	if (oper == '*' || oper == '/')
		return 1;
	if (oper == '(')
		return -1;
}