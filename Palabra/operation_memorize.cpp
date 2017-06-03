#include "operation_memorize.h"
#include"select_word_bcz.h"
using namespace std;


OperationMemorize::OperationMemorize(const BasicDict &basic_dict, UserDict &user_dict)
	:Operation("memorize","m","���ַ�ʽ������"), basic_dict_(basic_dict),
	user_dict_(user_dict)
{
}


OperationMemorize::~OperationMemorize()
{
}

void OperationMemorize::Execute(const std::vector<std::string>&)
{
	PrintHelp();
	//TODO:ʵ�ֱ����ʹ��� ѡ���� ���
	SelectWordBcz select(basic_dict_.ToWordList(), user_dict_);
	auto t = select.Select();
	cout << t << endl;
}

void OperationMemorize::PrintHelp() const
{
	cout << "  ѡ������������ȷ�Ĵ𰸱�ţ����������������ĵ���" << endl;
	
}
