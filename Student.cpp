#include "Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	computerRoom c;
	while (ifs >> c.m_comId && ifs >> c.m_maxNum)
	{
		this->vCom.push_back(c);
	}
	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ��: " << this->m_Name << " ��¼" << endl;
	cout << "\t\t ----------------------------------------\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              1������ԤԼ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              2���鿴�ҵ�ԤԼ           |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              3���鿴����ԤԼ           |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              4��ȡ��ԤԼ               |\n";
	cout << "\t\t|                                        |\n";
	cout << "\t\t|              0��ע����¼               |\n";
	cout << "\t\t ----------------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ��: " << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	
	int date;
	int interval;
	int room;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������!" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ� " << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������! " << endl;
	}

	cout << "����������ԤԼ�Ļ������: " << endl;
	for (vector<computerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "�������: " << it->m_comId << " �������Ϊ�� " << it->m_maxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������!" << endl;
	}
	cout << "ԤԼ�ɹ�,�����" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " " << "interval:" << interval << " " << "stuId:" << this->m_Id << " "
		<< "stuName:" << this->m_Name << " " << "roomId:" << room <<" "<<"status:" << "1" << endl;

	ofs.close();
	

	system("pause");
	system("cls");

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼʱ��: ��" << of.m_OrderData[i]["date"];
			cout << "ʱ��: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "����: " << of.m_OrderData[i]["roomId"];
			string status = " ״̬: ";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��,���δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴�����˵�ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
			cout << i + 1 << "��" << endl;
			cout << " ԤԼʱ��: ��" << of.m_OrderData[i]["date"];
			cout << " ʱ��: " << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ��" << of.m_OrderData[i]["stuId"];
			cout << " ����" << of.m_OrderData[i]["stuName"];
			cout << " ����: " << of.m_OrderData[i]["roomId"];
			string status = " ״̬: ";
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	
	cout << "ԤԼ�ļ�¼���£�" << endl;
	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_OrderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["date"];
				cout << "ʱ��: " << (of.m_OrderData[i]["interval"] == "1"?"����":"����");
				cout << "����: " << of.m_OrderData[i]["roomId"];
				string status = "״̬: ";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "ԤԼ��";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������Ҫȡ����ԤԼ��¼��0������: " << endl;
	int select=0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������! " << endl;
	}
	system("pause");
	system("cls");
}