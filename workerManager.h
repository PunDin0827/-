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

	void show_menu();//��ܵ��
	void exitSystem(); //�h�X

	//�������u�H��
	int m_EmpNum;

	//���u�}�C���w
	Worker** m_EmpArray;

	//�W�[���u
	void Add_Emp();

	//�O�s���
	void save();

	//�P�_���O�_���ŭ�
	bool m_fileEmpty;

	//�έp���H��
	int get_EmpNum();

	//��l�ƭ��u
	void init_Emp();

	//��ܭ��u
	void show_Emp();

	//�R�����u
	void del_Emp();

	//�P�_���u�O�_�s�b,�p�G�s�b:��^���u�b�ƾڤ�����m,���s�b:��^-1
	int isExist(int id);

	//�ק���u���
	void mod_Emp();
	
	//�M����u
	void fine_Emp();

	//���ӽs���Ƨ�
	void sort_Emp();

	//�M�Ť��
	void clean_File();

	~workerManager();
};

