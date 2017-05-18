#include "load_user_dict_simple.h"
using namespace std;


LoadUserDictSimple::LoadUserDictSimple()
{
}


LoadUserDictSimple::~LoadUserDictSimple()
{
}

UserDict LoadUserDictSimple::Load(const std::string & path)
{
	set<UserWord> user_word_set;
	ifstream is(path);
	string temp;
	while (is)
	{
		UserWord user_word = {};
		getline(is, user_word.word);
		getline(is, temp); user_word.note.push_back(temp);
		is >> user_word.review_num >> user_word.error_num
			>> user_word.last_appear_time >> user_word.importance;
		user_word_set.insert(user_word);
	}
	return UserDict(user_word_set);
}

bool LoadUserDictSimple::Save(UserDict)
{
	//TODO:Íê³É±£´æ
	return false;
}
