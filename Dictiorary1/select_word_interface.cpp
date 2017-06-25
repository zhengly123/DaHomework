#include "select_word_interface.h"

SelectWordInterface::SelectWordInterface(const ListType new_word_list,
	const ListType old_word_list, const BasicDict & basic_dict,
	UserDict & user_dict, const int mode)
	:new_word_list_(new_word_list), old_word_list_(old_word_list),
	basic_dict_(&basic_dict), user_dict_(&user_dict), updated(true), mode_(mode)
{
	next_word_ = new_word_list_.cbegin();
}

SelectWordInterface::~SelectWordInterface()
{
}

std::vector<std::string> GetThreeWord(const ListType & list, const std::string word)
{
	std::vector<std::string> ret;
	for (int i = 0; i < 3; )
	{
		auto t = list[rand() % list.size()];
		bool flag = false;

		if (t == word) continue;
		for (const auto &j : ret)
			if (j == t)
			{
				flag = true;
				break;
			}
		if (flag) continue;
		++i;
		ret.push_back(t);
	}
	return ret;
}

ListType GetNewWordList(const ListType new_list, const UserDict & dict, int num)
{
	ListType list;
	int cnt = 0;
	for (const auto &i : new_list)
		if (dict.Search(i).review_num == 0)
		{
			list.push_back(i);
			if (++cnt >= num) break;
		}
	return list;
}

ListType GetOldWordList(const UserDict &dict)
{
	ListType list;
	for (auto i = dict.cbegin(); i != dict.cend(); ++i)
		if (i->importance == 1)
			list.push_back(i->word);
	return list;
}

