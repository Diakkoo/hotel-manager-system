#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "admin.h"
#include <iostream>
using namespace std;

int main() {
	User user;								//������ͨ�û�����
	Admin admin;							//��������Ա����
	char ch;
	while (1) {
		system("cls");
		cout << "1.��ͨ�û���¼" << endl;
		cout << "2.����Ա��¼" << endl;
		cout << "3.�˳�ϵͳ" << endl;
		cout << "������Ҫִ�еĲ�����";
		cin >> ch;
		switch (ch)
		{
		case '1':
			user.check();			//�������1����ͨ�û���¼
			break;
		case '2':
			admin.Manager();			//�������2������Ա��¼
			break;
		case '3':
			exit(0);					//�������3���˳�ϵͳ
		default:
			cout << "��������ȷ�Ĳ���" << endl;
		}
	}
	return 0;
}
