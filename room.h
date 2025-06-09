#pragma once
#include <string>
#include <ctime>
using namespace std;

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