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
	//�û��ĵ����ࣨ�洢�û����ڵ��ʵ���Ϣ��
	//����˳��Ϊ:
	//word
	//tag
	//note
	//review_num error_num last_appear_time importance
	set<UserWord> user_word_set;
	ifstream is(path);
	string temp;
	while (is)
	{
		UserWord user_word = {};
		getline(is, user_word.word);
		//HACK:At most one note and tag are allowed
		getline(is, temp); user_word.note.push_back(temp);  
		getline(is, temp); user_word.tag.push_back(temp);
		is >> user_word.review_num >> user_word.error_num
			>> user_word.last_appear_time >> user_word.importance;
		if (is && !user_word.word.empty())//�����һ�������ݾͼ���set
			user_word_set.insert(user_word);
	}
	return UserDict(user_word_set);
}

bool LoadUserDictSimple::Save(const std::string path, const UserDict& user_dict)
{
	//TODO:��ɱ���
	ofstream os(path);
	for (auto i = user_dict.cbegin(); i != user_dict.cend(); ++i)
	{
		//HACK:������At most one entry is allowed
		os << i->word << "\n";
		if (!i->note.empty()) os << i->note[0] << "\n";
		if (!i->tag.empty()) os << i->tag[0] << "\n";
		os << i->review_num << " " << i->error_num << " "
			<< i->last_appear_time << " " << i->importance << std::endl;
	}
	return true;
}
