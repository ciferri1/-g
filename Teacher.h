#pragma once
#include "Identity.h"
#include "orderFile.h"
#include <vector>

class Teacher : public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	//��ʦ�˵�
	void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();



	//��Ա����
	int m_EmpId;//��ʦ���
};
