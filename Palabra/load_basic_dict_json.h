#pragma once
#ifndef LOAD_BASIC_DICT_JSON_H
#define LOAD_BASIC_DICT_JSON_H
#include "load_basic_dict_strategy.h"
//加载基础词典文件，用于加载json格式
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