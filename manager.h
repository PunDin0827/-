#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//�g�z���O
class Manager :public Worker
{
public:
	//�c�y���
	Manager(int id, string namel, int did);

	//��ܭӤH�T��
	virtual void show_Info();
	//���¾��
	virtual string getDepName() ;
};