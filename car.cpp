#include "car.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//��ӳ���
void Car::addCar() {
    time_t _time;
    while (1){
        AA:
            cout << "�����복�ƺţ�";
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
                        cout << "���ƺ��ظ�" << endl;
                        goto AA;
                    }
                }

            }
            cout << "�����복�����ͣ�";
            cin >> carType;
            cout << "�����복����ɫ��";
            cin >> color;
            inTime = time(&_time);

            saveInfor();
            char ch;
            cout << "\t�Ƿ������(y/n)";
            cin >> ch;
            if (ch == 'n' || ch == 'N') {
                break;
            }
    }
}

//ɾ������
void Car::delCar() {
    ifstream carData("carData.txt", ios::in);
    ofstream outData("tempcarData.txt", ios::out);
    if (!carData || !outData) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    string carlicense, name, str;
    bool flag = true;
    cout << "������Ҫɾ���ĳ��ƺţ�";
    cin >> carlicense;
    while (carData >> name) {
        getline(carData, str);
        if (carlicense == name) {
            cout << "Ҫɾ���ĳ�����Ϣ��" << endl << str << endl;
            flag = false;
            break;
        }
        outData << name << " " << str << endl;
        if(flag) {
            cout << "�ó���������" << endl;
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

//���ҳ���
void Car::findCar() {
	ifstream carData("carData.txt", ios::in);
	if (!carData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		string carLicense;
		time_t _time, t1;
		bool flag = true;
		cout << "������Ҫ��ѯ�ĳ��ƺ�:";
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
			cout << "δ�ҵ��ó�����Ϣ��" << endl;
        }
		else {
			cout << "���ƺţ�" << carNum << " " << "�������ͣ�" << carType
			<< " " << "��ɫ��" << color << " " << "ͣ��ʱ����" << (t1 - inTime) << "��"
			<< " " << "�Ʒѣ�" << (t1 - inTime) * 0.005 << "Ԫ" << endl;
        }
	}
	carData.close();
}

//�޸ĳ�����Ϣ
void Car::modCar() {
	ifstream carData("carData.txt", ios::in);
	ofstream outData("tempcarData.txt", ios::out);	
	if (!carData || !outData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	string name, str;
	bool flag = true;
	cout << "������Ҫ�޸ĵĳ��ƺţ�";
	cin >> carNum;
	while (carData >> name)	{
		getline(carData, str);
		if (carNum == name) {
			time_t _time;
			cout << "�޸ĺ�ĳ��ƺţ�";
			cin >> carNum;
			cout << "�޸ĺ�ĳ������ࣺ";
			cin >> carType;
			cout << "�޸ĺ�ĳ�����ɫ��";
			cin >> color;
			inTime = time(&_time);	
			outData << carNum << " " << carType << " " << color << " " << inTime << endl;
			flag = false;
			break;
		}
		outData << name << " " << str << endl;				
	}
	if (flag) {
		cout << "�޸ĳ������ݲ����ڣ�" << endl;
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

//��ʾ���г�����Ϣ
void Car::showInfor() {
     //�����ļ�����������carData.txt�ļ�
	ifstream carData("carData.txt", ios::in);
	if (!carData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		bool flag = true;
		time_t _time, t;
		while (carData >> carNum)
		{
			carData >> carType >> color >> inTime;	
			t = time(&_time);
			cout << "���ƺţ�" << carNum << " " << "�������ͣ�" << carType
				<< " " << "��ɫ��" << color << " " << "ͣ��ʱ����" << (t - inTime) << "��"
				<< " " << "�Ʒѣ�" << (t - inTime) * 0.005 << "Ԫ" << endl;
			flag = false;
		}
		if (flag) {
            cout << "\n�޳�����Ϣ" << endl;
        }
		else {
            cout << "\n������Ϣ����ʾ" << endl;
        }
	}
	carData.close();
}

//����ͣ��ʱ��
void Car::timeAmount()
{
	ifstream carData("carData.txt", ios::in);	
	if (!carData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "����������" << c1 << endl;
		cout << "ͣ��ʱ�䲻����һ�죺" << c2 << endl;
		cout << "ͣ��ʱ�䳬��һ�죺" << c1 - c2 << endl;
	}
	carData.close();
}

//���泵����Ϣ
void Car::saveInfor()
{
	ofstream outData("carData.txt", ios::app);	
	if (!outData) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	else {
		outData << carNum << " " << carType << " " << color << " " << inTime << endl;
	}
	outData.close();
}
