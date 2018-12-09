#include<string>
using namespace std;
	class MY_login
	{
	public:
		void loginscreen();
		void setuser(string);
		void setpassword(string);
		bool createuser();
		void createpassword();
		bool checkuser();
		bool checkpassword();
		string getuser();
		string getpassword();
		void displaylogin(string);
		int getpasswordsize();
		void Initial();
	private:
		string USER;
		string PASSWORD;
	};