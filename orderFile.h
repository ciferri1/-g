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

	//更新预约记录
	void updateOrder();

	//记录数据
	map<int, map<string, string>> m_OrderData;

	int m_Size;
};