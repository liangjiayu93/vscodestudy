#pragma once
#include <iostream>
#include <vector>

using namespace std;
class SparseArry
{
public:
	void PrintVec(vector<vector<int>> &vec);
	int GetValueNumber(vector<vector<int>> &vec);
	void CreatSparseArry(vector<vector<int>> &sourvec, vector<vector<int>> &destvec);
private:
	int m_num;
};