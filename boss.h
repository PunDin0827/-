#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//老闆類
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	virtual void show_Info();
	virtual string getDepName();
};
