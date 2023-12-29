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
	//�˵�����
	void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴�����˵�ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();


	//ѧ��ѧ��
	int m_Id;
	vector<computerRoom> vCom;
};