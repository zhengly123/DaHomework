#include "operation_search.h"
#include <iostream>
using namespace std;

OperationSearch::OperationSearch(const BasicDict &basic_dict, UserDict &user_dict)
	:Operation("search", "s", "Look up a word in dictionary"), basic_dict_(basic_dict),
	user_dict_(user_dict)
{
}


OperationSearch::~OperationSearch()
{
}

void OperationSearch::PrintHelp() const
{
	cout << "  请输入单词，输入Q退出" << endl;
}

void OperationSearch::Execute(const std::vector<std::string>&)
{
	vector<string> command;
	ClearScreen();
	PrintHelp();
	while (1)
	{
		cout << "(lookup) ";//
		command = InputCommand();
		if (command.size() == 0)
			continue;
		else if (command[0] == "Q")
			break;
		else
		{
			//HACK::
			const auto &basic_word = basic_dict_.Search(command[0]);
			const auto &user_word = user_dict_.Search(command[0]);
			if (basic_word.empty())
				cout << "    抱歉，没有找到您查询的单词" << endl;
			else
				cout << basic_word << std::endl << user_word;
		}
	}
}

