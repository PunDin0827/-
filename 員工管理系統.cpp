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
		cout << "�п�J���" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  //�h�X�t��
			wm.exitSystem();
				break;
		case 1: //�W�[���u
			wm.Add_Emp();
				break;
		case 2: //��ܭ��u
			wm.show_Emp();
				break;
		case 3: //�R�����u
			wm.del_Emp();
				break;
		case 4: //�ק���u���
			wm.mod_Emp();
				break;
		case 5: //�d�߭��u���
			wm.fine_Emp();
				break;
		case 6: //�Ƨ� 
			wm.sort_Emp();
				break;
		case 7: //�M���ɮ�
			wm.clean_File();
				break;
		default:
				system("cls"); //�M����ܵe��
				break;
		}
	}
	
	

	system("pause");
	return 0;
};