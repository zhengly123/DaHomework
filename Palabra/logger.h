#pragma once
#include<string>
#include<cstdlib>
#include"user.h"
//��½����
class Logger
{
public:
	Logger();
	virtual ~Logger();
	virtual bool Login(const User &user) = 0;
	virtual bool Signup(const User &user) = 0;
	virtual bool load_user_list() = 0;
	virtual bool save_user_list() = 0;
};

