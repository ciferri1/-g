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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "��������Ľ�ʦ��ţ�" << endl;
		cin >> id;
	}

	cout << "����������û�����" << endl;
	cin >> name;
	cout << "������������룺" << endl;
	cin >> pwd;


	if (type == 1)
	{
		//ѧ����¼�ӿ�
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��֤��¼�ɹ���" << endl;
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
		//��ʦ��¼�ӿ�
		int fid;
		string fname;
		string fpwd;

		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��֤��¼�ɹ���" << endl;
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
		//����Ա��¼�ӿ�
	
		string fname;
		string fpwd;

		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��" << endl;
	
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
			//����˺�
			man->addPerson();
		}
		else if (select == 2)
		{
			//�鿴�˺�
			man->showPerson();
		}
		else if (select == 3)
		{
			//�鿴������Ϣ
			man->showComputer();
		}
		else if (select == 4)
		{
			//���ԤԼ��¼
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2)
		{
			//�鿴�ҵ�ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			//�鿴�����˵�ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			//ȡ��ԤԼ
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
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
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
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
		cout << "--------------------- ��ӭʹ�û���ԤԼϵͳ ---------------------" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t ----------------------------------------\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              1��ѧ��                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              2����ʦ                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              3������Ա                 |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t|              0���˳�                   |\n";
		cout << "\t\t|                                        |\n";
		cout << "\t\t ----------------------------------------\n";
		cout << "����������ѡ��" << endl;

		cin >> select;

		switch (select)
		{
		case 1: LogIn(STUDENT_FILE, select);      //ѧ�����
			break;
		case 2: LogIn(TEACHER_FILE, select);      //��ʦ���
			break;
		case 3: LogIn(ADMIN_FiLE, select);		  //����Ա���
			break;
		case 0:									  //�˳�����
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}