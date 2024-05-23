//普通員工文件
#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker
{
public:
	//構造函數
	Employee(int id , string name , int did);
	//顯示個人訊息
	virtual void show_Info();
	//獲取職稱
	virtual string getDepName();
};
