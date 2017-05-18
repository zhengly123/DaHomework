#include<fstream>
//#include"basci_word.h"
//#include"load_dict_simple.h"
//#include"logger_simple.h"
#include"user_dict.h"
#include"user_word.h"
#include"shell_windows.h"
using namespace std;

void run()
{
	ShellWindows shell;
	shell.Execute();
}

int main()
{
	//run();
	//UserDict t;
	UserWord t;

	//std::ofstream os("out.txt");
	//Debug单词类
	//BasicWord t,t2;
	//t2.word = "mother";
	//t.word = "father";
	//t.meaning.push_back({ "noun","爸爸","I'm your father!" });
	//t.tag.push_back("CET-6");
	//t.phonetic = "'fɑːðər";
	//o << t;
	
	//Debug词典类
	//LoadBasicDictSimple load;
	//const BasicDict dict(load.Load("dict_txt_simple.txt"));
	//auto list = dict.WordList();
	//for (auto i = dict.cbegin(); i != dict.cend(); ++i)
	//	os << *i;
	//cout<<dict.Search("father");

	//Debug登入
	/*LoggerSimple logger;
	User user;
	do
	{
		cout << "Please enter you username and password:" << endl;
		cin >> user.username_ >> user.password_;
	} while (!logger.Login(user));
	cout << "Log in successfully" << endl;*/
}