#pragma once
#include "FileComment.h"
class FileCommentTxt :
	public FileComment
{
public:
	FileCommentTxt();
	virtual ~FileCommentTxt();
	//文件读入
	virtual void Load(const std::string Path);
	//文件输出
	virtual void Save(const std::string Path);
};

