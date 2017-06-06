#include "FileCommentTxt.h"
#include <fstream>
using namespace std;

FileCommentTxt::FileCommentTxt()
{
}


FileCommentTxt::~FileCommentTxt()
{
}

void FileCommentTxt::Load(const std::string Path)
{
	article_.clear();
	ifstream is(Path);
	string line;
	//char c, str[100000];
	//int size = 0;
	while (getline(is, line))
		article_ += line + "\n";
	//article_ = string(str);
}

void FileCommentTxt::Save(const std::string Path)
{
	ofstream os(Path);
	os << commented_article_;
}
