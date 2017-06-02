#include<fstream>
//#include"basic_word.h"
//#include"load_dict_simple.h"
//#include"logger_simple.h"
#include"user_dict.h"
#include"user_word.h"
#include"shell_windows.h"
#include"load_user_dict_simple.h"
#include"operation_search.h"
#include"shell_windows.h"
#include"select_word_bcz.h"
#include"load_basic_dict_json.h"
#include"load_user_dict_json.h"
using namespace std;

void run()
{
	ShellWindows shell;
	shell.Execute();
}

int main()
{
	//run();
	//BasicDict d1;
	//UserDict d2;
	//SelectWordBcz t(d1.ToWordList(), d2);
	
	//UserDict t;

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
	//auto list = dict.ToWordList();
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

	//Debug用户数据存储
	//UserDict a({});
	//UserWord word;
	//LoadUserDictSimple load;
	//word.word = "father";
	//word.tag.push_back("Favorite");
	//word.note.push_back("This is the most important word!");
	//word.error_num = 1, word.importance = 5, word.last_time = 111;
	//word.review_num = 1;
	//a.insert(word);
	//load.Save("userdata_zly.txt", a);
	//load.Load("userdata_zly.txt", a);
	//puts("-=-=-=-=-=-=-");
	//cout << *(a.cbegin());

	////Debug LoadBasicDictJson
	//LoadBasicDictJson lbdj;
	//BasicDict dict;
	//lbdj.Load("dict.json", dict);

	//Debug LoadUserDictJson
	LoadUserDictJson load;
	UserDict dict, dict2 = {};
	UserWord word = {};
	UserInfo info = {}, info2 = {};
	Date date = {};
	word.word = "father";
	word.last_time = int(time(NULL));
	word.note = "It's my favortie word!";
	dict.insert(word);
	dict.insert(word);
	date.day = 1;
	date.month = 6;
	date.year = 2016;
	info.level = "CET6";
	info.history.push_back(make_pair(date, 999));
	info.history.push_back(make_pair(date, 999));
	info.history.push_back(make_pair(date, 999));
	load.Save("data_zly.json",dict,info);
	load.Load("data_zly.json", dict2, info2);
	load.Save("data_zly1.json", dict2, info2);
}