#include <iostream>
#include <string>
#include <fstream>
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "admin.h"
using namespace std;

//显示管理员的菜单
void showAdminMenu(identy* &ident);
// 主菜单的显示
void showMainMenu();
// 用户登录 file: 要操作的文件	role 登录的角色
void rolelogin(string file,int role);
int main() {
	int select = 0;
	while (true) {
		showMainMenu();
		cin >> select;
		switch (select) {
		case studentRole:			// 学生登录
			break;
		case teacherRole:			// 老师登录
			break;
		case adminRole:			// 管理员
			rolelogin(ADMIN_FILE, adminRole);
			break;
		case logout:			// 退出系统
			cout << "谢谢使用机房预约系统. 欢迎下次光临" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入的有误，请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	


	system("pause");
	return 0;
}

void rolelogin(string file, int role) {
	ifstream ifs;
	ifs.open(file);

	if (ifs.is_open()) {
		switch (role) {
		case studentRole:
			break;
		case teacherRole:
			break;
		case adminRole:
			{
				string name;	// 读取用户的输入 用户名 
				string pwd;		// 用户输入的密码
				admin ma;	// 记录从文件中读取的admin用户的信息
				cout << "请输入要登录的用户名: " << endl;
				cin >> name;
				cout << "请输入要登录的用户的密码" << endl;
				cin >> pwd;
				while (ifs >> ma.m_name && ifs >> ma.m_pwd) {
					if (ma.m_name == name && ma.m_pwd == pwd) {
						cout << "登录成功" << endl;
						identy *ident = new admin(name, pwd);
						ifs.close();
						showAdminMenu(ident);
						break;
					}
				}
				break;
			}
		default:
			cout << "不存在的用户角色." << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << file << "  数据库文件不存在.请先配置." << endl;
	}
	ifs.close();

}

void showAdminMenu(identy* &ident) {
	// 进行强转
	admin *ad = (admin *)ident;
	int sel = 0;
	cin.clear();
	//cin.ignore();// 清除一个字符
	//cin.ignore(numeric_limits<std::streamsize>::max());	// 清除缓冲区中所有内容
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 清除缓冲区的当前行
	while (true) {
		ad->operMenu();
		cin >> sel;
		switch (sel) {
		case 1:			// 添加用户
			ad->addPerson();
			break;
		case 2:			// 查看账号
			ad->showPerson();
			break;
		case 3:			// 查看机房
			ad->showComputer();
			break;
		case 4:			// 清空预约
			ad->cleanOrder();
			break;
		case 5:			// 注销登录
			cout << "管理员 :" << ad->m_name << " 退出登录." << endl;
			delete ad;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误, 请重新输入." << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void showMainMenu() {
	cout << "****** 机房预约系统 *******" << endl;
	cout << "---------------------------\n";
	cout << "|1.学生代表		|\n";
	cout << "|2.老师			|\n";
	cout << "|3.管理员		|\n";
	cout << "|0.退出系统		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要登录的用户:" << endl;
}