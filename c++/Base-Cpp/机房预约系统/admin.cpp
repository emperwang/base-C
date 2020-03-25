#include "admin.h"

admin::admin() {
	this->loadRecords();
}
admin::admin(string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->loadRecords();
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
			student().addStudent();
			return;
		}
		case 2:	// ��ʦ
		{
			teacher().addTeacher();
			return;
		}
		case 3:	// ����Ա
		{
			addAdmin();
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
	int sel = 0;
	while (true) {
		cout << "��������չʾ�Ľ�ɫ:" << endl;
		cout << "1.��ʦ" << endl;
		cout << "2.ѧ��" << endl;
		cin >> sel;
		if (sel == 1) {
			printTeacher();
			
			break;
		}
		else if (sel == 2) {
			printStudent();
			break;
		}
		else {
			cout << "������������������." << endl;
		}
	}
}

// �鿴������Ϣ
void admin::showComputer() {
	cout << "չʾ������Ϣ" << endl;
}

// ���ԤԼ��¼
void admin::cleanOrder() {
	cout << "���ԤԼ��Ϣ." << endl;
}

void admin::loadRecords() {
	ifstream ifs,ifs1;
	ifs.open(STUDENT_FILE, ios::in);
	if (ifs.is_open()) {
		string name;
		string pwd;
		string sid;
		while (ifs >> name && ifs >> pwd && ifs >> sid) {
			this->studs.push_back(student(name, pwd, sid));
		}
	}
	else {
		cout << "ѧ�����ݲ�����." << endl;
	}
	ifs.close();
	ifs1.open(TEACHER_FILE, ios::in);
	if (ifs1.is_open()) {
		string name;
		string pwd;
		string sid;
		while (ifs >> name && ifs >> pwd && ifs >> sid) {
			this->studs.push_back(student(name, pwd, sid));
		}
	}
	else {
		cout << "��ʦ���ݲ�����." << endl;
	}
	ifs1.close();
}


void printStu(student st) {
	cout << "ѧ������:" << st.m_name << "\t pwd=" << 
		"\t��¼����: ***"  << "\tѧ��ID=" << st.s_id << endl;
}

void admin::printStudent() {
	for_each(this->studs.begin(), this->studs.end(), printStu);
}

void printTea(teacher st) {
	cout << "��ʦ����:" << st.m_name << "\t pwd=" <<
		"\t��¼����: ***" << "\t��ʦID=" << st.t_id << endl;
}

void admin::printTeacher() {
	for_each(this->teachs.begin(), this->teachs.end(), printTea);
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