#include "student.h"

student::student() {

}

student::student(string name, string pwd, string id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->s_id = id;
}

// �����˵�
void student::operMenu() {
	cout << "��ӭѧ��: " << this->m_name << " ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|1.����ԤԼ		|\n";
	cout << "|2.�鿴�ҵ�ԤԼ	|\n";
	cout << "|3.�鿴����ԤԼ	|\n";
	cout << "|4.ȡ��ԤԼ		|\n";
	cout << "|5.ע����¼		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
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

