#pragma once
#include "user.h"
#include <string>
using namespace std;

class Admin :public User
{
public:
    void Manager();
};