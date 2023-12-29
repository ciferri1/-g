#include <iostream>
#include <string>
#include <fstream>
#include "Identity.h"
#include "Manager.h"
#include "Teacher.h"
#include "Student.h"
#include "globalFile.h"

using namespace std;

void ManagerMenu(Identity*& manager);
void StudentMenu(Identity*& student);
void TeacherMenu(Identity*& teacher);

void LogIn(string fileName, int type)
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的教师编号：" << endl;
		cin >> id;
	}

	cout << "请输入你的用户名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;


	if (type == 1)
	{
		//学生登录接口
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录接口
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录接口
	
		string fname;
		string fpwd;

		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败" << endl;
	
	return;
}


void ManagerMenu(Identity* &manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select;
		cin >> select;

		if (select == 1)
		{
			//添加账号
			man->addPerson();
		}
		else if (select == 2)
		{
			//查看账号
			man->showPerson();
		}
		else if (select == 3)
		{
			//查看机房信息
			man->showComputer();
		}
		else if (select == 4)
		{
			//清空预约记录
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void StudentMenu(Identity* &student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;
		int select;
		cin >> select;

		if (select == 1)
		{
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//查看我的预约
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//查看所有人的预约
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//取消预约
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//----------------------------------------------------------------------------------------------------------------------

int main()
{
	int select;
	while (true)
	{
		cout << "--------------------- 欢迎使用机房预约系统 ---------------------" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              1、学生                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              2、老师                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              3、管理员                 |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              0、退出                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "请输入您的选择" << endl;

		cin >> select;

		switch (select)
		{
		case 1: LogIn(STUDENT_FILE, select);      //学生身份
			break;
		case 2: LogIn(TEACHER_FILE, select);      //老师身份
			break;
		case 3: LogIn(ADMIN_FiLE, select);		  //管理员身份
			break;
		case 0:									  //退出程序
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}