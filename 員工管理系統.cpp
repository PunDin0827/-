#include<iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	
	workerManager wm;
	while (true)
	{
		wm.show_menu();
		int choice = 0;
		cout << "請輸入選擇" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  //退出系統
			wm.exitSystem();
				break;
		case 1: //增加員工
			wm.Add_Emp();
				break;
		case 2: //顯示員工
			wm.show_Emp();
				break;
		case 3: //刪除員工
			wm.del_Emp();
				break;
		case 4: //修改員工資料
			wm.mod_Emp();
				break;
		case 5: //查詢員工資料
			wm.fine_Emp();
				break;
		case 6: //排序 
			wm.sort_Emp();
				break;
		case 7: //清空檔案
			wm.clean_File();
				break;
		default:
				system("cls"); //清除顯示畫面
				break;
		}
	}
	
	

	system("pause");
	return 0;
};