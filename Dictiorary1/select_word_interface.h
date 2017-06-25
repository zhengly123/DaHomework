#pragma once
#ifndef SELECT_WORD_INTERFACE_H
#define SELECT_WORD_INTERFACE_H
#include<string>
#include<vector>
#include"user_dict.h"
#include"basic_dict.h"
using ListType = std::vector<std::string>;
//选取单词的抽象类
class SelectWordInterface
{
public:
	//mode 0为混合，1为新学习，2为复习
	//Warning:词典类不要使用右值
	SelectWordInterface(const ListType new_word_list,
		const ListType old_word_list, const BasicDict &basic_dict
		, UserDict &user_dict, const int mode = 0);
	virtual ~SelectWordInterface();
	// 给出下一个单词
	virtual UserWord Select() = 0;
	virtual void Update(UserWord word) = 0;
	virtual int NumberOfRestNewWord() = 0;
	virtual int NumberOfRestOldWord() = 0;
	virtual bool Empty() = 0;
protected:
	const ListType new_word_list_, old_word_list_;//不应使用&，因为ToWordList是右值
	const BasicDict *const basic_dict_;
	UserDict *user_dict_;
	bool updated;//UserData是否更新
	ListType::const_iterator next_word_;
	int mode_;//0为混合，1为新学习，2为复习
};
//得到三个单词不同于word的单词，用于测试
std::vector<std::string> GetThreeWord(const ListType &list, const std::string word);
ListType GetOldWordList(const UserDict &dict);
ListType GetNewWordList(const ListType new_list, const UserDict &dict, int num);
#endif  // !SELECT_WORD_INTERFACE_H

