#include "Manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//管理员菜单
void Manager::operMenu()
{
	cout << "欢迎管理员: " << this->m_Name << " 登录！" << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              1、添加账号               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              2、查看账号               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              3、查看机房               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              4、清空预约               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              0、注销登录               |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请选择添加账号的类型" << endl;
	cout << "1、学生" << endl;
	cout << "2、教师" << endl;

	ofstream ofs;
	string filename;
	string tip;
	string errortip;
	int select;
	
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号";
		errortip = "学号重复，请重新输入";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "请输入教师编号";
		errortip = "教师编号重复，请重新输入";
	}

	int id;
	string name;
	string pwd;

	ofs.open(filename, ios::out | ios::app);

	
	while (true)
	{
		cout << tip << endl;
		cin >> id;
		if (this->checkRepeat(id,select))
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名: " << endl;
	cin >> name;
	cout << "请输入密码: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生的信息如下" << endl;
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
		{
			cout << "学号: " << it->m_Id << " 姓名: " << it->m_Name << " 密码: " << it->m_Pwd << endl;
		}
	}
	else
	{
		cout << "所有教师的信息如下" << endl;
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			cout << "教师编号: " << it->m_EmpId << " 姓名: " << it->m_Name << " 密码：" << it->m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下: " << endl;
	for (vector<computerRoom>::iterator it = v_com.begin(); it != v_com.end(); it++)
	{
		cout << "机房编号：" << it->m_comId << " 最大容量为：" << it->m_maxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}



//初始化容器
void Manager::initVector()
{
	//清空容器
	this->v_Stu.clear();
	this->v_Tea.clear();
	this->v_com.clear();

	ifstream ifs;
	//读取学生信息
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		ifs.close();
		return;
	}
	
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		v_Stu.push_back(s);
	}
	cout << "当前学生的数量为：" << v_Stu.size() << endl;
	ifs.close();
	//读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	
	Teacher t;

	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		v_Tea.push_back(t);
	}
	cout << "当前老师的数量为：" << v_Tea.size() << endl;
	ifs.close();

	//读取机房信息
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom c;

	while (ifs >> c.m_comId && ifs >> c.m_maxNum)
	{
		v_com.push_back(c);
	}
	cout << "机房数量为：" << v_com.size() << endl;
	ifs.close();

}

//查重
bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
		{
			if (it->m_Id == id) return true;
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			if (it->m_EmpId == id) return true;
		}
	}

	return false;
}