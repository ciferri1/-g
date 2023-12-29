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

	//����Ա�˵�
	void operMenu();

	//����˺�
	void addPerson();

	//����
	bool checkRepeat(int id, int type);

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();




	//��Ա����
	vector<Student> v_Stu;
	vector<Teacher> v_Tea;
	vector<computerRoom> v_com;
};
