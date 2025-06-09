#pragma once
#include <string>
#include <ctime>
using namespace std;

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