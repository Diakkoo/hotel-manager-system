#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "admin.h"
#include <iostream>
using namespace std;

int main() {
	User user;								//创建普通用户对象
	Admin admin;							//创建管理员对象
	char ch;
	while (1) {
		system("cls");
		cout << "1.普通用户登录" << endl;
		cout << "2.管理员登录" << endl;
		cout << "3.退出系统" << endl;
		cout << "请输入要执行的操作：";
		cin >> ch;
		switch (ch)
		{
		case '1':
			user.check();			//如果输入1，普通用户登录
			break;
		case '2':
			admin.Manager();			//如果输入2，管理员登录
			break;
		case '3':
			exit(0);					//如果输入3，退出系统
		default:
			cout << "请输入正确的操作" << endl;
		}
	}
	return 0;
}
