#include "room.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*
	添加房间
*/
void Room::addRoom() {
    time_t _time;
    while (1) {
        AA:
        cout << "请输入房间号：";
        cin >> roomNum;		// 接收房间号

        ifstream ifs("roomData.txt", ios::in);		// 打开文件输入流
        if (ifs) {
            char buf[1024];
            string strs[20];
            int index = 0;
            while (!ifs.eof()) {		// 如果文件未到末尾
                ifs.getline(buf, 100);		// 读取一行数据
                strs[index++] = buf[0];		// 将每行第一个字符串放入strs数组，即房间号
            }
            for (auto& num : strs) {	// 遍历strs的内容
                if (num == roomNum) {	// 判断房间号是否相同
                    cout << "该房间已被预定" << endl;
                    goto AA;		// 如果相同，回到AA标签处重新输入房间号
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

        saveInfor();		// 调用saveInfor函数保存房间信息
        char ch;
        cout << "\t是否继续？(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N') {
            break;
        }
        ifs.close();
    }
}

/*
	删除房间
*/
void Room::delRoom() {
    ifstream roomData("roomData.txt", ios::in);		// 打开原文件输入流
    ofstream outData("temproomData.txt", ios::out);		// 打开临时文件输出流
    if (!roomData || !outData) {		// 判断文件是否打开
        cout << "文件打开失败" << endl;
        return;
    }
    string roomlicense, name, str;
    bool flag = true;
    cout << "请输入要删除的房间号：";
    cin >> roomlicense;		// 接收要删除的房间号
    while (roomData >> name) {		// 读取每行的房间号
        getline(roomData, str);		// 读取房间信息
        if (roomlicense == name) {		// 如果房间号相同
            cout << "要删除的房间信息：" << endl << str << endl;
            flag = false;		// flag标记已找到要删除的房间信息
            break;
        }
	}
    outData << name << " " << str << endl;
    if(flag) {		// 如果flag为true，即未找到要删除的房间信息
        cout << "该房间没有被预定" << endl;
    }
    else {
        while (getline(roomData, str)) {		// 将剩余的房间信息写入临时文件
            outData << str << endl;
        }

        roomData.close();
        outData.close();

        ifstream in("temproomData.txt", ios::in);		// 打开临时文件输入流
        ofstream out("roomData.txt", ios::out);		// 打开原文件输出流
        if (!in || !out) {		// 判断文件是否打开
            cout << "修改数据时文件打开失败" << endl;
            return;
        }
        else {
            while (getline(in, str)) {
                out << str << endl;		// 将临时文件中的内容写入原文件
            }
        }
        in.close();
        out.close();
    }
}

/*
	查找房间
*/
void Room::findRoom() {
	ifstream roomData("roomData.txt", ios::in);		// 打开原文件输入流
	if (!roomData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		string roomLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "请输入要查询的房间号:";
		cin >> roomLicense;		// 接收要查询的房间号
		while (roomData >> roomNum) {		// 读取每行的房间号
			roomData >> roomType >> customerName >> phoneNum >> bookTime;		// 读取房间信息
			t1 = time(&_time);

			if (roomLicense == roomNum) {	// 如果房间号相同
				flag = false;		// flag标记为已找到房间
				break;
			}
		}
		if (flag) {		// 如果flag为true，即未找到要查询的房间信息
			cout << "该房间没有被预定！" << endl;
        }
		else {		// 输出房间信息
			cout << "房间号：" << roomNum << " " << "房间类型：" << roomType
			<< " " << "顾客名称：" << customerName << " " << "用房时长：" << (t1 - bookTime) << "秒"
			<< " " << "计费：" << (t1 - bookTime) * 0.13 << "元" << endl;
        }
	}
	roomData.close();
}

/*
	修改房间信息
*/
void Room::modRoom() {
	ifstream roomData("roomData.txt", ios::in);		// 打开原文件输入流
	ofstream outData("temproomData.txt", ios::out);		// 打开临时文件输出流
	if (!roomData || !outData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "请输入要修改的房间号：";
	cin >> roomNum;		// 接收要修改的房间号
	while (roomData >> name)	{
		getline(roomData, str);
		if (roomNum == name) {		// 如果房间号相同，输入修改后的房间信息
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
			// 将修改后的房间信息写入临时文件
			outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " "  << bookTime << endl;
			flag = false;		// falg标记为已找到要修改的房间信息
			break;
		}
		outData << name << " " << str << endl;		// 将剩下的房间信息写入临时文件
	}
	if (flag) {		// 如果flag为true，即未找到要修改的房间信息
		cout << "修改房间数据不存在！" << endl;
    }
	else {
		while (getline(roomData, str)) {		// 将剩余的房间信息写入临时文件
			outData << str << endl;
		}
		roomData.close();
		outData.close();
		ifstream in("temproomData.txt", ios::in);		// 打开临时文件输入流
		ofstream out("roomData.txt", ios::out);		// 打开原文件输出流
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
	显示所有房间信息
*/
void Room::showInfor() {
    // 创建文件输入流，打开roomData.txt文件
	ifstream roomData("roomData.txt", ios::in);
	if (!roomData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;
		while (roomData >> roomNum)		// 读取每行的房间号
		{
			roomData >> roomType >> customerName >> phoneNum >> bookTime;	
			t = time(&_time);
			// 输出房间信息
			cout << "房间号：" << roomNum << " " << "房间类型：" << roomType
				<< " " << "顾客名称：" << customerName << " " << "顾客手机号" << phoneNum << " " << "住房时长：" << (t - bookTime) << "秒"
				<< " " << "计费：" << (t - bookTime) * 0.13 << "元" << endl;
			flag = false;
		}
		if (flag) {		// 如果flag为true，即未找到任何房间信息
            cout << "\n无房间预定信息" << endl;
        }
		else {
            cout << "\n预定房间已显示" << endl;
        }
	}
	roomData.close();
}

/*
	计算预定时长
*/
void Room::timeAmount()
{
	ifstream roomData("roomData.txt", ios::in);		// 打开原文件输入流
	if (!roomData) {		// 判断文件是否打开
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		int c1 = 0, c2 = 0;		// c1计算预定房间总数，c2计算住房时间不超过一天的房间数
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

/*
	保存房间信息
*/
void Room::saveInfor()
{
	ofstream outData("roomData.txt", ios::app);		// 打开文件输出流
	if (!outData) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {		// 如果文件打开成功，将房间信息写入文件
		outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " " << bookTime << endl;
	}
	outData.close();
}