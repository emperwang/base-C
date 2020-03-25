#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "admin.h"
using namespace std;

//��ʾ����Ա�Ĳ˵�
void showAdminMenu(identy* &ident);
// ���˵�����ʾ
void showMainMenu();
// �û���¼ file: Ҫ�������ļ�	role ��¼�Ľ�ɫ
void rolelogin(string file,int role);
int main() {
	int select = 0;
	while (true) {
		showMainMenu();
		cin >> select;
		switch (select) {
		case studentRole:			// ѧ����¼
			break;
		case teacherRole:			// ��ʦ��¼
			break;
		case adminRole:			// ����Ա
			rolelogin(ADMIN_FILE, adminRole);
			break;
		case logout:			// �˳�ϵͳ
			cout << "ллʹ�û���ԤԼϵͳ. ��ӭ�´ι���" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�������������������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return 0;
}

void rolelogin(string file, int role) {
	ifstream ifs;
	ifs.open(file);

	if (ifs.is_open()) {
		switch (role) {
		case studentRole:
			break;
		case teacherRole:
			break;
		case adminRole:
			{
				string name;	// ��ȡ�û������� �û��� 
				string pwd;		// �û����������
				admin ma;	// ��¼���ļ��ж�ȡ��admin�û�����Ϣ
				cout << "������Ҫ��¼���û���: " << endl;
				cin >> name;
				cout << "������Ҫ��¼���û�������" << endl;
				cin >> pwd;
				while (ifs >> ma.m_name && ifs >> ma.m_pwd) {
					if (ma.m_name == name && ma.m_pwd == pwd) {
						cout << "��¼�ɹ�" << endl;
						identy *ident = new admin(name, pwd);
						ifs.close();
						showAdminMenu(ident);
						break;
					}
				}
				break;
			}
		default:
			cout << "�����ڵ��û���ɫ." << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << file << "  ���ݿ��ļ�������.��������." << endl;
	}
	ifs.close();

}

void showAdminMenu(identy* &ident) {
	// ����ǿת
	admin *ad = (admin *)ident;
	int sel = 0;
	cin.clear();
	//cin.ignore();// ���һ���ַ�
	//cin.ignore(numeric_limits<std::streamsize>::max());	// �������������������
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // ����������ĵ�ǰ��
	while (true) {
		ad->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:			// ����û�
			ad->addPerson();
			break;
		case 2:			// �鿴�˺�
			ad->showPerson();
			break;
		case 3:			// �鿴����
			ad->showComputer();
			break;
		case 4:			// ���ԤԼ
			ad->cleanOrder();
			break;
		case 5:			// ע����¼
			cout << "����Ա :" << ad->m_name << " �˳���¼." << endl;
			delete ad;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������, ����������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showMainMenu() {
	cout << "****** ����ԤԼϵͳ *******" << endl;
	cout << "---------------------------\n";
	cout << "|1.ѧ������		|\n";
	cout << "|2.��ʦ			|\n";
	cout << "|3.����Ա		|\n";
	cout << "|0.�˳�ϵͳ		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ��¼���û�:" << endl;
}