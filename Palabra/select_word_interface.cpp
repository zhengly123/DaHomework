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

