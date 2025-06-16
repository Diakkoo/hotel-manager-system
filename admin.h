#pragma once
#include "user.h"
#include <string>
using namespace std;

/*
    创建管理员类，继承自User类
    声明一个Manager函数，用于管理车辆的房间信息
*/
class Admin :public User
{
public:
    void Manager();
};