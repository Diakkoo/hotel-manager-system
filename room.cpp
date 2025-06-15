#include "room.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//添加房间
void Room::addRoom() {
    time_t _time;
    while (1) {
        AA:
        cout << "请输入房间号：";
        cin >> roomNum;

        ifstream ifs("roomData.txt", ios::in);
        if (ifs) {
            char buf[1024];
            string strs[20];
            int index = 0;
            while (!ifs.eof()) {
                ifs.getline(buf, 100);
                strs[index++] = buf[0];
            }
            for (auto& num : strs) {
                if (num == roomNum) {
                    cout << "该房间已被预定" << endl;
                    goto AA;
                }
            }
        }
        cout << "请输入房间类型：";
        cin >> roomType;
        cout << "请输入客户姓名：";
        cin >> customerName;
        cout << "请输入联系电话：";
        cin >> phoneNum;
        bookTime = time(&_time);

        saveInfor();
        char ch;
        cout << "\t是否继续？(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N') {
            break;
        }
        ifs.close();
    }
}

//删除房间
void Room::delRoom() {
    ifstream roomData("roomData.txt", ios::in);
    ofstream outData("temproomData.txt", ios::out);
    if (!roomData || !outData) {
        cout << "文件打开失败" << endl;
        return;
    }
    string roomlicense, name, str;
    bool flag = true;
    cout << "请输入要删除的房间号：";
    cin >> roomlicense;
    while (roomData >> name) {
        getline(roomData, str);
        if (roomlicense == name) {
            cout << "要删除的房间信息：" << endl << str << endl;
            flag = false;
            break;
        }
        outData << name << " " << str << endl;
        if(flag) {
            cout << "该房间没有被预定" << endl;
        }
        else {
            while (getline(roomData, str)) {
                outData << str << endl;
            }

            roomData.close();
            outData.close();

            ifstream in("temproomData.txt", ios::in);
            ofstream out("roomData.txt", ios::out);
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

//查找房间
void Room::findRoom() {
	ifstream roomData("roomData.txt", ios::in);
	if (!roomData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		string roomLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "请输入要查询的房间号:";
		cin >> roomLicense;
		while (roomData >> roomNum) {
			roomData >> roomType >> customerName >> phoneNum >> bookTime;		
			t1 = time(&_time);

			if (roomLicense == roomNum) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "该房间没有被预定！" << endl;
        }
		else {
			cout << "房间号：" << roomNum << " " << "房间类型：" << roomType
			<< " " << "顾客名称：" << customerName << " " << "用房时长：" << (t1 - bookTime) << "秒"
			<< " " << "计费：" << (t1 - bookTime) * 0.13 << "元" << endl;
        }
	}
	roomData.close();
}

//修改房间信息
void Room::modRoom() {
	ifstream roomData("roomData.txt", ios::in);
	ofstream outData("temproomData.txt", ios::out);	
	if (!roomData || !outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "请输入要修改的房间号：";
	cin >> roomNum;
	while (roomData >> name)	{
		getline(roomData, str);
		if (roomNum == name) {
			time_t _time;
			cout << "修改后的房间号：";
			cin >> roomNum;
			cout << "修改后的房间类型：";
			cin >> roomType;
			cout << "修改后的顾客姓名：";
			cin >> customerName;
            cout << "修改后的顾客手机号：";
			cin >> phoneNum;
			bookTime = time(&_time);
			outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " "  << bookTime << endl;
			flag = false;
			break;
		}
		outData << name << " " << str << endl;				
	}
	if (flag) {
		cout << "修改房间数据不存在！" << endl;
    }
	else {
		while (getline(roomData, str)) {
			outData << str << endl;
		}
		roomData.close();
		outData.close();
		ifstream in("temproomData.txt", ios::in);
		ofstream out("roomData.txt", ios::out);
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

//显示所有房间信息
void Room::showInfor() {
     //创建文件输入流，打开roomData.txt文件
	ifstream roomData("roomData.txt", ios::in);
	if (!roomData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;
		while (roomData >> roomNum)
		{
			roomData >> roomType >> customerName >> phoneNum >> bookTime;	
			t = time(&_time);
			cout << "房间号：" << roomNum << " " << "房间类型：" << roomType
				<< " " << "顾客名称：" << customerName << " " << "顾客手机号" << phoneNum << " " << "住房时长：" << (t - bookTime) << "秒"
				<< " " << "计费：" << (t - bookTime) * 0.13 << "元" << endl;
			flag = false;
		}
		if (flag) {
            cout << "\n无房间预定信息" << endl;
        }
		else {
            cout << "\n预定房间已显示" << endl;
        }
	}
	roomData.close();
}

//计算预定时长
void Room::timeAmount()
{
	ifstream roomData("roomData.txt", ios::in);	
	if (!roomData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		int c1 = 0, c2 = 0;
		time_t _time, t1;
		while (roomData >> roomNum)
		{
			c1++;
			t1 = time(&_time);
            roomData >> roomType >> customerName >> phoneNum >> bookTime;
			if ((t1 - bookTime) * 0.13 < long(11232)) 
				c2++;
		}
		cout << "预定房间总数：" << c1 << endl;
		cout << "住房时间不超过一天：" << c2 << endl;
		cout << "住房时间超过一天：" << c1 - c2 << endl;
	}
	roomData.close();
}

//保存房间信息
void Room::saveInfor()
{
	ofstream outData("roomData.txt", ios::app);	
	if (!outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " " << bookTime << endl;
	}
	outData.close();
}