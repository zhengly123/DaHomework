#pragma once
#ifndef WORD_USER_H
#define WORD_USER_H
#include<string>
#include<vector>
#include"sentence.h"
//用户的单词类（存储用户关于单词的信息）
struct WordUser
{
	std::string note;
	std::vector<Sentence> sentence;
	std::vector<std::string> tag;
	int review_num;
	int error_num;
	int last_appear_time;
	int importance;
};
#endif  // !WORD_USER_H