#include "student.h"

student::student() {

}

student::student(string name, string pwd, string id) {

}

// �����˵�
void student::operMenu() {

}

// ����
void student::applyOrder() {

}
// �鿴�Լ�����
void student::showMyOrder() {

}
// �鿴���ж���
void student::showAllOrder() {

}

// ȡ������
void student::cancelOrder() {

}

void student::addStudent() {
	string name;
	string pwd;
	string sid;
	cout << "������ѧ�����:" << endl;
	cin >> sid;
	cout << "������ѧ������ :" << endl;
	cin >> name;
	cout << "������ѧ������: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(STUDENT_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;

	ofs.close();

}