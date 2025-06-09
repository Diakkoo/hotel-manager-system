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
        cout << "1.���ӳ���" << endl;
        cout << "2.��ʾ���г�����Ϣ" << endl;
        cout << "3.��ѯ������Ϣ" << endl;
        cout << "4.�޸ĳ�����Ϣ" << endl;
        cout << "5.ɾ��������Ϣ" << endl;
        cout << "6.ͳ�Ƴ�����Ϣ" << endl;
        cout << "============================" << endl;
        cout << "7.����Ԥ������" << endl;
        cout << "8.��ʾ����Ԥ��������Ϣ" << endl;
        cout << "9.��ѯԤ��������Ϣ" << endl;
        cout << "10.�޸�Ԥ��������Ϣ" << endl;
        cout << "11.ɾ��Ԥ��������Ϣ" << endl;
        cout << "12.ͳ��Ԥ��������Ϣ" << endl;
        cout << "============================" << endl;
        cout << "13.�˳������û�" << endl;
        cout << "������Ҫִ�еĲ������" << endl;
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