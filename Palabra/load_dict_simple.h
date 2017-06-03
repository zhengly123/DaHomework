#pragma once
#ifndef LOAD_DICT_SIMPLE_H
#define LOAD_DICT_SIMPLE_H
#include "load_dict_strategy.h"
//���شʵ��ļ������ڼ��ز��Ը�ʽ
class LoadDictSimple :
	public LoadDictStrategy
{
public:
	LoadDictSimple();
	virtual ~LoadDictSimple();
	virtual const Dict Load(const std::string &path) override;
};


#endif  // !LOAD_DICT_SIMPLE_H