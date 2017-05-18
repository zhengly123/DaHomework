#pragma once
#ifndef USER_DICT_H
#define USER_DICT_H
#include<string>
#include"dict_template.h"
#include"user_word.h"
class UserDict : public DictTemplate<UserWord>
{
public:
	using DictTemplate<UserWord>::DictTemplate;
protected:
	std::string preference;
	//TODO:用户词典 和 用户参数 要不要分离？要分离
};

#endif  // !USER_DICT_H