#pragma once
#include "FileComment.h"
class FileCommentTxt :
	public FileComment
{
public:
	FileCommentTxt();
	virtual ~FileCommentTxt();
	//�ļ�����
	virtual void Load(const std::string Path);
	//�ļ����
	virtual void Save(const std::string Path);
};

