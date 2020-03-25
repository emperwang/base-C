#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <iostream>
#include <fstream>
#include "identy.h"
#include "globalFile.h"

class student :public identy {
public:

	student();

	student(string name, string pwd, string id);

	// 操作菜单
	virtual void operMenu();

	// 申请预约
	void applyOrder();
	// 查看自己订阅
	void showMyOrder();
	// 查看所有订阅
	void showAllOrder();

	// 取消订阅
	void cancelOrder();

	// 学生添加
	void addStudent();

	// 学生编号
	string s_id;
};


#endif // !__STUDENT_H__
