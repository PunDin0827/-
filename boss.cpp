#include "Boss.h"

//�c�y���
Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
}

//��ܭӤH�T��
void Boss::show_Info()
{
	cout << "���u�s��" << this->m_Id
		<< "\t���u�m�W" << this->m_Name
		<< "\t¾��" << this->getDepName()
		<< "\t¾�d�G�޲z���q�Ҧ��ƪ�" << endl;
}
//���¾��
string Boss::getDepName()
{
	return string("����");
}