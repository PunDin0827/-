//���q���u���
#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//�c�y���
	Employee(int id , string name , int did);
	//��ܭӤH�T��
	virtual void show_Info();
	//���¾��
	virtual string getDepName();
};
