#include <iostream>
#include "herolist.h"

Herolist::Herolist()
{
	phead = new struct Hero;
	phead->number = 0;
	phead->next = NULL;
}

Herolist::~Herolist()
{
	struct Hero *temp;
	while (phead != NULL)
	{
		temp = phead->next;
		delete phead;
		phead = temp;
	}
}

struct Hero* Herolist::creathero(int number, std::string name, std::string nickname)
{
	struct Hero *p = new struct Hero;
	p->number = number;
	p->name = name;
	p->nickname = nickname;
	p->next = NULL;
	return p;
}

//Ë³Ðò²åÈë
void Herolist::addhero(struct Hero *data)
{
	if (data == NULL)
		return;
	struct Hero *temp = phead;
	struct Hero *front = NULL;
	while (temp != NULL && temp->number < data->number)
	{
		front = temp;
		temp = temp->next;
	}
	if (temp != NULL && temp->number == data->number)
		return;
	front->next = data;
	data->next = temp;
}

void Herolist::showhero(int number)
{
	struct Hero* temp = phead;
	while (temp != NULL)
	{
		if (temp->number == number)
		{
			std::cout << "Ó¢ÐÛºÅÂë£º" << temp->number << " Ãû×Ö£º" << temp->name << " ´ÂºÅ£º" << temp->nickname << std::endl;
			return;
		}
		temp = temp->next;
	}
	std::cout << "Ã»ÓÐ¸ÃÓ¢ÐÛ!" << std::endl;
	return;
} 

void Herolist::showherolist()
{
	struct Hero* temp = phead->next;
	while (temp != NULL)
	{
		std::cout << "Ó¢ÐÛºÅÂë£º" << temp->number << " Ãû×Ö£º" << temp->name << " ´ÂºÅ£º" << temp->nickname << std::endl;
		temp = temp->next;
	}
	return;
}
void Herolist::deletehero(int number)
{
	struct Hero* temp = phead;
	struct Hero* front = NULL;
	while (temp != NULL)
	{
		if (temp->number == number)
		{
			front->next = temp->next;
			delete temp;
			return;
		}
		front = temp;
		temp = temp->next;
	}
	std::cout << "Ã»ÓÐ¸ÃÓ¢ÐÛ£¡" << std::endl;
}

int Herolist::getlength()
{
	struct Hero *temp = phead->next;
	if (temp == NULL)
	{
		return 0;
	}
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

//µ¥Á´±í·´×ª
struct Hero* Herolist::reversetlist()
{
	if (phead == NULL)
		return phead;
	struct Hero *temp = phead->next;
	struct Hero *rear = NULL;
	phead->next = NULL;
	while (temp != NULL)
	{
		rear = temp->next;
		temp->next = phead->next;
		phead->next = temp;
		temp = rear;
	}
	return phead;
}