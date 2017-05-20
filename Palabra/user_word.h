#pragma once
#ifndef USER_WORD_H
#define USER_WORD_H
#include<string>
#include<vector>
#include"sentence.h"
//用户的单词类（存储用户关于单词的信息）
//输入顺序为:
//word
//tag
//note
//review_num error_num last_appear_time importance（-1表示不再出现）
struct UserWord
{
	std::string word;
	std::vector<std::string> note;
	std::vector<std::string> tag;
	int review_num;
	int error_num;
	int last_appear_time;
	int importance;//[1,5]
	friend bool operator<(const UserWord& a, const UserWord& b);
	//重载流输出
	friend std::ostream &operator<<(std::ostream &o, const UserWord &user_word);
	//根据单词字母序排序
	friend bool operator<(const UserWord& a, const UserWord& b);
};
#endif  // !USER_WORD_H