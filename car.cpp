#include "car.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


/* 
	添加车辆
 */
void Car::addCar() {
    time_t _time;	//记录时间
    while (1){
        AA:
            cout << "请输入车牌号：";
            cin >> carNum;		// 接收输入的车牌号

            ifstream ifs("carData.txt", ios::in);	// 打开carData.txt文件
            if (ifs) {
                char buf[1024];
                string strs[20];
                int index = 0;
                while (!ifs.eof()) {	// 如果文件还不为空，读取文件内容
                    ifs.getline(buf, 100);		// 将文件每一行读取到buf中
                    strs[index++] = buf[0];		// 将buf第一个字符存入strs数组，即车牌号
                }
                for (auto& num : strs) {		// for循环遍历strs数组
                    if (num == carNum) {
                        cout << "车牌号重复" << endl;
                        goto AA;		// 如果车牌号重复，跳转到AA标签重新输入
                    }
                }

            }
            cout << "请输入车辆类型：";
            cin >> carType;
            cout << "请输入车辆颜色：";
            cin >> color;
            inTime = time(&_time);

            saveInfor();
            char ch;
            cout << "\t是否继续？(y/n)";
            cin >> ch;
            if (ch == 'n' || ch == 'N') {
                break;
            }
    }
}

/*
	删除车辆
*/
void Car::delCar() {
    ifstream carData("carData.txt", ios::in);	// 打开文件出入流
    ofstream outData("tempcarData.txt", ios::out);	// 打开临时文件输出流
    if (!carData || !outData) {	// 判断文件是否成功打开
        cout << "文件打开失败" << endl;
        return;
    }
    string carlicense, name, str;
    bool flag = true;
    cout << "请输入要删除的车牌号：";
    cin >> carlicense;		// 接收要删除的车牌号
    while (carData >> name) {		// 读取每行第一个字符串，即车牌号
        getline(carData, str);		// 读取整行内容
        if (carlicense == name) {		// 如果车牌号与要删除的车牌号相同，输出车辆其余信息
            cout << "要删除的车辆信息：" << endl << str << endl;
            flag = false;		// 标记为找到车辆
            break;		// 跳出循环
        }
        outData << name << " " << str << endl;		// 将未删除的车辆信息写入临时文件
        if(flag) {		// 如果flag为true，即没有该车辆信息
            cout << "该车辆不存在" << endl;
        }
        else {
            while (getline(carData, str)) {		// 读取剩余的车辆信息
                outData << str << endl;		// 将剩余的车辆信息写入临时文件
            }

            carData.close();
            outData.close();

            ifstream in("tempcarData.txt", ios::in);	// 打开临时文件输入流
            ofstream out("carData.txt", ios::out);		// 打开原文件输出流
            if (!in || !out) {
                cout << "修改数据时文件打开失败" << endl;
                return;
            }
            else {
                while (getline(in, str)) { 	// 将临时文件内容写入原文件	
                    out << str << endl;
                }
            }
            in.close();
            out.close();
        }
    }
}

/*
	查找车辆
*/
void Car::findCar() {
	ifstream carData("carData.txt", ios::in);		// 打开文件输入流
	if (!carData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		string carLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "请输入要查询的车牌号:";
		cin >> carLicense;		// 接收要查询的车牌号
		while (carData >> carNum) {		// while循环读取每行的第一个字符串，即车牌号
			carData >> carType >> color >> inTime;		// 读取剩下的车辆信息
			t1 = time(&_time);

			if (carLicense == carNum) {		// 判断要查询的车牌号是否相同
				flag = false;		// flag标记已找到车辆
				break;
			}
		}
		if (flag) {		// 如果flag为true，即未找到车辆信息
			cout << "未找到该车辆信息！" << endl;
        }
		else {		// 输出车辆信息
			cout << "车牌号：" << carNum << " " << "车辆类型：" << carType
			<< " " << "颜色：" << color << " " << "停车时长：" << (t1 - inTime) << "秒"
			<< " " << "计费：" << (t1 - inTime) * 0.005 << "元" << endl;
        }
	}
	carData.close();
}

