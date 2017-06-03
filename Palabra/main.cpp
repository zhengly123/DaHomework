#include<fstream>
#include"user_dict.h"
#include"user_word.h"
#include"select_word_bcz.h"
#include"load_basic_dict_json.h"
#include"load_user_dict_json.h"
#include"logger_json.h"
using namespace std;
//单词类的组成
void exp1()
{	
	BasicWord basic_word;
	Meaning meaning;
	basic_word.word = "father";
	basic_word.phonetic = "'fa:r";//删除了非ascii字母，便于演示。这个音标是错误的

	meaning.part_of_speech = "n";//词性
	meaning.chinese_meaning = "爸爸";

	basic_word.meaning.push_back(meaning);//多个解释
	basic_word.tag.push_back("CET6");//但此标签

	//UserWord user_word;与BasicWord类似
}
//字典类的使用
void exp2()
{
	LoadBasicDictJson loader;
	BasicDict dict;
	loader.Load("dict-small.json", dict);//载入词库文件
	cout<<dict.Search("American");//查找单词
	auto full_word_list = dict.ToWordList();//得到完整词表
	auto GRE_Word_list = dict.ToWordList("GRE");//得到GRE词表
}
//登陆与UserDict, UserInfo
void exp3()
{
	LoggerJson logger("userlist.json");//logger初始化时绑定文件
	User user;
	user.username_ = "zhengly123", user.password_ = "111111";
	if (logger.Login(user))//if (logger.signin(user))就是注册
	{
		//登陆成功
	}
	else
	{
		//登录失败
	}
	
	LoadUserDictJson load;
	UserDict dict;
	UserWord word = {};
	UserInfo info = {}, info2 = {};
	load.Load("data_zly.json", dict, info);//载入UserDict, UserInfo
	load.Save("data_zly1.json", dict, info);//保存
}
//背单词
void exp4()
{
	LoadBasicDictJson load_basic;
	LoadUserDictJson load_user;
	BasicDict basic_dict;
	UserDict user_dict;
	UserInfo info;
	load_basic.Load("dict.json", basic_dict);
	load_user.Load("data_zly.json", user_dict, info);

	ListType new_word, old_word;
	old_word = GetOldWordList(user_dict);//获得旧词
	//获得新词(最后一个参数是请求的新词个数，但不一定有这么多)
	new_word = GetNewWordList(basic_dict.ToWordList("GRE"), user_dict, 20);
	//传入新单词列表，复习单词列表，两个词库，模式设定
	//模式设置中：0为混合，1为新学习，2为复习
	SelectWordBcz sel(new_word, old_word, basic_dict, user_dict, 0);
	//while (需要继续背诵)//根据sel.Empty()判断，或者根据新词的个数判断
	//{
	//	auto user_word = sel.Select();//获得一个新单词
	//	用户背诵、操作完成后
	//	更新UserWord
	//	user_word.last_time = time(NULL);
	//	user_word.review_num++;
	//	if(错误)
	//		word.error_num++;
	//	这时还可以进行其他操作
	//		喜欢这个单词(user_word.favor=1)
	//		不再复习这个单词(importance=-1)
	//		增加笔记(user_word.note="啦啦啦")
	//	
	//	sel.Update(user_word);//背诵每个单词后必须更新，不然会报错
	//}

	//背诵结束后，记录写入日志
	//auto current_date = GetCurrentDate();//获得日期
	//info.history.push_back(make_pair(current_date, 背单词个数));
	//load_user.Save("data_zly.json", user_dict, info);//写入文件
}

int main()
{
	//exp1();
	//exp2();
	//exp3();
	//exp4();
}


/*
*以下代码作废
*以下代码作废
*以下代码作废
*以下代码作废
*/




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
//LoadBasicDictJson load;
//BasicDict dict;
//load.Load("dict.json", dict);

////Debug LoadUserDictJson
//LoadUserDictJson load;
//UserDict dict, dict2 = {};
//UserWord word = {};
//UserInfo info = {}, info2 = {};
//Date date = {};
//word.word = "father";
//word.last_time = int(time(NULL));
//word.note = "It's my favortie word!";
//dict.insert(word);
//dict.insert(word);
//date.day = 1;
//date.month = 6;
//date.year = 2016;
//info.level = "CET6";
//info.history.push_back(make_pair(date, 999));
//info.history.push_back(make_pair(date, 999));
//info.history.push_back(make_pair(date, 999));
//load.Save("data_zly.json",dict,info);
//load.Load("data_zly.json", dict2, info2);
//load.Save("data_zly1.json", dict2, info2);

//Debug SelectWordBcz
//LoadBasicDictJson lbdj;
//auto current_time = GetCurrentDate();
//BasicDict dict;
//UserDict udict;
//load_basic.Load("dict.json", dict);
//SelectWordBcz sel(dict.ToWordList(), ListType(), dict, udict);
//auto t = sel.Select();
//cout << t;
//auto list = dict.ToWordList();
//auto list2 = dict.ToWordList("senior");
//auto tt = GetThreeWord(list, t.word);
///*t.error_num++;
//t.review_num++;
//t.last_time = int(time(NULL));
//sel.Update(t);
//t = sel.Select();
//*/

////Debug logger_json
//LoggerJson lj("userlist.json"),llj("userlist.json");
//User a;
//a.username_ = "zhengly123";
//a.password_ = "111111";
//lj.Load();
//auto t = lj.Signup(a);
