#ifndef __COMORDER_H__
#define __COMORDER_H__
#include <iostream>
#include <string>
using namespace std;

class order {
public:
	order();
	order(int romid, string name, string id, int time);
	order(int romid, string name, string id, int time, int status);

	// ԤԼ�Ļ���id
	int romid;
	// ԤԼ�˵�����
	string o_name;
	// ԤԼ�˵�id
	string o_id;
	// ԤԼ��ʱ��
	int time;
	// ԤԼ��״̬
	int status;
};


#endif // !__COMORDER_H__

