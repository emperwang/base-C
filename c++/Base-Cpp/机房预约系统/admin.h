#ifndef __ADMIN_H__
#define __ADMIN_H__

#include <iostream>
#include <string>
#include <fstream>
#include "identy.h"
#include "student.h"
#include "teacher.h"
#include "globalFile.h"
#include "computer.h"
using namespace std;
class admin :public identy {
public:
	admin();
	admin(string name,string pwd);

	// 显示管理员菜单界面
	virtual void operMenu();
	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 情况预约记录
	void cleanOrder();

	// 添加管理员
	static void addAdmin();
};

#endif // !1
