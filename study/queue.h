#pragma once


//ѭ�����У�ͨ��ȡģ�ķ�ʽ��ʵ�֣�

/*
��������������(rear+1)%maxsize = front;
���пյ�������rear = front;
������Ч������(rear + maxsize - front)%maxsize; 
*/

class Queue
{
public:
	Queue(int maxsize);
	~Queue();

	bool isEmpty();
	bool isFull();
	void addQueue(int data);
	int getQueue();
	void showQueue();

private:
	int m_maxsize;
	int m_front; //���е�һ��Ԫ��λ��
	int m_rear;  //�������һ��Ԫ�صĺ�һ��λ�ã�����һ���ռ���Լ�����ÿռ䲻ʹ�ã�Ϊ�����ֶ��������ǿգ�
	int *m_parry;
};

