#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"

class Identity
{
public:
	virtual void operMenu() = 0;

	//��Ա����
	string m_Name;//�û���
	string m_Pwd;//����
};