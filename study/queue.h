#pragma once


//循环队列（通过取模的方式来实现）

/*
队列满的条件：(rear+1)%maxsize = front;
队列空的条件：rear = front;
队列有效个数：(rear + maxsize - front)%maxsize; 
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
	int m_front; //队列第一个元素位置
	int m_rear;  //队列最后一个元素的后一个位置，留出一个空间做约定，该空间不使用（为了区分队列满还是空）
	int *m_parry;
};

