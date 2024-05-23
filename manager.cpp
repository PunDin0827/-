#include "manager.h"

//構造函數
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

//顯示個人訊息
void Manager :: show_Info()
{
	cout << "員工編號" << this->m_Id
		<< "\t員工姓名" << this->m_Name
		<< "\t職稱" << this->getDepName()
		<< "\t職責：完成老闆交辦任務，並且下發任務給一般員工" << endl;
}
//獲取職稱
string Manager ::getDepName()
{
	return string("經理");
}