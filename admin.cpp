#include "car.h"
#include "admin.h"
#include "room.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void Admin::Manager()
{
    Car car;    //声明一个Car对象
    Room room;  //声明一个Room对象
    while (1)
    {
        system("cls");  //终端清除屏幕内容
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
                car.addCar();   //跳转到Car类的addCar函数
                break;
            case 2:
                car.showInfor();    //跳转到Car类的showInfor函数
                break;
            case 3:
                car.findCar();  //跳转到Car类的findCar函数
                break;
            case 4:
                car.modCar();   //跳转到Car类的modCar函数
                break;
            case 5:
                car.delCar();   //跳转到Car类的delCar函数
                break;
            case 6:
                car.timeAmount();   //跳转到Car类的timeAmount函数
                break;
            case 7:
                room.addRoom();  //跳转到Room类的addRoom函数
                break;
            case 8:
                room.showInfor();   //跳转到Room类的showinfor函数
                break;
            case 9:
                room.findRoom();    //跳转到Room类的findRoom函数
                break;
            case 10:
                room.modRoom();  //跳转到Room类的modRoom函数
                break;
            case 11:
                room.delRoom();  //跳转到Room类的delRoom函数
                break;
            case 12:
                room.timeAmount();  //跳转到Room类的timeAmount函数
                break;
            case 13:
                return; //退出管理用户
            default:
                cout << "Worng Number!" << endl;
        }
        system("pause");
    }
}