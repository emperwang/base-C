#include "teacher.h"

teacher::teacher() {

}
teacher::teacher(string name, string pwd, string tid) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->t_id = tid;
}
void teacher::operMenu() {
	cout << "��ӭ��ʦ: " << this->m_name << " ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|					|\n";
	cout << "|1.�鿴����ԤԼ	|\n";
	cout << "|2.���ԤԼ		|\n";
	cout << "|3.ע����¼		|\n";
	cout << "|					|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
}

// �鿴����
void teacher::showAllOrder() {

}

// ���
void teacher::validOrder() {

}
