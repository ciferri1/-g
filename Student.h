#pragma once;
#include <vector>
#include <fstream>
#include "Identity.h"
#include "computerRoom.h"
#include "orderFile.h";

class Student : public Identity
{
public:
	Student();

	Student(int id, string name, string pwd);
	//菜单界面
	void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有人的预约
	void showAllOrder();
	//取消预约
	void cancelOrder();


	//学生学号
	int m_Id;
	vector<computerRoom> vCom;
};