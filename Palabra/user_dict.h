#pragma once
#ifndef USER_DICT_H
#define USER_DICT_H
#include<string>
#include"dict_template.h"
#include"user_word.h"
//用户词典类，保存关于单词的用户数据
using UserDict = DictTemplate<UserWord>;
//class UserDict : public DictTemplate<UserWord>
//{
//public:
//	using DictTemplate<UserWord>::DictTemplate;
//protected:
//	std::string preference;
//	//TODO:用户词典 和 用户参数 要不要分离？要分离
//};

#endif  // !USER_DICT_H