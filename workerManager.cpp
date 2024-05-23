#include "workerManager.h"
workerManager::workerManager()
{
	//1.���s�b
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//Ū���
	if (!ifs.is_open())
	{
		cout << "��󤣦s�b " << endl;
		//��l�Ƭ����H��
		this->m_EmpNum = 0;
		//��l�ƫ��w
		this->m_EmpArray = NULL;
		this->m_fileEmpty = true;
		ifs.close();
		return;
	}
	//2.���s�b�A���ƾڬ��ŭ�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//���ƾڬ��ŭ�
		cout << "���ƾڬ��� " << endl;
		this->m_EmpNum = 0;
		//��l�ƫ��w
		this->m_EmpArray = NULL;
		this->m_fileEmpty = true;
		ifs.close();
		return;
	}
	//3.���s�b�B�t���ƾ�
	int num = this->get_EmpNum();
	cout << "���u�H�Ƭ� " << num << endl;
	this->m_EmpNum = num;
	//�}�P�Ŷ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//�N��󤤪��ƾڦs�i�Ʋ�
	this->init_Emp();
	
	//��l�ƴ���
	//for (int i = 0; i < this->m_empnum; i++)
	//{
	//	cout << "���u�s�� " << this->m_emparray[i]->m_id
	//		<< "���u�m�W " << this->m_emparray[i]->m_id
	//		<< "���u¾�� " << this->m_emparray[i]->m_depid << endl;
	//}
}
void workerManager::show_menu()
{
	cout << "******************************" << endl;
	cout << "***  �w��ϥέ��u�޲z�t��  ***" << endl;
	cout << "******  0.�h�X�޲z�{��  ******" << endl;
	cout << "******  1.�W�[���u�T��  ******" << endl;
	cout << "******  2.��ܭ��u�T��  ******" << endl;
	cout << "******  3.�R����¾���u  ******" << endl;
	cout << "******  4.�ק���u�T��  ******" << endl;
	cout << "******  5.�d����u�T��  ******" << endl;
	cout << "******  6.���ӽs���Ƨ�  ******" << endl;
	cout << "******  7.�M�ũҦ��ɮ�  ******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
//�h�X�t��
void workerManager::exitSystem()
{
	cout << "�w��U���ϥ� " << endl;
	system("pause");
	exit(0);
}
//�W�[���u
void workerManager::Add_Emp()
{
	cout << "�п�J�K�[���u���ƶq " << endl;
	int addNum = 0;//�O�s�Τ��J���ƶq
	cin >> addNum;
	if (addNum > 0)
	{
		//�K�[
		int newSize = this->m_EmpNum + addNum;//�s�Ŷ��H��=��Ӭ����H��+�s�W�H��
		//�s�Ŷ�
		Worker** newSpace = new Worker * [newSize];
		//�N��Ŷ��ƾڽƻs�ܷs�Ŷ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�K�[�ƾ�
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�п�J�� " << i + 1 << "�ӷs���u�s�� " << endl;
			cin >> id;
			cout << "�п�J�� " << i + 1 << "�ӷs���u�m�W " << endl;
			cin >> name;
			cout << "�п�ܸӭ��u¾�� " << endl;
			cout << "1.���q���u " << endl;
			cout << "2.�g�z " << endl;
			cout << "3.���� " << endl;
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
			//�N���u���w�O�s��}�C��
			newSpace[this->m_EmpNum + i] = worker;
		}
		//����즳�Ŷ�
		delete[] this->m_EmpArray; 
		//���V�s�Ŷ�
		this->m_EmpArray = newSpace;
		//��s�s���u�H��
		this->m_EmpNum = newSize;
		//��s���u��󤣬��ŭ�
		this->m_fileEmpty = false;
		cout << "�K�[���\ " << addNum << "�W�s���u " << endl;
		//�O�s��Ʀܤ��
		this->save();
	}	
	else
	{
		cout << "��J�ƾڦ��~ " << endl;
	}
	system("pause");
	system("cls");
}	
//�O�s���
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //�g���
	//�N�C�ӭ��u����Ƽg�J���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DepId << endl;
	}
	ofs.close();
}
//�έp���H��
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME , ios::in);//Ū�����
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//�έp�H��
		num++;
		return num;
	}
}
//��l�ƭ��u
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
		if (did == 1)//���q���u
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
//��ܭ��u
void workerManager::show_Emp()
{
	//�P�_���O�_���ŭ�
	if (this->m_fileEmpty)
	{
		cout << "��󤣦s�b�εL���� " << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//�Q�Φh�νե�
			this->m_EmpArray[i]->show_Info();
		}
	}
	//�����N��M���e��
	system("pause");
	system("cls");
}
//�R�����u
void  workerManager::del_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "��󤣦s�b�ΰO�����ŭ� " << endl;
	}
	else
	{
		cout << "�п�J�R�����u�s��: " << endl;
		int id = 0;
		cin >> id; 
		int index = this->isExist(id);
		if (index != -1)//���u�s�b,�B�ݧR���bindex��}�����u
		{

			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				//�ƾګe��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//��s�H����
			//�P�B��s����
			this->save();
			cout << "�R�����\�I " << endl;
		}	
		else
		{
			cout << "�R�����ѡA�����ӭ��u " << endl;
		}
	}	
	system("pause");
	system("cls");
}	


