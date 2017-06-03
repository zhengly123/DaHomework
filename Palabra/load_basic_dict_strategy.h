#pragma once
#ifndef LOAD_BASIC_DICT_STRATEGY_H
#define LOAD_BASIC_DICT_STRATEGY_H
#include <fstream>
#include"basic_dict.h"
//���شʵ��ļ�
class LoadBasicDictStrategy
{
public:
	LoadBasicDictStrategy();
	//��ֹ����
	LoadBasicDictStrategy(const LoadBasicDictStrategy &orig) = delete;
	virtual ~LoadBasicDictStrategy();
	//���شʵ��ļ�
	virtual const BasicDict Load(const std::string &path) = 0;
};



#endif  // !LOAD_BASIC_DICT_STRATEGY_H
