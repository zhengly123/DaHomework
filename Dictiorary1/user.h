#pragma once
#ifndef USER_H
#define USER_H
#include<string>
//�û���
class User
{
public:
	std::string username_, password_;
	User();
	User(const std::string username, const std::string password);
	~User();
	////HACK:�ж��Ƿ�Ӧ�÷���Logger��
	////�ж�username_�Ƿ����Ҫ��
	//bool UsernameWellDefined();
	////�ж�password_�Ƿ����Ҫ��
	//bool PasswordWellDefined();
};
inline bool operator==(const User &a, const User &b)
{
	return (a.username_ == b.username_&&a.password_ == b.password_);
}

#endif  // !USER_H
#include<string>