#include<string>
#include<vector>
using namespace std;
	class choice
	{
	public:
		void choicescreen(string); //主畫面
		void Save(string ); //讀全資料
		void setjob(int, int);
		void setrace(int, int);
		int getjob(int);
		int getrace(int);
		void display_job_pic();
		void display_job(ifstream &,int,int);
		string jobname(int);
		string racename(int);
		int select( );
		int newdata(int );
		void DEL();
	private:
		vector<int > User_job;
		vector<int > User_race;
		vector<string >User_save;
		vector<string > User_skill;
		string mainscreen;
	};

