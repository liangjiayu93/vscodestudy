#include "queue.h"
#include <iostream>

Queue::Queue(int maxsize):m_maxsize(maxsize), m_front(0),m_rear(0)
{
	m_parry = new int[m_maxsize];
}

Queue::~Queue()
{
	delete[] m_parry;
}

bool Queue::isEmpty()
{
	if (m_front == m_rear)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if ((m_rear + 1)%m_maxsize == m_front)
		return true;
	else
		return false;
}

void Queue::addQueue(int data)
{
	if (isFull())
	{
		std::cout << "队列已满！" << std::endl;
		return;
	}
	m_parry[m_rear] = data;
	m_rear = (m_rear + 1) % m_maxsize;
}

int Queue::getQueue()
{
	if(isEmpty())
	{
		std::cout << "队列为空！" << std::endl;
		return -1;
	}
	int data = m_parry[m_front];
	m_front = (m_front + 1) % m_maxsize;
	return data;
}

void Queue::showQueue()
{
	if(isEmpty())
	{
		std::cout << "队列为空！" << std::endl;
		return;
	}
	int num = (m_rear + m_maxsize - m_front) % m_maxsize;
	for (int i = 0; i < num; i++)
	{
		std::cout << m_parry[(m_front + i)% m_maxsize] << std::endl;
	}
}