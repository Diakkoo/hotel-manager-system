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
		cout << "1.显示车辆状况" << endl;
		cout << "2.查询车辆信息" << endl;
		cout << "3.统计车辆" << endl;
		cout << "===========================" << endl;
		cout << "4.显示预定房间" << endl;
		cout << "5.查询预定房间" << endl;
		cout << "===========================" << endl;
		cout << "6.退出普通用户" << endl;
		int ch;
		cout << "请输入要执行的操作：";
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
			cout << "请输入正确的操作" << endl;
		}
		system("pause");
	}
}
