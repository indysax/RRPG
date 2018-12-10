#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<Windows.h>
#include"Choice_member.h"
using namespace std;
void choice::choicescreen(string _user) {
	Save(_user);
	while (1) {
		display_job_pic();
		int cou = select();
		if (cou) {
			system("cls");
		}
		else {
			return;
		}
	}
}   //��ܵe��  
void choice::Save(string _user) {
	ifstream fin("Users//" + _user);
	if (!fin.is_open()) {
		cout << "file error!" << endl;
		system("pause");
		exit(1);
	}
	string save,save2,_save1,_save2;
	while(!fin.eof()) {
		getline(fin, save);
		save2 = save2 + save + " ";
	}
	User_job.resize(3,0);User_race.resize(3,0);User_skill.resize(6,"0 ");User_save.resize(6,"0 ");
	for (int i = 0; i < 3; i++) {
		_save1 = _save1.assign(save2, save2.find("SAVE1") + 5 + (i * 8), 1);
		_save2 = _save2.assign(save2, save2.find("SAVE1") + 6 + (i * 8), 1);
		User_job[i] = stoi(_save1);
		User_race[i] = stoi(_save2);
	}
	fin.close();
}
void choice::display_job_pic() {
	ifstream fin("Info\\job_pic.txt");
	if (!fin.is_open()) {
		cout << "file error!" << endl; system("pause"); exit(1);
	}
	int i;
	for (i = 0; i < 3; i++) {
		cout << "�СССССССССССССССССССССССССССС�" << endl;
		display_job(fin, getjob(i), getrace(i));
	}
	fin.close();
	cout << "�СССССССССССССССССССССССССССС�" << endl;
	cout << "1~3Ū������\t4�s��\t5�R��\t��L�����}" << endl;
}
int choice::select(){
	while (1) {
		int SEL = 0, num = 0;
		cin >> SEL;
		if (SEL == 4) {
			cout << "1~3�إߨ���" << endl;
			cin >> num;
			if (getjob(num - 1) != 0) { cout << "�n���Ŷ��~�i�H�إߨ����!! "; system("pause"); return 5;}
			newdata(num); 
		}
		else if (SEL == 5) {
			DEL(); system("pause");
		}
		else if (SEL == 1 || SEL == 2 || SEL == 3) {
			return User_job[SEL-1];
		}
		else
		{
			return 0;
		}
		return 5;
	}
}
int choice::newdata(int _num) {
	int A = 1;
	ifstream fin("Info\\job_text.txt");
	if (!fin.is_open()) {
		cout << "file error!" << endl; system("pause"); exit(1);
	}
	while (1) {	
		system("cls");
		string ss;
		while (!fin.eof()) {
			getline(fin,ss);
			if (ss == "!") {
				A = A + fin.tellg();
				break;
			}
			Sleep(333);
			cout << ss << endl;
		}
		int  race;
		cout << "�ХμƦr��ܧA���ر�:" << endl;
		cin >> race;
		if (0 < race && race < 5) {
			User_race[_num - 1] = race;
			break;
		}
	}
	while (1) {
		system("cls");
		string ss;
		fin.seekg(A, ios::beg);
		while (!fin.eof()) {
			getline(fin, ss);
			Sleep(333);
			cout << ss << endl;
		}
		int  job;
		cout << "�ХμƦr��ܧA��¾�~:" << endl;
		cin >> job;
		if (0 < job && job < 5) {
			User_job[_num - 1] = job;
			break;
		}
	}
	fin.close();
	return 0;
}
void choice::display_job(ifstream &fin,int _jobnum,int _racenum) {
	string _pic;
	for (int i = 0; i < 5; i++) {
		getline(fin, _pic);
		if (i == 2) {
			_pic.insert(24, racename(_racenum) + jobname(_jobnum));
		}
		cout << _pic << endl;
	}
	fin.seekg(0, ios::beg);
}
string choice::jobname(int _num) {
	switch (_num)
	{
	case 0:
		return "���";
	case 1:
		return "�Ԥh";
	case 2:
		return "�k�v";  
	case 3:
		return "�p��";
	case 4:
		return "�]��";
	default:
		return "���";
	}
}
string choice::racename(int _num) {
	switch (_num)
	{
	case 0:
		return "���";
	case 1:
		return "�H��";
	case 2:
		return "�~�H";
	case 3:
		return "����";
	case 4:
		return "���F";
	default:
		return "���";
	}
}
void choice::DEL() {
		int input;
		cout << "�n�R�����ӭ˷���??\n1~3��� ��L���^" << endl;
		cin >> input;
		if (input == 1 || input == 2 || input == 3) {
			User_job[input-1] = 0;
			User_race[input-1] = 0;
			cout << "~�w�R��~" << endl;
		}
		else
			return;
}
void choice::setjob(int _user_job, int num) {
	User_job[num] = _user_job;
}
int choice::getjob(int J) {
	return User_job[J];
}
void choice::setrace(int _user_race, int num) {
	User_race[num] = _user_race;
}
int choice::getrace(int R) {
	return User_race[R];
}