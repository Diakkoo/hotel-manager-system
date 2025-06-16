#pragma once
#include <string>
#include <ctime>
using namespace std;

/*
    创建房间类，
    将房间特征作为**私有**成员变量，
    声明一些函数用于添加、删除、修改、查询房间信息等操作
*/
class Room
{
private:
    string roomNum;
    string roomType;
    string customerName;
    string phoneNum;
    time_t bookTime;
public:
    void addRoom();
    void showInfor();
    void findRoom();
    void delRoom();
    void modRoom();
    void timeAmount();
    void saveInfor();
};