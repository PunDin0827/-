#pragma once
#include<iostream>
#include<string>


using namespace std;

//���u��H���O
class Worker
{
public:
	//��ܭӤH�T��
	virtual void show_Info() = 0;
	//���¾��
	virtual string getDepName() = 0;
	//���u�s��
	int m_Id;
	//���u�m�W
	string m_Name;
	//�����s��
	int m_DepId;
};