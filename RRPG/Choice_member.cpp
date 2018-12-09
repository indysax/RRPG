#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include"Choice_member.h"
#include"Loginsystem.h"
using namespace std;
void choice::choicescreen(string _user) {
	start:
	Save(_user);
	display_job();
	if (select()) {
		
	}
	else{
		system("cls");
		goto start;
	}
	
}
void choice::Save(string _user) {
	ifstream fin("Users//" + _user);
	if (!fin.is_open()) {
		cout << "file error!" << endl;
		system("pause");
		exit(1);
	}
	int job,race;
	fin >> job;
	for (int i = 0; i < 3; i++) {
		fin >> job;
		User_job.push_back(job);
		fin >> race;
		User_race.push_back(race);
	}
	fin.close();
}
void choice::display_job() {
	ifstream fin("Info\\job_pic.txt");
	if (!fin.is_open()) {
		cout << "file error!" << endl; system("pause"); exit(1);
	}
	int i;
	for (i = 0; i < 3; i++) {
		cout << "－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;
		display_job_pic(fin, getjob(i), getrace(i));
	}
	fin.close();
	cout << "－－－－－－－－－－－－－－－－－－－－－－－－－－－－－" << endl;
	cout << "1~3讀取紀錄\t4新建\t5刪除\t-1離開" << endl;
}
int choice::select() {
	int SEL,num;
	cin >> SEL;
	switch (SEL)
	{
	case 1:
		return User_job[0];
	case 2:
		return User_job[0];
	case 3:
		return User_job[0];
	case 4:
		cout << "要新增哪個存檔?" << endl;
		cin >> num;
		newdata(num);
	case 5:

	case -1:
		exit(1);
	default:
		break;
	}
	return 0;
}
int choice::newdata(int _num) {
	ifstream fin("Info\\job_text.txt");
	if (!fin.is_open()) {
		cout << "file error!" << endl; system("pause"); exit(1);
	}
	system("cls");
	string ss;
	while (!fin.eof()) {
		getline(fin, ss);
		cout << ss << endl;
	}
	fin.close();
	system("pause");
	return 0;
}
void choice::display_job_pic(ifstream &fin,int _jobnum,int _racenum) {
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
string choice::jobname(int _num) {
	switch (_num)
	{
	case 0:
		return "ＸＸ";
	case 1:
		return "戰士";
	case 2:
		return "法師";  
	case 3:
		return "小偷";
	case 4:
		return "魔王";
	default:
		return "ＸＸ";
	}
}
string choice::racename(int _num) {
	switch (_num)
	{
	case 0:
		return "ＸＸ";
	case 1:
		return "人類";
	case 2:
		return "獸人";
	case 3:
		return "矮人";
	case 4:
		return "地精";
	default:
		return "ＸＸ";
	}
}