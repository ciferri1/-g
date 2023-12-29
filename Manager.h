#pragma once
#include "Identity.h"
#include <fstream>
#include <vector>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "computerRoom.h"

class Manager : public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//管理员菜单
	void operMenu();

	//添加账号
	void addPerson();

	//查重
	bool checkRepeat(int id, int type);

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();




	//成员属性
	vector<Student> v_Stu;
	vector<Teacher> v_Tea;
	vector<computerRoom> v_com;
};
