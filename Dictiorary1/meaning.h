#pragma once
#ifndef MEANING_H
#define MEANING_H
#include<string>
#include"sentence.h"
//单词的一种释义
struct Meaning
{
	//词性，需要标准化存储
	std::string part_of_speech;
	std::string chinese_meaning;
	//只保存一个例句
	std::string sentence;//whether to use vector or not
};

#endif  // !MEANING_H