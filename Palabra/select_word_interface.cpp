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

