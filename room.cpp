#include "room.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//��ӷ���
void Room::addRoom() {
    time_t _time;
    while (1) {
        AA:
        cout << "�����뷿��ţ�";
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
                    cout << "�÷����ѱ�Ԥ��" << endl;
                    goto AA;
                }
            }
        }
        cout << "�����뷿�����ͣ�";
        cin >> roomType;
        cout << "������ͻ�������";
        cin >> customerName;
        cout << "��������ϵ�绰��";
        cin >> phoneNum;
        bookTime = time(&_time);

        saveInfor();
        char ch;
        cout << "\t�Ƿ������(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N') {
            break;
        }
        ifs.close();
    }
}

//ɾ������
void Room::delRoom() {
    ifstream roomData("roomData.txt", ios::in);
    ofstream outData("temproomData.txt", ios::out);
    if (!roomData || !outData) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string roomlicense, name, str;
    bool flag = true;
    cout << "������Ҫɾ���ķ���ţ�";
    cin >> roomlicense;
    while (roomData >> name) {
        getline(roomData, str);
        if (roomlicense == name) {
            cout << "Ҫɾ���ķ�����Ϣ��" << endl << str << endl;
            flag = false;
            break;
        }
        outData << name << " " << str << endl;
        if(flag) {
            cout << "�÷���û�б�Ԥ��" << endl;
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
                cout << "�޸�����ʱ�ļ���ʧ��" << endl;
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

//���ҷ���
void Room::findRoom() {
	ifstream roomData("roomData.txt", ios::in);
	if (!roomData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		string roomLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "������Ҫ��ѯ�ķ����:";
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
			cout << "�÷���û�б�Ԥ����" << endl;
        }
		else {
			cout << "����ţ�" << roomNum << " " << "�������ͣ�" << roomType
			<< " " << "�˿����ƣ�" << customerName << " " << "�÷�ʱ����" << (t1 - bookTime) << "��"
			<< " " << "�Ʒѣ�" << (t1 - bookTime) * 0.13 << "Ԫ" << endl;
        }
	}
	roomData.close();
}

//�޸ķ�����Ϣ
void Room::modRoom() {
	ifstream roomData("roomData.txt", ios::in);
	ofstream outData("temproomData.txt", ios::out);	
	if (!roomData || !outData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "������Ҫ�޸ĵķ���ţ�";
	cin >> roomNum;
	while (roomData >> name)	{
		getline(roomData, str);
		if (roomNum == name) {
			time_t _time;
			cout << "�޸ĺ�ķ���ţ�";
			cin >> roomNum;
			cout << "�޸ĺ�ķ������ͣ�";
			cin >> roomType;
			cout << "�޸ĺ�Ĺ˿�������";
			cin >> customerName;
            cout << "�޸ĺ�Ĺ˿��ֻ��ţ�";
			cin >> phoneNum;
			bookTime = time(&_time);
			outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " "  << bookTime << endl;
			flag = false;
			break;
		}
		outData << name << " " << str << endl;				
	}
	if (flag) {
		cout << "�޸ķ������ݲ����ڣ�" << endl;
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
			cout << "�ļ���ʧ�ܣ�" << endl;
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

//��ʾ���з�����Ϣ
void Room::showInfor() {
     //�����ļ�����������roomData.txt�ļ�
	ifstream roomData("roomData.txt", ios::in);
	if (!roomData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;
		while (roomData >> roomNum)
		{
			roomData >> roomType >> customerName >> phoneNum >> bookTime;	
			t = time(&_time);
			cout << "����ţ�" << roomNum << " " << "�������ͣ�" << roomType
				<< " " << "�˿����ƣ�" << customerName << " " << "�˿��ֻ���" << phoneNum << " " << "ס��ʱ����" << (t - bookTime) << "��"
				<< " " << "�Ʒѣ�" << (t - bookTime) * 0.13 << "Ԫ" << endl;
			flag = false;
		}
		if (flag) {
            cout << "\n�޷���Ԥ����Ϣ" << endl;
        }
		else {
            cout << "\nԤ����������ʾ" << endl;
        }
	}
	roomData.close();
}

//����Ԥ��ʱ��
void Room::timeAmount()
{
	ifstream roomData("roomData.txt", ios::in);	
	if (!roomData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "Ԥ������������" << c1 << endl;
		cout << "ס��ʱ�䲻����һ�죺" << c2 << endl;
		cout << "ס��ʱ�䳬��һ�죺" << c1 - c2 << endl;
	}
	roomData.close();
}

//���淿����Ϣ
void Room::saveInfor()
{
	ofstream outData("roomData.txt", ios::app);	
	if (!outData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		outData << roomNum << " " << roomType << " " << customerName << " " << phoneNum << " " << bookTime << endl;
	}
	outData.close();
}