#include "employee.h"
#include <iostream>
//�c�y���
Employee::Employee(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

	//��ܭӤH�T��
	void Employee:: show_Info()
	{
		cout << "���u�s��" << this->m_Id
			<< "\t���u�m�W" << this->m_Name
			<< "\t¾��" << this->getDepName()
			<< "\t¾�d�G�����g�z������" << endl;
	}
	//���¾��
	string Employee::getDepName()
	{
		return string("���u");
	}
