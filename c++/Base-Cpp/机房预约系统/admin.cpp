#include "admin.h"

admin::admin() {

}
admin::admin(string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
}

// ��ʾ����Ա�˵�����
void admin::operMenu() {
	cout << "��ӭ����Ա: "<< this->m_name <<" ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|1.����˺�		|\n";
	cout << "|2.�鿴�˺�		|\n";
	cout << "|3.�鿴����		|\n";
	cout << "|4.���ԤԼ		|\n";
	cout << "|5.ע����¼		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
}
// ����˺�
void admin::addPerson() {
	cout << "����û�" << endl;
	ofstream ofs;
	
	int sel = 0;
	while (true){
		cout << "������Ҫ��ӵ��û��Ľ�ɫ���� : " << endl;
		cout << "1.ѧ��" << endl;
		cout << "2.��ʦ" << endl;
		cout << "3.����Ա" << endl;
		cin >> sel;
		switch (sel) {
		case 1:	// ͬѧ
		{	
			student::addStudent();
			return;
		}
		case 2:	// ��ʦ
		{
			teacher::addTeacher();
			return;
		}
		case 3:	// ����Ա
		{
			admin::addAdmin();
			return;
		}
		default:
			cout << "��������Ͳ���ȷ������������." << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

// �鿴�˺�
void admin::showPerson() {
	cout << "չʾ�û�" << endl;
}

// �鿴������Ϣ
void admin::showComputer() {
	cout << "չʾ������Ϣ" << endl;
}

// ���ԤԼ��¼
void admin::cleanOrder() {
	cout << "���ԤԼ��Ϣ." << endl;
}

void admin::addAdmin() {
	string name;
	string pwd;
	string sid;
	cout << "���������Ա�û��� :" << endl;
	cin >> name;
	cout << "���������Ա����: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << endl;
	ofs.close();
}