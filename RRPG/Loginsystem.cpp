#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include"Loginsystem.h"
using namespace std;
void MY_login::loginscreen() {
	int mode = 0;
	while (1) {
		if (_kbhit()) {
			break;
		}
		else{
			displaylogin("");
			Sleep(200);
			system("cls");
			displaylogin("2");
			Sleep(200);
			system("cls");
		}
	 }
	while (1) {
		displaylogin("");
		cin >> mode;
		switch (mode)
		{
		case 1:
			cout << "帳號: "; if (createuser()) { continue; } cout << "密碼: ";  createpassword();
			Initial();
			system("pause"); system("cls");
		case 2:
			cout << "帳號: "; if (checkuser()) { continue; } cout << "密碼: ";  if (checkpassword()) { continue; }
			system("pause"); system("cls");
			return;
		case -1:
			exit(1);
		default:
			cout << "請輸入有效數字!!" << endl; system("pause"); system("cls");
		}
	}
}
void MY_login::displaylogin(string n) {
	ifstream log_f;
	string log_data = "";
	log_f.open("Themes\\Theme"+n+".txt");
	while (getline(log_f, log_data)) {
		cout << log_data << endl;
	}
	log_f.close();
	cout << "1. █ 註冊 █" << endl << "2. █ 登入 █ " << endl << "-1.█ 離開 █" << endl;
}
void MY_login::setuser(string _user) {
	USER = _user;
}
void MY_login::setpassword(string _password) {
	PASSWORD = _password;
}
string MY_login::getuser() {
	return USER;
}
string MY_login::getpassword() {
	return PASSWORD;
}
bool MY_login::createuser() {
	ifstream fin;
	string in_data;
	cin >> in_data;
	in_data = in_data + ".txt";
	fin.open("Users\\"+in_data);
	if (fin.is_open()) {
		cout << "這個帳號已經被人認領囉 QQ 請重新輸入~" << endl;
		fin.close();
		system("pause");
		system("cls");
		return 1;
	}
	else
	{
		ofstream fout;
		setuser(in_data);
		fout.open("Users\\" + in_data);
		fout.close();
		return 0;
	}

}
void MY_login::createpassword() {
	ofstream fout("Users\\" + getuser());
	string in_pass;
	cin >> in_pass;
	setpassword(in_pass);
	fout << in_pass;
	fout.close();
	cout << "註冊成功" << endl;
}
bool MY_login::checkuser() {
	ifstream fin;
	string my_user;
	cin >> my_user;
	my_user = my_user + ".txt";
	fin.open("Users\\" + my_user);
	if (fin.is_open()) {
		setuser(my_user);
		return 0;
	}
	else
	{
		cout << "查無此帳號!" << endl;system("pause");system("cls");
		return 1;
	}
}
bool MY_login::checkpassword() {
	ifstream fin;
	string PASS;
	string my_password;
	fin.open("Users\\" + getuser());
	cin >> my_password;
	fin >> PASS;
	if (PASS == my_password) {
		setpassword(my_password);
		return 0;
	}
	else
	{
		cout << "密碼錯誤!!" << endl; system("pause"); system("cls");
		return 1;
	}
}
int MY_login::getpasswordsize() {
	return PASSWORD.size();
}
void MY_login::Initial() {
	ofstream fout(("Users\\" + getuser()),ios::app);
	if (fout.is_open()) {
		string s =  "\nSAVE100\nSAVE200\nSAVE300" ;
		cout << s;
		fout << s;
		fout.close();
	}
	else
	{
		cout << "file is error" << endl;
	}
	
}