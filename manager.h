#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//經理類別
class Manager :public Worker
{
public:
	//構造函數
	Manager(int id, string namel, int did);

	//顯示個人訊息
	virtual void show_Info();
	//獲取職稱
	virtual string getDepName() ;
};