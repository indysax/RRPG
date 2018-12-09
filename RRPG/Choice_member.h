#include<string>
#include<vector>
using namespace std;
	class choice
	{
	public:
		void choicescreen(string);
		void Save(string );
		void setjob(int, int);
		void setrace(int, int);
		int getjob(int);
		int getrace(int);
		void display_job();
		void display_job_pic(ifstream &,int,int);
		string jobname(int);
		string racename(int);
		int select( );
		int newdata(int );
	private:
		vector<int > User_job;
		vector<int > User_race;
		vector<string >User_save;
		vector<string >User_skill;
		
	};

