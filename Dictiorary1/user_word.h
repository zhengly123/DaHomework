#pragma once
#ifndef USER_WORD_H
#define USER_WORD_H
#include<string>
#include<vector>
#include"sentence.h"
//用户单词类（存储关于单词的用户数据）。
//若为成员word==""，表示未找到单词。
struct UserWord
{
	std::string word;
	std::string note;
	//std::vector<std::string> tag;
	bool favor;
	int review_num;//复习次数
	int error_num;//错误次数
	int last_time;//最后一次复习时间
	int importance;//重要性:0未背过，1待复习，-1已记住

	friend bool operator<(const UserWord& a, const UserWord& b);
	//重载流输出
	friend std::ostream &operator<<(std::ostream &o, const UserWord &user_word);
	//根据单词字母序排序
	friend bool operator<(const UserWord& a, const UserWord& b);
};
#endif  // !USER_WORD_H