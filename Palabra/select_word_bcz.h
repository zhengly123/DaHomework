#pragma once
#include<queue>
#include<set>
#include "select_word_interface.h"
#include"user_dict.h"
//priority_queue比较器
class Compare
{
public:
	inline bool operator()(const UserWord &lhs, const UserWord &rhs)
	{
		if (lhs.importance >= 0 && rhs.importance == -1) return true;
		else if ((lhs.importance == rhs.importance
			|| (lhs.importance >= 0 && rhs.importance >= 0)))
			if (lhs.last_appear_time < rhs.last_appear_time) return true;
		return false;
	}
};

//按照百词斩(bcz)的模式
class SelectWordBcz :
	public SelectWordInterface
{
public:
	SelectWordBcz(const ListType &list, UserDict &dict);
	virtual ~SelectWordBcz();
	// 选择模式
	void SetMode(int mode);
	virtual UserWord Select() override;
	void Update(const UserWord &word);//word的tag等更新应该由外部操作来完成
private:
	std::priority_queue<UserWord, std::vector<UserWord>, Compare> heap;
	//0为混合，1为新学习，2为复习
	int mode_;
	//UserWord last_word_;
	ListType::const_iterator next_word_;
};