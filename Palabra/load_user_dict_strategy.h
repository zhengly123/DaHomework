#pragma once
#ifndef LOAD_USERDATA_STRATEGY_H
#define LOAD_USERDATA_STRATEGY_H
#include<fstream>
#include"user_dict.h"
//�����û��ļ�
class LoadUserDictStrategy
{
public:
	LoadUserDictStrategy();
	//��ֹ����
	LoadUserDictStrategy(const LoadUserDictStrategy&) = delete;
	virtual ~LoadUserDictStrategy();
	//���شʵ��ļ�
	virtual UserDict Load(const std::string &path) = 0;
	virtual bool Save(const UserDict& user_dict) = 0;
};

#endif  // !LOAD_USERDATA_STRATEGY_H


