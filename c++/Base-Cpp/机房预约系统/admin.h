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

	// ��ʾ����Ա�˵�����
	virtual void operMenu();
	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��¼
	void cleanOrder();

	// ��ӹ���Ա
	static void addAdmin();
};

#endif // !1
