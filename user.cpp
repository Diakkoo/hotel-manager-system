#include <iostream>
#include <windows.h>
#include "user.h"
#include "car.h"
#include "room.h"
using namespace std;

void User::check() {
	Car car;	//声明一个Car对象
	Room room;	//声明一个Room对象
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
		cin >> ch;	//接受输入的操作编号
		switch (ch) {
		case 1:
            car.showInfor();	//跳转到Car类的showInfor函数
			break;
		case 2:
            car.findCar();	//跳转到Car类的findCar函数
			break;
		case 3:
            car.timeAmount();	//跳转到Car类的timeAmount函数
			break;
		case 4:
            room.showInfor();	//跳转到Room类的showInfor函数
			break;
		case 5:
            room.findRoom();	//跳转到Room类的findRoom函数
			break;
		case 6:
			return;		//退出普通用户
		default:
			cout << "请输入正确的操作" << endl;
		}
		system("pause");
	}
}
