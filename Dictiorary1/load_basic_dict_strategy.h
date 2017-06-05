#pragma once
#ifndef LOAD_BASIC_DICT_STRATEGY_H
#define LOAD_BASIC_DICT_STRATEGY_H
#include <fstream>
#include"basic_dict.h"
//���ػ����ʵ��ļ��ĳ��������
class LoadBasicDictStrategy
{
public:
	LoadBasicDictStrategy();
	//��ֹ����
	LoadBasicDictStrategy(const LoadBasicDictStrategy &orig) = delete;
	virtual ~LoadBasicDictStrategy();
	
	//virtual const BasicDict Load(const std::string &path) = 0;
	//���شʵ��ļ�
	virtual bool Load(const std::string & path, BasicDict &dict) = 0;
};



#endif  // !LOAD_BASIC_DICT_STRATEGY_H
