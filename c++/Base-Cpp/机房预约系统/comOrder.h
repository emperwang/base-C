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

	// 预约的机房id
	int romid;
	// 预约人的姓名
	string o_name;
	// 预约人的id
	string o_id;
	// 预约的时间
	int time;
	// 预约的状态
	int status;
};


#endif // !__COMORDER_H__

