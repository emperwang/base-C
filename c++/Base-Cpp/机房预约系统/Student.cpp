#include "student.h"
#include "admin.h"
#include "comOrder.h"
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
		return "δͨ��";
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
void printOrder(order od) {
	cout << "���Ļ���: " << od.o_id << " ������:" << od.o_name << "  ������id:" << od.o_id  << " ����ʱ��:" <<
		(od.time == 1 ? "����" : "����") << "  ״̬:" << getStatus(od.status) << endl;
}
// ȡ������
void student::cancelOrder() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "Ŀǰû��ԤԼ." << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}
	char c;
	ifs >> c;

	if (ifs.eof()) {
		cout << "Ŀǰû��ԤԼ����Ϣ." << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	// �ļ����ڣ��Ҳ�Ϊ��
	string romid;
	string name;
	string id;
	string time;
	string status;
	ifs.putback(c);
	vector<order> orders;
	int idx = 1;
	int sel = 0; // ��¼����ֵ
	while (ifs >> romid && ifs >> name && ifs >> id && ifs >> time && ifs >> status) {
		if (id == this->s_id) {
			order od(atoi(romid.c_str()), name, id, atoi(time.c_str()), atoi(status.c_str()));
			orders.push_back(od);
		}
	}
	ifs.close();
	if (orders.size() <= 0) {
		cout << "Ŀǰ��û�� " << this->m_name << "  ��ԤԼ��Ϣ." << endl;
		system("pause");
		system("cls");
		return;
	}

	while (true) {
		for (vector<order>::iterator it = orders.begin(); it != orders.end(); it++) {
			cout << idx++ << " ";
			printOrder(*it);
		}
		cout << "��������Ҫȡ����ԤԼ:" << endl;
		cin >> sel;
		if (sel > 0 && sel <= orders.size()) {
			orders.at(sel - 1).status = orderCancel;
			// cout << "�޸ĺ��ֵ: " << endl;
			// ����д���ļ�
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::out | ios::trunc);
			for (vector<order>::iterator it = orders.begin(); it != orders.end(); it++) {
				// printOrder(*it);

				// // �����  ԤԼ��  ԤԼ��id		ʱ��	״̬
				ofs << it->romid << " " << it->o_name << " " << it->o_id << " " << it->time << " " 
					<< it->status << endl;
			}
			ofs.close();
			break;
		}
		else {
			idx = 1;
			cout << "������������������. " << endl;
			system("pause");
			system("cls");
		}
	}
	system("pause");
	system("cls");
}

