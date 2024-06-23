#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//老闆類
class Boss :public Worker
{
public:
	Boss(int id, string name, int did);
	//顯示個人資訊
	virtual void show_Info();
	//獲取職稱
	virtual string getDepName();
};
