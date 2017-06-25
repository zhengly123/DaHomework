#pragma once
#ifndef DICT_TEMPLATE_H
#define DICT_TEMPLATE_H
#include<set>
#include<vector>

using ListType = std::vector<std::string>;//单词表类型，用于储存单词表，不带有多余数据
//词典模板
template<typename T> class DictTemplate
{
private:
	std::set<T> dict_;
public:
	DictTemplate();
	DictTemplate(std::set<T> & dict);
	DictTemplate(std::set<T> && dict) noexcept;
	//Copy is not allowed，因为词典过大，复制成本非常高
	DictTemplate operator=(DictTemplate &&orig) noexcept = delete;
	virtual ~DictTemplate();
	void insert(const T &word);//插入新单词。若同名单词已经存在，则会覆盖。

	const typename std::set<T>::const_iterator cbegin() const;
	const typename std::set<T>::const_iterator cend() const;
	void clear();
	//查找单词（如果未找到返回只包含word的空词）
	const T Search(const std::string& word) const;
	//导出单词列表
	const ListType ToWordList() const;
	const ListType ToWordList(std::string tag) const;
private:
	//空对象，用于判断是不是返回了一个空值，即这个单词在词典中不存在。
	const T EmptyObject;
};

template<typename T>
inline DictTemplate<T>::DictTemplate()
{
}

template<typename T>
DictTemplate<T>::DictTemplate(std::set<T>& dict) :dict_(dict)
{
}

template<typename T> 
DictTemplate<T>::DictTemplate(std::set<T>&& dict) noexcept : dict_(dict)
{
}

//template<typename T>
//inline DictTemplate DictTemplate<T>::operator=(DictTemplate<T> && orig) & noexcept
//{
//	if (this != &orig)
//		dict_ = orig;
//	return *this;
//}

template<typename T>
DictTemplate<T>::~DictTemplate()
{
}

template<typename T>
const T DictTemplate<T>::Search(const std::string & word) const
{
	T temp = {};
	temp.word = word;
	auto it = dict_.find(temp);
	if (it == dict_.cend())
	{
		return temp;//如果未找到返回只包含word信息的空词
	}
	else return *it;
}

template<typename T>
const ListType DictTemplate<T>::ToWordList() const
{
	std::vector<std::string> wordlist;
	for (auto i : dict_)
		wordlist.push_back(i.word);
	return wordlist;
}

template<typename T>
inline const ListType DictTemplate<T>::ToWordList(std::string tag) const
{
	std::vector<std::string> wordlist;
	for (const auto &i : dict_)
	{
		if (find(i.tag.cbegin(), i.tag.cend(), tag) != i.tag.cend())
			wordlist.push_back(i.word);
	}
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
inline void DictTemplate<T>::clear()
{
	dict_.clear();
}

template<typename T>
inline void DictTemplate<T>::insert(const T & word)
{
	dict_.insert(word);
}
#endif  // !DICT_TEMPLATE_H
