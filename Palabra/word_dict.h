#pragma once
#ifndef WORD_DICT_H
#define WORD_DICT_H
#include<string>
#include<vector>
#include<iostream>
#include"meaning.h"
//字典中的单词类（存储字典中的信息)。若为空，表示不存在。
struct WordDict
{
	//英文单词
	std::string word;
	//音标
	std::string phonetic;
	std::vector<Meaning> meaning;
	int importance;
	//字典标签，例如CET-4
	std::vector<std::string> tag;
	//重载流输出
	friend void operator<<(std::ostream &o, const WordDict &worddict);
	//根据单词字母序排序
	friend bool operator<(const WordDict& a, const WordDict& b);
	inline operator std::string() { return word; }
};


//**************************
//the definition of inline functions
//**************************
inline bool operator<(const WordDict &a, const WordDict &b)
{
	return a.word < b.word;
}
#endif // !WORD_DICT_H