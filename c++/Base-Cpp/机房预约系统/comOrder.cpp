#include <iostream>
#include "comOrder.h"


order::order(){}

order::order(int romid, string name, string id, int time, int status) {
	this->romid = romid;
	this->o_name = name;
	this->o_id = id;
	this->time = time;
	this->status = status;
}

order::order(int romid, string name, string id, int time) {
	this->romid = romid;
	this->o_name = name;
	this->o_id = id;
	this->time = time;
}