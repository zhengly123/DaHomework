#pragma once
#include "basic_dict.h"
#include "cctype"
class FileComment
{
public:
	FileComment();
	virtual ~FileComment();
	//文件读入
	virtual void Load(const std::string Path) = 0;
	//文件输出
	virtual void Save(const std::string Path) = 0;
	void parse(const BasicDict &dict, ListType difficult_list);
protected:
	std::string article_;
	std::string commented_article_;
};

