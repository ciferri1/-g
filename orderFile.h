#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"

class OrderFile
{
public:
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼����
	map<int, map<string, string>> m_OrderData;

	int m_Size;
};