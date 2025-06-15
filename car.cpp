#include "car.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//添加车辆
void Car::addCar() {
    time_t _time;
    while (1){
        AA:
            cout << "请输入车牌号：";
            cin >> carNum;

            ifstream ifs("carData.txt", ios::in);
            if (ifs) {
                char buf[1024];
                string strs[20];
                int index = 0;
                while (!ifs.eof()) {
                    ifs.getline(buf, 100);
                    strs[index++] = buf[0];
                }
                for (auto& num : strs) {
                    if (num == carNum) {
                        cout << "车牌号重复" << endl;
                        goto AA;
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

//删除车辆
void Car::delCar() {
    ifstream carData("carData.txt", ios::in);
    ofstream outData("tempcarData.txt", ios::out);
    if (!carData || !outData) {
        cout << "文件打开失败" << endl;
        return;
    }
    string carlicense, name, str;
    bool flag = true;
    cout << "请输入要删除的车牌号：";
    cin >> carlicense;
    while (carData >> name) {
        getline(carData, str);
        if (carlicense == name) {
            cout << "要删除的车辆信息：" << endl << str << endl;
            flag = false;
            break;
        }
        outData << name << " " << str << endl;
        if(flag) {
            cout << "该车辆不存在" << endl;
        }
        else {
            while (getline(carData, str)) {
                outData << str << endl;
            }

            carData.close();
            outData.close();

            ifstream in("tempcarData.txt", ios::in);
            ofstream out("carData.txt", ios::out);
            if (!in || !out) {
                cout << "修改数据时文件打开失败" << endl;
                return;
            }
            else {
                while (getline(in, str)) {
                    out << str << endl;
                }
            }
            in.close();
            out.close();
        }
    }
}

//查找车辆
void Car::findCar() {
	ifstream carData("carData.txt", ios::in);
	if (!carData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		string carLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "请输入要查询的车牌号:";
		cin >> carLicense;
		while (carData >> carNum) {
			carData >> carType >> color >> inTime;		
			t1 = time(&_time);

			if (carLicense == carNum) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "未找到该车辆信息！" << endl;
        }
		else {
			cout << "车牌号：" << carNum << " " << "车辆类型：" << carType
			<< " " << "颜色：" << color << " " << "停车时长：" << (t1 - inTime) << "秒"
			<< " " << "计费：" << (t1 - inTime) * 0.005 << "元" << endl;
        }
	}
	carData.close();
}

//修改车辆信息
void Car::modCar() {
	ifstream carData("carData.txt", ios::in);
	ofstream outData("tempcarData.txt", ios::out);	
	if (!carData || !outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "请输入要修改的车牌号：";
	cin >> carNum;
	while (carData >> name)	{
		getline(carData, str);
		if (carNum == name) {
			time_t _time;
			cout << "修改后的车牌号：";
			cin >> carNum;
			cout << "修改后的车的种类：";
			cin >> carType;
			cout << "修改后的车的颜色：";
			cin >> color;
			inTime = time(&_time);	
			outData << carNum << " " << carType << " " << color << " " << inTime << endl;
			flag = false;
			break;
		}
		outData << name << " " << str << endl;				
	}
	if (flag) {
		cout << "修改车辆数据不存在！" << endl;
    }
	else {
		while (getline(carData, str)) {
			outData << str << endl;
		}
		carData.close();
		outData.close();
		ifstream in("tempcarData.txt", ios::in);
		ofstream out("carData.txt", ios::out);
		if (!in || !out) {
			cout << "文件打开失败！" << endl;
			return;
		}
		else {
            while (getline(in, str))
			{
				out << str << endl;	
			}
        }
		in.close();
		out.close();
	}
}

//显示所有车辆信息
void Car::showInfor() {
     //创建文件输入流，打开carData.txt文件
	ifstream carData("carData.txt", ios::in);
	if (!carData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;
		while (carData >> carNum)
		{
			carData >> carType >> color >> inTime;	
			t = time(&_time);
			cout << "车牌号：" << carNum << " " << "车辆类型：" << carType
				<< " " << "颜色：" << color << " " << "停车时长：" << (t - inTime) << "秒"
				<< " " << "计费：" << (t - inTime) * 0.005 << "元" << endl;
			flag = false;
		}
		if (flag) {
            cout << "\n无车辆信息" << endl;
        }
		else {
            cout << "\n车辆信息已显示" << endl;
        }
	}
	carData.close();
}

//计算停车时长
void Car::timeAmount()
{
	ifstream carData("carData.txt", ios::in);	
	if (!carData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		int c1 = 0, c2 = 0;
		time_t _time, t1;
		while (carData >> carNum)
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

//保存车辆信息
void Car::saveInfor()
{
	ofstream outData("carData.txt", ios::app);	
	if (!outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		outData << carNum << " " << carType << " " << color << " " << inTime << endl;
	}
	outData.close();
}
