#pragma once
#include "Identity.h"
#include "orderFile.h"
#include <vector>

class Teacher : public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	//教师菜单
	void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();



	//成员属性
	int m_EmpId;//教师编号
};
