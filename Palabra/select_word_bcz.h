#pragma once
#include<queue>
#include<set>
#include"select_word_interface.h"
#include"user_dict.h"
#include"user_info.h"
//priority_queue比较器
class Compare
{
public:
	inline bool operator()(const UserWord &lhs, const UserWord &rhs)
	{
		if (lhs.importance >= 0 && rhs.importance == -1) return true;
		else if ((lhs.importance == rhs.importance
			|| (lhs.importance >= 0 && rhs.importance >= 0)))
			if (lhs.last_time < rhs.last_time) return true;
		return false;
	}
};

//按照百词斩(bcz)的模式选取单词
class SelectWordBcz :
	public SelectWordInterface
{
public:
	using SelectWordInterface::SelectWordInterface;
	virtual ~SelectWordBcz();
	// 选择模式
	virtual UserWord Select() override;
	virtual void Update(const UserWord word) override;//word的tag等更新应该由外部操作来完成

private:
	std::priority_queue<UserWord, std::vector<UserWord>, Compare> heap;
	//UserWord last_word_;
};