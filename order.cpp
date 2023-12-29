#include "orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	this->m_Size = 0;
	string date;//日期
	string interval;//时间段
	string stuId;//学号
	string stuName;//姓名
	string roomId;//机房编号
	string status;//预约状态

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs>>roomId && ifs >> status)
	{

		
		string key;
		string value;
		map<string, string> m;

		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1,date.size()-pos);
			m.insert({ key, value });
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0,pos);
			value = interval.substr(pos + 1,interval.size()-pos);
			m.insert({ key, value });
		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1,roomId.size()-pos);
			m.insert({ key, value });
		}
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1,stuId.size()-pos);
			m.insert({ key, value });
		}
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1,stuName.size()-pos);
			m.insert({ key, value });
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1,status.size()-pos);
			m.insert({ key, value });
		}
		this->m_OrderData.insert({this->m_Size, m});
		this->m_Size++;
	}
	ifs.close();
	//for (map<int, map<string, string>>::iterator it = this->m_OrderData.begin(); it != this->m_OrderData.end(); it++)
	//{
	//	cout << "条数为：" << it->first << " value = " << endl;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key = " << mit->first << " value = " << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_OrderData[i]["date"] << " ";
		ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_OrderData[i]["status"] <<endl;
	}
	ofs.close();
}