/*
	修改车辆信息
*/
void Car::modCar() {
	ifstream carData("carData.txt", ios::in);		// 打开原文件输入流
	ofstream outData("tempcarData.txt", ios::out);		// 打开临时文件输出流
	if (!carData || !outData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "请输入要修改的车牌号：";
	cin >> carNum;		// 接收要修改的车牌号
	while (carData >> name)	{		// 读取每行第一个字符串，即车牌号
		getline(carData, str);		// 读取整行内容
		if (carNum == name) {		// 如果车牌号相同，输入修改后的车辆信息
			time_t _time;
			cout << "修改后的车牌号：";
			cin >> carNum;
			cout << "修改后的车的种类：";
			cin >> carType;
			cout << "修改后的车的颜色：";
			cin >> color;
			inTime = time(&_time);	
			outData << carNum << " " << carType << " " << color << " " << inTime << endl;
			flag = false;		// flag标记已找到车辆
			break;
		}
		outData << name << " " << str << endl;		// 将未修改的车辆信息写入临时文件		
	}
	if (flag) {		// 如果flag为true，即未找到车辆信息
		cout << "修改车辆数据不存在！" << endl;
    }
	else {
		while (getline(carData, str)) {		// 读取剩余的车辆信息
			outData << str << endl;		// 将剩余车辆信息写入临时文件
		}
		carData.close();
		outData.close();
		ifstream in("tempcarData.txt", ios::in);		// 打开临时文件输入流
		ofstream out("carData.txt", ios::out);		// 打开原文件输出流
		if (!in || !out) {
			cout << "文件打开失败！" << endl;
			return;
		}
		else {
            while (getline(in, str))		// 将临时文件内容写入原文件
			{
				out << str << endl;	
			}
        }
		in.close();
		out.close();
	}
}

/*
	显示所有车辆信息
*/
void Car::showInfor() {
    //创建文件输入流，打开carData.txt文件
	ifstream carData("carData.txt", ios::in);
	if (!carData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;		// 获取当前时间用于统计停车费用
		while (carData >> carNum)		// while循环输出全部车辆信息
		{
			carData >> carType >> color >> inTime;	
			t = time(&_time);
			cout << "车牌号：" << carNum << " " << "车辆类型：" << carType
				<< " " << "颜色：" << color << " " << "停车时长：" << (t - inTime) << "秒"
				<< " " << "计费：" << (t - inTime) * 0.005 << "元" << endl;
			flag = false;
		}
		if (flag) {		// 如果flag为true，即文件夹为空
            cout << "\n无车辆信息" << endl;
        }
		else {
            cout << "\n车辆信息已显示" << endl;
        }
	}
	carData.close();
}

/*
	计算停车时长
*/
void Car::timeAmount()
{
	ifstream carData("carData.txt", ios::in);		// 打开文件输入流
	if (!carData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		int c1 = 0, c2 = 0;		//c1统计车辆总数，c2统计停车时长不超过一天的车辆数
		time_t _time, t1;
		while (carData >> carNum)		// 读取每行车牌号
		{
			c1++;
			t1 = time(&_time);
            carData >> carType >> color >> inTime;
			if ((t1 - inTime) * 0.0001 < long(8.64)) 
				c2++;
		}
		cout << "车辆总数：" << c1 << endl;
		cout << "停车时间不超过一天：" << c2 << endl;
		cout << "停车时间超过一天：" << c1 - c2 << endl;
	}
	carData.close();
}

/*
	保存车辆信息
*/
void Car::saveInfor()
{
	ofstream outData("carData.txt", ios::app);	//打开文件输出流
	if (!outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		// 将车辆信息写入carData.txt文件
		outData << carNum << " " << carType << " " << color << " " << inTime << endl;
	}
	outData.close();
}
