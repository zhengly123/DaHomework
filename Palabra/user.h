#pragma once
#ifndef USER_H
#define USER_H
#include<string>
//用户类
class User
{
public:
	std::string username_, password_;
	User();
	User(const std::string username, const std::string password);
	~User();
	//HACK:判断是否应该放在Logger中
	//判断username_是否符合要求
	bool UsernameWellDefined();
	//判断password_是否符合要求
	bool PasswordWellDefined();
};
inline bool operator==(const User &a, const User &b)
{
	return (a.username_ == b.username_&&a.password_ == b.password_);
}

#endif  // !USER_H
#include<string>