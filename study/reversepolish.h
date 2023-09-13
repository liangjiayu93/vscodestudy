#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//�沨��������
//1+((2+3)*4)-5=16 ������׺���ʽ�������ڼ��������123+4*+5- ��׺���ʽ���ڴ���Ҳ���沨�����ʽ

//�沨��������
/*
׼��һ��ջ��������
�����沨�����ʽ����������ѹջ���������ŵ���������������
ע�⣺��һ����ջ���Ƿ����ұߵ����֣�����-��/�ǵڶ���������ǰ
������ѹջ��ֱ��������������һ�����־��ǽ��
*/
class ReversePolish
{
public:
	ReversePolish();
	virtual ~ReversePolish();
	int Calculation(vector<string> &vec);
	//�ָ��ַ���
	void Split(string postfix, char separator, vector<string> &vec);
	//stringתint
	int StringToInt(string str);
};


class Stack
{
public:
	Stack(int maxsize);
	virtual ~Stack();
	bool isFull();
	//�ж�ջ�Ƿ�Ϊ��
	bool isEmpty();
	//����ջ��Ԫ��
	string getTop();
	//��ջ
	bool Push(string str);
	//��ջ
	string Pop();
	
private:
	string *index; //ջָ��
	int m_top; //ջ��λ��
	int m_maxsize;
};


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
	Stack *S1; //�����
	Stack *S2; //�м���
};