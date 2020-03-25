#include "student.h"

student::student() {

}

student::student(string name, string pwd, string id) {

}

// 操作菜单
void student::operMenu() {

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

void student::addStudent() {
	string name;
	string pwd;
	string sid;
	cout << "请输入学生姓名 :" << endl;
	cin >> name;
	cout << "请输入学生密码: " << endl;
	cin >> pwd;
	cout << "请输入学生编号:" << endl;
	cin >> sid;
	ofstream ofs;
	ofs.open(STUDENT_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;

	ofs.close();

}