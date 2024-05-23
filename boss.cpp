#include "Boss.h"

//構造函數
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

//顯示個人訊息
void Boss::show_Info()
{
	cout << "員工編號" << this->m_Id
		<< "\t員工姓名" << this->m_Name
		<< "\t職稱" << this->getDepName()
		<< "\t職責：管理公司所有事物" << endl;
}
//獲取職稱
string Boss::getDepName()
{
	return string("老闆");
}