#pragma once
#ifndef LOAD_BASIC_DICT_JSON_H
#define LOAD_BASIC_DICT_JSON_H
#include "load_basic_dict_strategy.h"
//���ػ����ʵ��ļ������ڼ���json��ʽ
class LoadBasicDictJson :
	public LoadBasicDictStrategy
{
public:
	LoadBasicDictJson();
	virtual ~LoadBasicDictJson();
	//virtual const BasicDict Load(const std::string &path) override;
	bool Load(const std::string & path, BasicDict &dict) override;
};

#endif  // !LOAD_BASIC_DICT_JSON_H