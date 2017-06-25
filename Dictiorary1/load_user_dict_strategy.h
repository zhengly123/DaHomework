#pragma once
#ifndef LOAD_USERDATA_STRATEGY_H
#define LOAD_USERDATA_STRATEGY_H
#include<fstream>
#include"user_dict.h"
#include"user_info.h"
//�����û��ʵ��ļ��ĳ��������
class LoadUserDictStrategy
{
public:
	LoadUserDictStrategy();
	//��ֹ����
	LoadUserDictStrategy(const LoadUserDictStrategy&) = delete;
	virtual ~LoadUserDictStrategy();
	//���شʵ��ļ�
	//virtual UserDict Load(const std::string &path) = 0;
	virtual bool Load(const std::string &path, UserDict & dict, UserInfo &info) = 0;
	virtual bool Save(const std::string path, const UserDict& user_dict,
		const UserInfo &info) = 0;
};

#endif  // !LOAD_USERDATA_STRATEGY_H


