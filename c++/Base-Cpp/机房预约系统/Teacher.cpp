#include "teacher.h"

teacher::teacher() {

}
teacher::teacher(string name, string pwd, string tid) {

}
void teacher::operMenu() {

}

// �鿴����
void teacher::showAllOrder() {

}

// ���
void teacher::validOrder() {

}

void teacher::addTeacher() {
	string name;
	string pwd;
	string sid;
	cout << "��������ʦ���� :" << endl;
	cin >> name;
	cout << "��������ʦ����: " << endl;
	cin >> pwd;
	cout << "��������ʦ���:" << endl;
	cin >> sid;
	ofstream ofs;
	ofs.open(TEACHER_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();
}