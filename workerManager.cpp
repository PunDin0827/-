#include "workerManager.h"
workerManager::workerManager()
{
	//1.文件存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//讀文件
	if (!ifs.is_open())
	{
		cout << "文件不存在 " << endl;
		//初始化紀錄人數
		this->m_EmpNum = 0;
		//初始化指針
		this->m_EmpArray = NULL;
		this->m_fileEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但數據為空值
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件數據為空值
		cout << "文件數據為空 " << endl;
		this->m_EmpNum = 0;
		//初始化指針
		this->m_EmpArray = NULL;
		this->m_fileEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在且含有數據
	int num = this->get_EmpNum();
	cout << "員工人數為 " << num << endl;
	this->m_EmpNum = num;
	//開闢空間
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//將文件中的數據存進數組
	this->init_Emp();
	
	//初始化測試
	//for (int i = 0; i < this->m_empnum; i++)
	//{
	//	cout << "員工編號 " << this->m_emparray[i]->m_id
	//		<< "員工姓名 " << this->m_emparray[i]->m_id
	//		<< "員工職務 " << this->m_emparray[i]->m_depid << endl;
	//}
}
void workerManager::show_menu()
{
	cout << "******************************" << endl;
	cout << "***  歡迎使用員工管理系統  ***" << endl;
	cout << "******  0.退出管理程序  ******" << endl;
	cout << "******  1.增加員工訊息  ******" << endl;
	cout << "******  2.顯示員工訊息  ******" << endl;
	cout << "******  3.刪除離職員工  ******" << endl;
	cout << "******  4.修改員工訊息  ******" << endl;
	cout << "******  5.查找員工訊息  ******" << endl;
	cout << "******  6.按照編號排序  ******" << endl;
	cout << "******  7.清空所有檔案  ******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
//退出系統
void workerManager::exitSystem()
{
	cout << "歡迎下次使用 " << endl;
	system("pause");
	exit(0);
}
//增加員工
void workerManager::Add_Emp()
{
	cout << "請輸入添加員工的數量 " << endl;
	int addNum = 0;//保存用戶輸入的數量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		int newSize = this->m_EmpNum + addNum;//新空間人數=原來紀錄人數+新增人數
		//新空間
		Worker** newSpace = new Worker * [newSize];
		//將原空間數據複製至新空間
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//添加數據
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "請輸入第 " << i + 1 << "個新員工編號 " << endl;
			cin >> id;
			cout << "請輸入第 " << i + 1 << "個新員工姓名 " << endl;
			cin >> name;
			cout << "請選擇該員工職務 " << endl;
			cout << "1.普通員工 " << endl;
			cout << "2.經理 " << endl;
			cout << "3.老闆 " << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1 :
				worker = new Employee(id, name , 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss (id, name, 3);
				break;
			default:
				break;
			}
			//將員工指針保存到陣列中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//釋放原有空間
		delete[] this->m_EmpArray; 
		//指向新空間
		this->m_EmpArray = newSpace;
		//更新新員工人數
		this->m_EmpNum = newSize;
		//更新員工文件不為空值
		this->m_fileEmpty = false;
		cout << "添加成功 " << addNum << "名新員工 " << endl;
		//保存資料至文件中
		this->save();
	}	
	else
	{
		cout << "輸入數據有誤 " << endl;
	}
	system("pause");
	system("cls");
}	
//保存文件
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //寫文件
	//將每個員工的資料寫入文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs.close();
}
//統計文件人數
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME , ios::in);//讀取文件
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//統計人數
		num++;
		return num;
	}
}
//初始化員工
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)//普通員工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
	
	}	
	ifs.close();
}	
//顯示員工
void workerManager::show_Emp()
{
	//判斷文件是否為空值
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或無紀錄 " << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多形調用
			this->m_EmpArray[i]->show_Info();
		}
	}
	//按任意鍵清除畫面
	system("pause");
	system("cls");
}
//刪除員工
void  workerManager::del_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或記錄為空值 " << endl;
	}
	else
	{
		cout << "請輸入刪除員工編號: " << endl;
		int id = 0;
		cin >> id; 
		int index = this->isExist(id);
		if (index != -1)//員工存在,且需刪除在index位址的員工
		{

			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//數據前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新人員數
			//同步更新到文件中
			this->save();
			cout << "刪除成功！ " << endl;
		}	
		else
		{
			cout << "刪除失敗，未找到該員工 " << endl;
		}
	}	
	system("pause");
	system("cls");
}	


//判斷員工是否存在,如果存在:返回員工在數據中的位置,不存在:返回-1
int workerManager::isExist(int id)
{
	{
		int index = -1;
		for (int i = 0; i < this->m_EmpNum; i++) 
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				//找到員工
				index = i;
				break;
			}

		}
		return index;
	}
}
//修改員工資料
void  workerManager::mod_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或者紀錄為空值 " << endl;
	}
	else
	{
		cout << "請輸入修改的員工編號 " << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//找到該員工
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查找到: " << id << "員工,請輸入新的員工編號 " << endl;
			cin >> newID;
			cout << "請輸入新的姓名 " << endl;
			cin >> newName;
			cout << "請輸入新的職稱 " << endl;
			cout << "1.普通員工 " << endl;
			cout << "2.經理 " << endl;
			cout << "3.老闆 " << endl;

			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newID, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newID, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newID, newName, dSelect);
				break;
			default:
				break;
			}
			//更新數據到數組中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功! " << endl;
			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失敗,查無此人 " << endl;
		}
	}
	system("pause");
	system("cls");
}	
//尋找員工
void  workerManager::fine_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或者紀錄為空值 " << endl;
	}
	else
	{
		cout << "請輸入查找的方式: " << endl;
		cout << "1.按照員工編號查找 " << endl;
		cout << "2.按照員工姓名查找 " << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照編號查
			int id;
			cout << "請輸入查找的員工編號: " << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret != -1)
			{
				//找到該員工
				cout << "查找成功! 該員工資訊如下 " << endl;
				this->m_EmpArray[ret]->show_Info();
			}
			else
			{
				cout << "查找失敗,查無此人! " << endl;
			}
		}	
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "請輸入查找的姓名: " << endl;
			cin >> name;

			//加入判斷是否有查找到的標誌
			bool flag = false; //默認未找到
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功! 該員工編號為: " 
						<< this->m_EmpArray[i]->m_Id 
						<< "員工資訊如下" << endl;
					this->m_EmpArray[i]->show_Info();
					flag = true;
				}
			}
			if (flag == false)
				cout << "查找失敗,查無此人! " << endl;
		}
		else
		{
			cout << "輸入選項有誤! " << endl;
		}
	}
	system("pause");
	system("cls");
}
//按照編號排序
void workerManager::sort_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "文件不存在或者紀錄為空值 " << endl;
		system("pause");
		system("cls");
	}	
	else
	{
		cout << "請選擇排序方式: " << endl;
		cout << "1.按照員工編號進行升序排列 " << endl;
		cout << "2.按照員工編號進行降序排列 " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//宣告一個最小值或最大值的變數
			for (int j = 0; j < m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //降序
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}	
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功! 排序後的結果為" << endl;
		this->show_Emp();
		this->save();
	}
}
//清空文件
void workerManager::clean_File()
{
	cout << "確定是否要清空文件? " << endl;
	cout << "1.確定 " << endl;
	cout << "2.返回 " << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//刪除文件後重新創建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i =0  ; i < m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//刪除數組指針
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_fileEmpty = true;
		}
		cout << "刪除成功! " << endl;

	}
	system("pause");
	system("cls");
}
workerManager::~workerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}