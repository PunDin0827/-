#include "employee.h"
#include <iostream>
//構造函數
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

	//顯示個人訊息
	void Employee:: show_Info()
	{
		cout << "員工編號" << this->m_Id
			<< "\t員工姓名" << this->m_Name
			<< "\t職稱" << this->getDepName()
			<< "\t職責：完成經理交辦任務" << endl;
	}
	//獲取職稱
	string Employee::getDepName()
	{
		return string("員工");
	}
