#pragma once
#ifndef SELECT_WORD_INTERFACE_H
#define SELECT_WORD_INTERFACE_H
#include<string>
#include<vector>
#include"user_dict.h"
using ListType = std::vector<std::string>;
class SelectWordInterface
{
public:
	SelectWordInterface(const ListType &list,UserDict &dict);
	virtual ~SelectWordInterface();
	// ������һ������
	virtual UserWord Select() = 0;
protected:
	const ListType list_;//��Ӧʹ��&����ΪToWordList����ֵ
	UserDict &dict_;
};

#endif  // !SELECT_WORD_INTERFACE_H

