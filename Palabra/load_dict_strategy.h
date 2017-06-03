#pragma once
#ifndef LOAD_DICT_STRATEGY_H
#define LOAD_DICT_STRATEGY_H
#include <fstream>
#include"dict.h"
//���شʵ��ļ�
class LoadDictStrategy
{
public:
	LoadDictStrategy();
	//��ֹ����
	LoadDictStrategy(const LoadDictStrategy &orig) = delete;
	virtual ~LoadDictStrategy();
	//���شʵ��ļ�
	virtual const Dict Load(const std::string &path) = 0;
};



#endif  // !LOAD_DICT_STRATEGY_H
