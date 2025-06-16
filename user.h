#pragma  once
#include <string>
using namespace std;

/*
	创建普通用户类，
	声明一个check函数，
	只能查看、统计、显示车辆，
	不能执行添加、删除、修改等操作
*/
class User 
{
public:
	//普通用户登录的菜单
	void check();
};
