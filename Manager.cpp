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

//����Ա�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա: " << this->m_Name << " ��¼��" << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              1������˺�               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              2���鿴�˺�               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              3���鿴����               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              4�����ԤԼ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              0��ע����¼               |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "��ѡ������˺ŵ�����" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;

	ofstream ofs;
	string filename;
	string tip;
	string errortip;
	int select;
	
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ��";
		errortip = "ѧ���ظ�������������";
	}
	else
	{
		filename = TEACHER_FILE;
		tip = "�������ʦ���";
		errortip = "��ʦ����ظ�������������";
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

	cout << "����������: " << endl;
	cin >> name;
	cout << "����������: " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ������Ϣ����" << endl;
		for (vector<Student>::iterator it = v_Stu.begin(); it != v_Stu.end(); it++)
		{
			cout << "ѧ��: " << it->m_Id << " ����: " << it->m_Name << " ����: " << it->m_Pwd << endl;
		}
	}
	else
	{
		cout << "���н�ʦ����Ϣ����" << endl;
		for (vector<Teacher>::iterator it = v_Tea.begin(); it != v_Tea.end(); it++)
		{
			cout << "��ʦ���: " << it->m_EmpId << " ����: " << it->m_Name << " ���룺" << it->m_Pwd << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����: " << endl;
	for (vector<computerRoom>::iterator it = v_com.begin(); it != v_com.end(); it++)
	{
		cout << "������ţ�" << it->m_comId << " �������Ϊ��" << it->m_maxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}



//��ʼ������
void Manager::initVector()
{
	//�������
	this->v_Stu.clear();
	this->v_Tea.clear();
	this->v_com.clear();

	ifstream ifs;
	//��ȡѧ����Ϣ
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		ifs.close();
		return;
	}
	
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		v_Stu.push_back(s);
	}
	cout << "��ǰѧ��������Ϊ��" << v_Stu.size() << endl;
	ifs.close();
	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	
	Teacher t;

	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		v_Tea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << v_Tea.size() << endl;
	ifs.close();

	//��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	computerRoom c;

	while (ifs >> c.m_comId && ifs >> c.m_maxNum)
	{
		v_com.push_back(c);
	}
	cout << "��������Ϊ��" << v_com.size() << endl;
	ifs.close();

}

//����
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