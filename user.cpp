#include <iostream>
#include <windows.h>
#include "user.h"
#include "car.h"
#include "room.h"
using namespace std;

void User::check() {
	Car car;
	Room room;
	while (1) {
		system("cls");
		cout << "===========================" << endl;
		cout << "1.��ʾ����״��" << endl;
		cout << "2.��ѯ������Ϣ" << endl;
		cout << "3.ͳ�Ƴ���" << endl;
		cout << "===========================" << endl;
		cout << "4.��ʾԤ������" << endl;
		cout << "5.��ѯԤ������" << endl;
		cout << "===========================" << endl;
		cout << "6.�˳���ͨ�û�" << endl;
		int ch;
		cout << "������Ҫִ�еĲ�����";
		cin >> ch;
		switch (ch) {
		case 1:
            car.showInfor();	
			break;
		case 2:
            car.findCar();
			break;
		case 3:
            car.timeAmount();
			break;
		case 4:
            room.showInfor();
			break;
		case 5:
            room.findRoom();
			break;
		case 6:
			return;
		default:
			cout << "��������ȷ�Ĳ���" << endl;
		}
		system("pause");
	}
}
