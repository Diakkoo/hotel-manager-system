#pragma once
#include <string>
#include <ctime>
using namespace std;

/*
    创建车辆类，
    将车辆特征作为**私有**成员变量，
    声明一些函数用于添加、删除、修改、查询车辆信息等操作
*/
class Car
{
private:
    string carNum;
    string carType;
    string color;
    time_t inTime;
public:
    void addCar();
    void showInfor();
    void findCar();
    void delCar();
    void modCar();
    void timeAmount();
    void saveInfor();
};