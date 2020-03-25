#include "admin.h"

admin::admin() {

}
admin::admin(string name, string pwd) {
	this->m_name = name;
	this->m_pwd = pwd;
}

// 显示管理员菜单界面
void admin::operMenu() {
	cout << "欢迎管理员: "<< this->m_name <<" 登录." << endl;
	cout << "---------------------------\n";
	cout << "|1.添加账号		|\n";
	cout << "|2.查看账号		|\n";
	cout << "|3.查看机房		|\n";
	cout << "|4.清空预约		|\n";
	cout << "|5.注销登录		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}
// 添加账号
void admin::addPerson() {
	cout << "添加用户" << endl;
	ofstream ofs;
	
	int sel = 0;
	while (true){
		cout << "请输入要添加的用户的角色类型 : " << endl;
		cout << "1.学生" << endl;
		cout << "2.老师" << endl;
		cout << "3.管理员" << endl;
		cin >> sel;
		switch (sel) {
		case 1:	// 同学
		{	
			student::addStudent();
			return;
		}
		case 2:	// 老师
		{
			teacher::addTeacher();
			return;
		}
		case 3:	// 管理员
		{
			admin::addAdmin();
			return;
		}
		default:
			cout << "输入的类型不正确，请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}

}

// 查看账号
void admin::showPerson() {
	cout << "展示用户" << endl;
}

// 查看机房信息
void admin::showComputer() {
	cout << "展示机房信息" << endl;
}

// 清空预约记录
void admin::cleanOrder() {
	cout << "清除预约信息." << endl;
}

void admin::addAdmin() {
	string name;
	string pwd;
	string sid;
	cout << "请输入管理员用户名 :" << endl;
	cin >> name;
	cout << "请输入管理员密码: " << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(ADMIN_FILE, ios::out | ios::app);
	ofs << name << " " << pwd << " " << endl;
	ofs.close();
}