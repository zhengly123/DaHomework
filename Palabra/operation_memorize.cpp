#include "operation_memorize.h"
using namespace std;


OperationMemorize::OperationMemorize():Operation("memorize","m","���ַ�ʽ������")
{
}


OperationMemorize::~OperationMemorize()
{
}

void OperationMemorize::Execute(const std::vector<std::string>& parameter)
{
	PrintHelp();
	//TODO:ʵ�ֱ����ʹ��� ѡ���� ���
}

void OperationMemorize::PrintHelp() const
{
	cout << "  ѡ������������ȷ�Ĵ𰸱�ţ����������������ĵ���" << endl;
}
