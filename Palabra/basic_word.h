#pragma once
#ifndef BASIC_WORD_H
#define BASIC_WORD_H
#include<string>
#include<vector>
#include<iostream>
#include"meaning.h"
//字典中的单词类（存储字典中的信息)。若为空，表示不存在。
struct BasicWord
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
	friend std::ostream &operator<<(std::ostream &o, const BasicWord &basic_word);
	//根据单词字母序排序
	friend bool operator<(const BasicWord& a, const BasicWord& b);
	inline operator std::string() { return word; }
	inline bool empty() const { return word.empty(); }
};


//**************************
//the definition of inline functions
//**************************
inline bool operator<(const BasicWord &a, const BasicWord &b)
{
	return a.word < b.word;
}
#endif // !BASIC_WORD_H