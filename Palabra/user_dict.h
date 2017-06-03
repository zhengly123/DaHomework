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
	//TODO:�û��ʵ� �� �û����� Ҫ��Ҫ���룿Ҫ����
};

#endif  // !USER_DICT_H