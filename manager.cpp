#include "manager.h"

//�c�y���
Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

//��ܭӤH�T��
void Manager :: show_Info()
{
	cout << "���u�s��" << this->m_Id
		<< "\t���u�m�W" << this->m_Name
		<< "\t¾��" << this->getDepName()
		<< "\t¾�d�G������������ȡA�åB�U�o���ȵ��@����u" << endl;
}
//���¾��
string Manager ::getDepName()
{
	return string("�g�z");
}