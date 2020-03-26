#include "student.h"

student::student() {

}

student::student(string name, string pwd, string id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->s_id = id;
}

// 操作菜单
void student::operMenu() {
	cout << "欢迎学生: " << this->m_name << " 登录." << endl;
	cout << "---------------------------\n";
	cout << "|1.申请预约		|\n";
	cout << "|2.查看我的预约	|\n";
	cout << "|3.查看所有预约	|\n";
	cout << "|4.取消预约		|\n";
	cout << "|5.注销登录		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}

// 订阅
void student::applyOrder() {

}
// 查看自己订阅
void student::showMyOrder() {

}
// 查看所有订阅
void student::showAllOrder() {

}

// 取消订阅
void student::cancelOrder() {

}

