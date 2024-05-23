#pragma once
#include <iostream>
#include "worker.h"
#include "manager.h"
#include "boss.h"
#include "employee.h"
#include <fstream>
#define FILENAME "empFILE.txt"
using namespace std;

class workerManager
{
public:
	workerManager();

	void show_menu();//顯示菜單
	void exitSystem(); //退出

	//紀錄員工人數
	int m_EmpNum;

	//員工陣列指針
	Worker** m_EmpArray;

	//增加員工
	void Add_Emp();

	//保存文件
	void save();

	//判斷文件是否為空值
	bool m_fileEmpty;

	//統計文件人數
	int get_EmpNum();

	//初始化員工
	void init_Emp();

	//顯示員工
	void show_Emp();

	//刪除員工
	void del_Emp();

	//判斷員工是否存在,如果存在:返回員工在數據中的位置,不存在:返回-1
	int isExist(int id);

	//修改員工資料
	void mod_Emp();
	
	//尋找員工
	void fine_Emp();

	//按照編號排序
	void sort_Emp();

	//清空文件
	void clean_File();

	~workerManager();
};

