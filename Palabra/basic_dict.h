#pragma once
#include"basic_word.h"
#include"set"
#include"dict_template.h"
//基础词典类，保存完整词库和解释
using BasicDict = DictTemplate<BasicWord>;




//词典类，保存所有单词和解释
//class BasicDict
//{
//private:
//	//不可修改
//	const std::set<BasicWord> dict_;
//public:
//	//必须初始化
//	BasicDict(std::set<BasicWord> & dict);
//	BasicDict(std::set<BasicWord> && dict) noexcept;
//	~BasicDict();
//	//inline void insert(const BasicWord &word);//dict不能插入，只能初始化
//	
//	inline const std::set<BasicWord>::const_iterator cbegin() const;
//	inline const std::set<BasicWord>::const_iterator cend() const;
//	//查找单词
//	BasicWord Search(const std::string& word) const;
//	//导出单词列表
//	const std::vector<std::string> ToWordList() const;
//};

//**************************
//the definition of inline functions
//**************************
//inline const std::set<BasicWord>::const_iterator BasicDict::cbegin() const
//
//inline const std::set<BasicWord>::const_iterator BasicDict::cend() const
//{
//	return dict_.cend();
//}
