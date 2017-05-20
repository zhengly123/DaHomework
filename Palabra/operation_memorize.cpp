#include "operation_memorize.h"
using namespace std;


OperationMemorize::OperationMemorize():Operation("memorize","m","多种方式背单词")
{
}


OperationMemorize::~OperationMemorize()
{
}

void OperationMemorize::Execute(const std::vector<std::string>& parameter)
{
	PrintHelp();
	//TODO:实现背单词功能 选单词 输出
}

void OperationMemorize::PrintHelp() const
{
	cout << "  选择题请输入正确的答案编号，填空题请键入完整的单词" << endl;
}
