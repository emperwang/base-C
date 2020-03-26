#include "student.h"
#include "admin.h"
student::student() {

}

student::student(string name, string pwd, string id) {
	this->m_name = name;
	this->m_pwd = pwd;
	this->s_id = id;
}

// �����˵�
void student::operMenu() {
	cout << "��ӭѧ��: " << this->m_name << " ��¼." << endl;
	cout << "---------------------------\n";
	cout << "|1.����ԤԼ		|\n";
	cout << "|2.�鿴�ҵ�ԤԼ	|\n";
	cout << "|3.�鿴����ԤԼ	|\n";
	cout << "|4.ȡ��ԤԼ		|\n";
	cout << "|5.ע����¼		|\n";
	cout << "---------------------------" << endl;
	cout << "��ѡ��Ҫ���еĲ���:" << endl;
}

// ����
void student::applyOrder() {
	cout << "����ԤԼ. " << endl;
	admin ad;
	// ҪԤԼ�Ļ����� �Լ�  ʱ��
	int romid;
	int time;
	int flag = true;
	while (flag) {
		ad.showComputer();
		cout << "������ҪԤԼ�Ļ����� :" << endl;
		cin >> romid;
		for (vector<computerRoom>::iterator it = ad.coms.begin(); it != ad.coms.end(); it++) {
			if (it->room_id == romid) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "������������������." << endl;;
			system("pause");
			system("cls");
		}
	}
	flag = true;
	while (flag) {
		cout << "������ҪԤԼ��ʱ�� :" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cin >> time;
		if (time == morning || time == afternoon) {
			flag = false;
		}
		if (flag) {
			cout << "������������������." << endl;;
			system("pause");
			system("cls");
		}
	}
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	// �����  ԤԼ��  ԤԼ��id		ʱ��	״̬
	ofs << romid << " " << this->m_name << " " << this->s_id << " " << time << " " << orderPorcess << endl;
	ofs.close();
}

string getStatus(int status) {
	switch (status) {
	case orderPorcess:
		return "������";
	case orderReady:
		return "ͨ��";
	case orderCancel:
		return "ȡ��";
	case orderFailed:
		return "ʧ��";
	}
}

// �鿴�Լ�����
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
				cout << "���Ļ���: " << romid << " ������:" << name << "  ������id:" << id << " ����ʱ��:" <<
					(atoi(time.c_str()) == 1 ? "����" : "����") <<"  ״̬:"<< getStatus(atoi(status.c_str())) << endl;
			}
		}
	}
	else {
		cout << "�ļ������ڻ�Ϊ��." << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
// �鿴���ж���
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
			cout << "���Ļ���: " << romid << " ������:" << name << "  ������id:" << id << " ����ʱ��:" <<
				(atoi(time.c_str()) == 1 ? "����" : "����") << "  ״̬:" << getStatus(atoi(status.c_str())) << endl;
		}
	}
	else {
		cout << "�ļ������ڻ�Ϊ��." << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

// ȡ������
void student::cancelOrder() {

}

