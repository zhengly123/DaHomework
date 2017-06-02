#pragma once
#include<string>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<fstream>
#include"user.h"
using UserListType = std::vector<User>;
//µÇÂ½³éÏóÀà
class Logger
{
public:
	Logger(std::string path);
	virtual ~Logger();
	bool Login(const User user);
	bool Signup(const User user);
	bool Load();
	const std::string path_;
protected:
	virtual bool load_user_list(UserListType &user_list) = 0;
	virtual bool save_user_list(const UserListType &user_list) = 0;
private:
	UserListType user_list_;
};

