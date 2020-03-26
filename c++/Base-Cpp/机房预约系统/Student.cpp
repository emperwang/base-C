#include "student.h"
#include "admin.h"
student::student() {

}

student::student(string name, string pwd, string id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->s_id = id;
}

// 操作菜单
void student::operMenu() {
	cout << "欢迎学生: " << this->m_name << " 登录." << endl;
	cout << "---------------------------\n";
	cout << "|1.申请预约		|\n";
	cout << "|2.查看我的预约	|\n";
	cout << "|3.查看所有预约	|\n";
	cout << "|4.取消预约		|\n";
	cout << "|5.注销登录		|\n";
	cout << "---------------------------" << endl;
	cout << "请选择要进行的操作:" << endl;
}

// 订阅
void student::applyOrder() {
	cout << "申请预约. " << endl;
	admin ad;
	// 要预约的机房号 以及  时间
	int romid;
	int time;
	int flag = true;
	while (flag) {
		ad.showComputer();
		cout << "请输入要预约的机房号 :" << endl;
		cin >> romid;
		for (vector<computerRoom>::iterator it = ad.coms.begin(); it != ad.coms.end(); it++) {
			if (it->room_id == romid) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "输入有误，请重新输入." << endl;;
			system("pause");
			system("cls");
		}
	}
	flag = true;
	while (flag) {
		cout << "请输入要预约的时间 :" << endl;
		cout << "1.上午" << endl;
		cout << "2.下午" << endl;
		cin >> time;
		if (time == morning || time == afternoon) {
			flag = false;
		}
		if (flag) {
			cout << "输入有误，请重新输入." << endl;;
			system("pause");
			system("cls");
		}
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	// 房间号  预约人  预约人id		时间	状态
	ofs << romid << " " << this->m_name << " " << this->s_id << " " << time << " " << orderPorcess << endl;
	ofs.close();
}

string getStatus(int status) {
	switch (status) {
	case orderPorcess:
		return "审阅中";
	case orderReady:
		return "通过";
	case orderCancel:
		return "取消";
	case orderFailed:
		return "失败";
	}
}

// 查看自己订阅
void student::showMyOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (ifs.is_open()) {
		string romid;
		string name;
		string id;
		string time;
		string status;
		while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
			if (id == this->s_id) {
				cout << "订阅机房: " << romid << " 订阅人:" << name << "  订阅人id:" << id << " 订阅时间:" <<
					(atoi(time.c_str()) == 1 ? "上午" : "下午") <<"  状态:"<< getStatus(atoi(status.c_str())) << endl;
			}
		}
	}
	else {
		cout << "文件不存在或为空." << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
// 查看所有订阅
void student::showAllOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (ifs.is_open()) {
		string romid;
		string name;
		string id;
		string time;
		string status;
		while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
			cout << "订阅机房: " << romid << " 订阅人:" << name << "  订阅人id:" << id << " 订阅时间:" <<
				(atoi(time.c_str()) == 1 ? "上午" : "下午") << "  状态:" << getStatus(atoi(status.c_str())) << endl;
		}
	}
	else {
		cout << "文件不存在或为空." << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

// 取消订阅
void student::cancelOrder() {

}

