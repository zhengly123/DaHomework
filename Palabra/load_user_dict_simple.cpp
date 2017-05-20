#include "load_user_dict_simple.h"
using namespace std;


LoadUserDictSimple::LoadUserDictSimple()
{
}

LoadUserDictSimple::~LoadUserDictSimple()
{
}

bool LoadUserDictSimple::Load(const std::string &path, UserDict & dict)
{
	//TODO:handle Exception
	//用户的单词类（存储用户关于单词的信息）
	//输入顺序为:
	//word
	//tag
	//note
	//review_num error_num last_appear_time importance
	ifstream is(path);
	string temp;
	dict.clear();
	while (is)
	{
		UserWord user_word = {};
		getline(is, user_word.word);
		//HACK:At most one note and tag are allowed
		getline(is, temp); user_word.note.push_back(temp);  
		getline(is, temp); user_word.tag.push_back(temp);
		is >> user_word.review_num >> user_word.error_num
			>> user_word.last_appear_time >> user_word.importance;
		if (is && !user_word.word.empty())//如果是一条新数据就加入set
			dict.insert(user_word);
	}
	return true;
}

bool LoadUserDictSimple::Save(const std::string path, const UserDict& user_dict)
{
	ofstream os(path);
	for (auto i = user_dict.cbegin(); i != user_dict.cend(); ++i)
	{
		//HACK:保存中At most one entry is allowed
		os << i->word << "\n";
		if (!i->note.empty()) os << i->note[0] << "\n";
		if (!i->tag.empty()) os << i->tag[0] << "\n";
		os << i->review_num << " " << i->error_num << " "
			<< i->last_appear_time << " " << i->importance << std::endl;
	}
	return true;
}
