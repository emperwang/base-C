#include "teacher.h"

teacher::teacher() {

}
teacher::teacher(string name, string pwd, string tid) {

}
void teacher::operMenu() {

}

// 查看订阅
void teacher::showAllOrder() {

}

// 审核
void teacher::validOrder() {

}

void teacher::addTeacher() {
	string name;
	string pwd;
	string sid;
	cout << "请输入老师姓名 :" << endl;
	cin >> name;
	cout << "请输入老师密码: " << endl;
	cin >> pwd;
	cout << "请输入老师编号:" << endl;
	cin >> sid;
	ofstream ofs;
	ofs.open(TEACHER_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << sid << " " << endl;
	ofs.close();
}