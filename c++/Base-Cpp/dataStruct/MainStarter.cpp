#include <iostream>
#include "SingleList.h"
using namespace std;

// ���Ե�������
void testSingleList();
// ����˫������

// ����queue ����

// ����ջ


void testPoint() {
	int tmp = 5;
	int *p = &tmp;
	int *p1 = p;
	*p = 10;
	cout << "p = " << *p << ", p1=" << *p1 << endl;
}

int main() {
	//testPoint();
	testSingleList();

	system("pause");
	return 0;
}

void testSingleList() {
	HEAD *head = (HEAD *)malloc(sizeof(HEAD));
	init(head);
	appendValue(head, 10);
	appendValue(head, 10);
	appendValue(head, 10);
	//appendValue(head, 40);
	headInsertValue(head, 5);
	posInsertValue(head, 2, 15);
	posInsertValue(head, 100, 50);

	//deleteValue(head, 50);
	//deleteAllVal(head, 10);
	cout << "�Ƿ����Ԫ��50 :" << findValue(head, 50)<< endl;
	travleList(head);

	// �Ƿ�Ϊ��
	// ��С
	cout << "�Ƿ�Ϊ��: " << isEmpty(head) << ",  Ԫ�ظ���Ϊ: " << listSize(head) << endl;
}