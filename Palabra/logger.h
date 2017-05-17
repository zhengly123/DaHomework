#pragma once
#include<string>
#include<cstdlib>
#include"user.h"
//µÇÂ½¿ØÖÆ
class Logger
{
public:
	Logger();
	virtual ~Logger();
	virtual bool Login(const User &user) = 0;
	virtual bool Signup(const User &user) = 0;
};

