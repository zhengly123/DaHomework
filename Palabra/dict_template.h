#pragma once
#ifndef DICT_TEMPLATE_H
#define DICT_TEMPLATE_H
#include<set>
#include<vector>

using ListType = std::vector<std::string>;//单词表类型

template<typename T> class DictTemplate
{
private:
	std::set<T> dict_;
public:
	DictTemplate();
	DictTemplate(std::set<T> & dict);
	DictTemplate(std::set<T> && dict) noexcept;
	//Copy is not allowed
	DictTemplate operator=(DictTemplate &&orig) noexcept = delete;
	virtual ~DictTemplate();
	void insert(const T &word);//dict插入，若已经存在，则会覆盖

	const typename std::set<T>::const_iterator cbegin() const;
	const typename std::set<T>::const_iterator cend() const;
	void clear();
	//查找单词
	const T& Search(const std::string& word) const;
	//导出单词列表
	const ListType ToWordList() const;
private:
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
const T& DictTemplate<T>::Search(const std::string & word) const
{
	T temp;
	temp.word = word;
	auto it = dict_.find(temp);
	if (it == dict_.cend())
		return EmptyObject;//如果未找到返回空
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
