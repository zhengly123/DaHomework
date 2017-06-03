#pragma once
#ifndef LOAD_BASIC_DICT_SIMPLE_H
#define LOAD_BASIC_DICT_SIMPLE_H
#include "load_basic_dict_strategy.h"
//���شʵ��ļ������ڼ��ز��Ը�ʽ
class LoadBasicDictSimple :
	public LoadBasicDictStrategy
{
public:
	LoadBasicDictSimple();
	virtual ~LoadBasicDictSimple();
	virtual const BasicDict Load(const std::string &path) override;
};


#endif  // !LOAD_BASIC_DICT_SIMPLE_H