#include<iostream>
#include<fstream>
#include"Loginsystem.h"
#include"Choice_member.h"
using namespace std;
void Login(login*_user) {
	_user->loginscreen();
	return;
}
void Choice(login*_user, choice*_choice) {
	_choice->choicescreen(_user->getuser());
}
void Safesave(login *lptr, choice *cptr) {
	ofstream fout("Users//"+lptr->getuser());
	fout << lptr->getpassword() << "\n"
		<< "SAVE1" << cptr->getjob(0) << cptr->getrace(0) << "\n"
		<< "SAVE2" << cptr->getjob(1) << cptr->getrace(1) << "\n"
		<< "SAVE3" << cptr->getjob(2) << cptr->getrace(2) << "\n"
		<< "SAVE1:" << "\n" << "關卡0 物品 技能裝備" << "\n"
		<< "SAVE2:" << "\n" << "關卡0 物品 技能裝備" << "\n"
		<< "SAVE3:" << "\n" << "關卡0 物品 技能裝備" << "\n";
	fout.close();
}
int main() {
	login MY_LOGIN;
	choice MY_CHOICE;
	Login(&MY_LOGIN);
	Choice(&MY_LOGIN,&MY_CHOICE);
	Safesave(&MY_LOGIN,&MY_CHOICE);
	system("pause");
	return 0;
}

/*
Login();			//登入畫面
Chioce();
IN_game();
END();
*/
