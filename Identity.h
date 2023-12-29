#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"

class Identity
{
public:
	virtual void operMenu() = 0;

	//成员属性
	string m_Name;//用户名
	string m_Pwd;//密码
};