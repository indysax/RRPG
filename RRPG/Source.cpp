#include<iostream>
#include<fstream>
#include"Loginsystem.h"
#include"Choice_member.h"
using namespace std;
MY_login MY_user;
choice MY_choice;
void Login() {
	MY_user.loginscreen();
	return;
}
void Choice(ifstream &fin) {
	MY_choice.choicescreen(MY_user.getuser());
}
int main() {
	ifstream fin("Users//" + MY_user.getuser());
	Login();
	Choice(fin);
	system("pause");
	return 0;
}

/*
Login();			//µn¤Jµe­±
Chioce();
IN_game();
END();
*/
