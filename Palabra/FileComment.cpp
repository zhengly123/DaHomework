#include "FileComment.h"
#include <algorithm>

FileComment::FileComment()
{
}


FileComment::~FileComment()
{
}

void FileComment::parse(const BasicDict & dict, ListType difficult_list)
{
	sort(difficult_list.begin(), difficult_list.end());
	bool word_not_complete = false;
	std::string word;
	for (int i = 0; i < article_.size(); ++i)
	{
		if (('A'<=article_[i]&& article_[i]<='Z')|| ('a' <= article_[i] && article_[i] <= 'z'))
		{
			if (!word_not_complete)
				word_not_complete = true;
			word.push_back(article_[i]);
		}
		else
		{
			if (word_not_complete)
			{
				word_not_complete = false;
				commented_article_ += word;
				auto it = std::binary_search(difficult_list.begin(), difficult_list.end(), word);
				if (it)
				{
					auto basic_dict = dict.Search(word);
					commented_article_ += "(";
					for (const auto j : basic_dict.meaning)
						commented_article_ += j.chinese_meaning + ",";
					commented_article_.pop_back();
					commented_article_ += ")";
				}
				word.clear();
			}
			commented_article_.push_back(article_[i]);
		}
	}
}
