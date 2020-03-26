#include "teacher.h"

teacher::teacher() {

}
teacher::teacher(string name, string pwd, string tid) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->t_id = tid;
}
void teacher::operMenu() {
	cout << "欢迎老师: " << this->m_name << " 登录." << endl;
	cout << "---------------------------\n";
	cout << "|					|\n";
	cout << "|1.查看所有预约	|\n";
	cout << "|2.审核预约		|\n";
	cout << "|3.注销登录		|\n";
	cout << "|					|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}

// 查看订阅
void teacher::showAllOrder() {

}

// 审核
void teacher::validOrder() {

}
