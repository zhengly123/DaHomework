#include "operation_memorize.h"
#include"select_word_bcz.h"
using namespace std;


OperationMemorize::OperationMemorize(const BasicDict &basic_dict, UserDict &user_dict)
	:Operation("memorize","m","多种方式背单词"), basic_dict_(basic_dict),
	user_dict_(user_dict)
{
}


OperationMemorize::~OperationMemorize()
{
}

void OperationMemorize::Execute(const std::vector<std::string>&)
{
	PrintHelp();
	//TODO:实现背单词功能 选单词 输出
	SelectWordBcz select(basic_dict_.ToWordList(), user_dict_);
	auto t = select.Select();
	cout << t << endl;
}

void OperationMemorize::PrintHelp() const
{
	cout << "  选择题请输入正确的答案编号，填空题请键入完整的单词" << endl;
	
}
