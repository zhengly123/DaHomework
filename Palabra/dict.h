#pragma once
#include"word_dict.h"
#include"set"
//词典类，保存所有单词和解释
class Dict
{
private:
	//不可修改
	const std::set<WordDict> dict_;
public:
	//必须初始化
	Dict(std::set<WordDict> & dict);
	Dict(std::set<WordDict> && dict) noexcept;
	~Dict();
	//inline void insert(const WordDict &word);//dict不能插入，只能初始化
	
	inline const std::set<WordDict>::const_iterator cbegin() const;
	inline const std::set<WordDict>::const_iterator cend() const;
	//查找单词
	WordDict Search(const std::string& word) const;
	//导出单词列表
	const std::vector<std::string> WordList() const;
};

//**************************
//the definition of inline functions
//**************************
inline const std::set<WordDict>::const_iterator Dict::cbegin() const
{
	return dict_.cbegin();
}
inline const std::set<WordDict>::const_iterator Dict::cend() const
{
	return dict_.cend();
}
