#pragma once
#include<iostream>
#include<string>


using namespace std;

//員工抽象類別
class Worker
{
public:
	//顯示個人訊息
	virtual void show_Info() = 0;
	//獲取職稱
	virtual string getDepName() = 0;
	//員工編號
	int m_Id;
	//員工姓名
	string m_Name;
	//部門編號
	int m_DepId;
};