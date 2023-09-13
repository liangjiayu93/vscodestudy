#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//逆波兰计算器
//1+((2+3)*4)-5=16 这是中缀表达式，不利于计算机处理，123+4*+5- 后缀表达式利于处理，也叫逆波兰表达式

//逆波兰计算器
/*
准备一个栈，存数字
遍历逆波兰表达式，遇到数字压栈，遇到符号弹出两个数字运算
注意：第一个出栈的是符号右边的数字，所以-和/是第二个数字在前
计算结果压栈，直到运算结束，最后一个数字就是结果
*/
class ReversePolish
{
public:
	ReversePolish();
	virtual ~ReversePolish();
	int Calculation(vector<string> &vec);
	//分割字符串
	void Split(string postfix, char separator, vector<string> &vec);
	//string转int
	int StringToInt(string str);
};


class Stack
{
public:
	Stack(int maxsize);
	virtual ~Stack();
	bool isFull();
	//判断栈是否为空
	bool isEmpty();
	//返回栈顶元素
	string getTop();
	//入栈
	bool Push(string str);
	//出栈
	string Pop();
	
private:
	string *index; //栈指针
	int m_top; //栈顶位置
	int m_maxsize;
};


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

//1+((2+3)*4)-5=16 
class PostfixExpression
{
public:
	PostfixExpression(int maxsize);
	virtual ~PostfixExpression();
	string Process(string str);
	int Operatorlevel(char oper);
private:
	int maxsize;
	Stack *S1; //运算符
	Stack *S2; //中间结果
};