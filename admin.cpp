#include "car.h"
#include "admin.h"
#include "room.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Admin::Manager()
{
    Car car;
    Room room;
    while (1)
    {
        system("cls");
        cout << "============================" << endl;
        cout << "1.增加车辆" << endl;
        cout << "2.显示所有车辆信息" << endl;
        cout << "3.查询车辆信息" << endl;
        cout << "4.修改车辆信息" << endl;
        cout << "5.删除车辆信息" << endl;
        cout << "6.统计车辆信息" << endl;
        cout << "============================" << endl;
        cout << "7.增加预定房间" << endl;
        cout << "8.显示所有预定房间信息" << endl;
        cout << "9.查询预定房间信息" << endl;
        cout << "10.修改预定房间信息" << endl;
        cout << "11.删除预定房间信息" << endl;
        cout << "12.统计预定房间信息" << endl;
        cout << "============================" << endl;
        cout << "13.退出管理用户" << endl;
        cout << "请输入要执行的操作编号" << endl;
        int i;
        cin >> i;
        
        switch (i)
        {
            case 1:
                car.addCar();
                break;
            case 2:
                car.showInfor();
                break;
            case 3:
                car.findCar();
                break;
            case 4:
                car.modCar();
                break;
            case 5:
                car.delCar();
                break;
            case 6:
                car.timeAmount();
                break;
            case 7:
                room.addRoom();
                break;
            case 8:
                room.showInfor();
                break;
            case 9:
                room.findRoom();
                break;
            case 10:
                room.modRoom();
                break;
            case 11:
                room.delRoom();
                break;
            case 12:
                room.timeAmount();
                break;
            case 13:
                return;
            default:
                cout << "Worng Number!" << endl;
        }
        system("pause");
    }
}