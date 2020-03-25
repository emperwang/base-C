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

	// �����˵�
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();
	// �鿴�Լ�����
	void showMyOrder();
	// �鿴���ж���
	void showAllOrder();

	// ȡ������
	void cancelOrder();

	// ѧ�����
	static void addStudent();

	// ѧ�����
	string s_id;
};


#endif // !__STUDENT_H__
