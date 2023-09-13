#pragma once
#include <string>

static struct Hero
{
	int number;
	std::string name;
	std::string nickname;
	struct Hero *next;
}hero;

//��ͷ�ڵ㣬˳���������
class Herolist
{
public:
	Herolist();
	~Herolist();
	struct Hero* creathero(int number,std::string name,std::string nickname);
	void addhero(struct Hero *data);
	void showhero(int number);
	void showherolist();
	void deletehero(int number);
	int getlength();
	struct Hero* reversetlist();

private:
	struct Hero *phead;
};



