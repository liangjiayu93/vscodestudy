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
		return "ջ�ѿ�";
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


//��׺���ʽת��׺���ʽ
/*
1����ʼ������ջ�������ջs1�ʹ����м�����ջs2
2��������ɨ����׺���ʽ
3������������ѹջs2
4�����������ʱ���Ƚ�����s1ջ������������ȼ�
	1�����s1Ϊ�գ�����ջ�������Ϊ������ֱ�ӽ��������ջ
	2�����������ȼ���s1ջ��������ߣ����������ջ
	3�����򣬽�s1ջ�������������ѹ��s2�У��ٴ�ת��4.1����s1�е���ջ��������Ƚ�
5����������ʱ
	1������������ţ�����ֱ����ջs1
	2������������ţ�����һ�ε���s1ջ���������ѹ��s2��֪�����������ţ������������Ŷ���
6���ظ�2��5���裬ֱ�����ʽ�����ұ�
7����s1��ʣ�����������ε�����ѹ��s2
8�����ε���s2�е�Ԫ�ز���������������Ϊ��׺���ʽ��Ӧ�ĺ�׺���ʽ
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