//�P�_���u�O�_�s�b,�p�G�s�b:��^���u�b�ƾڤ�����m,���s�b:��^-1
int workerManager::isExist(int id)
{
	{
		int index = -1;
		for (int i = 0; i < this->m_EmpNum; i++) 
		{
			if (this->m_EmpArray[i]->m_Id == id)
			{
				//�����u
				index = i;
				break;
			}

		}
		return index;
	}
}
//�ק���u���
void  workerManager::mod_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "��󤣦s�b�Ϊ̬������ŭ� " << endl;
	}
	else
	{
		cout << "�п�J�ק諸���u�s�� " << endl;
		int id;
		cin >> id;

		int ret = this->isExist(id);
		if (ret != -1)
		{
			//���ӭ��u
			delete this->m_EmpArray[ret];

			int newID = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�d���: " << id << "���u,�п�J�s�����u�s�� " << endl;
			cin >> newID;
			cout << "�п�J�s���m�W " << endl;
			cin >> newName;
			cout << "�п�J�s��¾�� " << endl;
			cout << "1.���q���u " << endl;
			cout << "2.�g�z " << endl;
			cout << "3.���� " << endl;

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
			//��s�ƾڨ�Ʋդ�
			this->m_EmpArray[ret] = worker;
			cout << "�ק令�\! " << endl;
			//�O�s����
			this->save();
		}
		else
		{
			cout << "�ק異��,�d�L���H " << endl;
		}
	}
	system("pause");
	system("cls");
}	
//�M����u
void  workerManager::fine_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "��󤣦s�b�Ϊ̬������ŭ� " << endl;
	}
	else
	{
		cout << "�п�J�d�䪺�覡: " << endl;
		cout << "1.���ӭ��u�s���d�� " << endl;
		cout << "2.���ӭ��u�m�W�d�� " << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//���ӽs���d
			int id;
			cout << "�п�J�d�䪺���u�s��: " << endl;
			cin >> id;
			int ret = isExist(id);
			if (ret != -1)
			{
				//���ӭ��u
				cout << "�d�䦨�\! �ӭ��u��T�p�U " << endl;
				this->m_EmpArray[ret]->show_Info();
			}
			else
			{
				cout << "�d�䥢��,�d�L���H! " << endl;
			}
		}	
		else if (select == 2)
		{
			//���өm�W�d
			string name;
			cout << "�п�J�d�䪺�m�W: " << endl;
			cin >> name;

			//�[�J�P�_�O�_���d��쪺�лx
			bool flag = false; //�q�{�����
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "�d�䦨�\! �ӭ��u�s����: " 
						<< this->m_EmpArray[i]->m_Id 
						<< "���u��T�p�U" << endl;
					this->m_EmpArray[i]->show_Info();
					flag = true;
				}
			}
			if (flag == false)
				cout << "�d�䥢��,�d�L���H! " << endl;
		}
		else
		{
			cout << "��J�ﶵ���~! " << endl;
		}
	}
	system("pause");
	system("cls");
}
//���ӽs���Ƨ�
void workerManager::sort_Emp()
{
	if (this->m_fileEmpty)
	{
		cout << "��󤣦s�b�Ϊ̬������ŭ� " << endl;
		system("pause");
		system("cls");
	}	
	else
	{
		cout << "�п�ܱƧǤ覡: " << endl;
		cout << "1.���ӭ��u�s���i��ɧǱƦC " << endl;
		cout << "2.���ӭ��u�s���i�歰�ǱƦC " << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;//�ŧi�@�ӳ̤p�ȩγ̤j�Ȫ��ܼ�
			for (int j = 0; j < m_EmpNum; j++)
			{
				if (select == 1)//�ɧ�
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //����
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
		cout << "�ƧǦ��\! �Ƨǫ᪺���G��" << endl;
		this->show_Emp();
		this->save();
	}
}
//�M�Ť��
void workerManager::clean_File()
{
	cout << "�T�w�O�_�n�M�Ť��? " << endl;
	cout << "1.�T�w " << endl;
	cout << "2.��^ " << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//�M�Ť��
		ofstream ofs(FILENAME, ios::trunc);//�R�����᭫�s�Ы�
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i =0  ; i < m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//�R���Ʋի��w
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_fileEmpty = true;
		}
		cout << "�R�����\! " << endl;

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