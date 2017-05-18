#pragma once
#ifndef DICT_TEMPLATE_H
#define DICT_TEMPLATE_H
#include<set>
#include<vector>

using ListType = std::vector<std::string>;//单词表类型

template<typename T> class DictTemplate
{
protected:
	std::set<T> dict_;
public:
	//必须初始化
	DictTemplate(std::set<T> & dict);
	DictTemplate(std::set<T> && dict) noexcept;
	virtual ~DictTemplate();
	void insert(const T &word);//dict能插入，只能初始化
	
	const typename std::set<T>::const_iterator cbegin() const;
	const typename std::set<T>::const_iterator cend() const;
	//查找单词
	T Search(const std::string& word) const;
	//导出单词列表
	const ListType WordList() const;
};

template<typename T>
DictTemplate<T>::DictTemplate(std::set<T>& dict) :dict_(dict)
{
}

template<typename T> 
DictTemplate<T>::DictTemplate(std::set<T>&& dict) noexcept : dict_(dict)
{
}

template<typename T>
DictTemplate<T>::~DictTemplate()
{
}

template<typename T>
T DictTemplate<T>::Search(const std::string & word) const
{
	T T;
	T.word = word;
	return *dict_.find(T);
}

template<typename T>
const ListType DictTemplate<T>::WordList() const
{
	std::vector<std::string> wordlist;
	for (auto i : dict_)
		wordlist.push_back(i.word);
	return wordlist;
}

template<typename T>
const typename std::set<T>::const_iterator DictTemplate<T>::cbegin() const
{
	return dict_.cbegin();
}

template<typename T> 
const typename std::set<T>::const_iterator DictTemplate<T>::cend() const
{
	return dict_.cend();
}

template<typename T>
inline void DictTemplate<T>::insert(const T & word)
{
	dict_.insert(word);
}
#endif  // !DICT_TEMPLATE_H
