#include"shell_windows.h"
#include"logger_simple.h"
#include"operation_search.h"
using namespace std;

//所有操作的数组
const vector<Operation*> AllOperation{ new OperationSearch() };

ShellWindows::ShellWindows() :Operation("", "", "The kernel process")
{
}

ShellWindows::~ShellWindows()
{
}
// CLI运行入口
void ShellWindows::Execute(const std::vector<std::string>&)
{
	vector<string> command;
	PrintWelcome();
	Login();//登录
	PrintHelp();
	while (1)
	{
		bool find_operation = false;
		cout << "(plb) ";//
		command = InputCommand();
		if (command.size() == 0)
			continue;
		else if (command[0] == "quit" || command[0] == "q")
			break;
		else if (command[0] == "help" || command[0] == "h")
			PrintHelp();
		else
		{
			for (auto &i : AllOperation)
			{
				if (i->command_name_ == command[0] 
					|| i->command_abbreviation_ == command[0])
				{
					find_operation = true;
					i->Execute(command);
				}
			}
			if (!find_operation)
				cout << "\"" << command[0] << "\"is not a command" << endl;
		}
	}
}

// 输出帮助
void ShellWindows::PrintHelp() const
{
	cout << "------------Mannul of Palabra------------" << endl;
	for (const auto &i : AllOperation)
	{
		cout << i->command_name_ << "\t(" << i->command_abbreviation_ << ")\t"
			<< i->help_ << endl;
	}
	cout << "--------------End of Mannul--------------" << endl;
}

void ShellWindows::PrintLoginInformation() const
{
	cout << "----请选择操作" << "\n"
		<< "\t1、登陆" << "\n"
		<< "\t2、注册新用户" << "\n"
		<< "\t3、游客模式" << endl;
}

void ShellWindows::Login()
{
	//1表示已经登陆，2表示游客模式
	int mode = 0;
	vector<string> input;
	string username, password;
	LoggerSimple logger;

	while (!mode)
	{
		PrintLoginInformation();
		input = InputCommand();
		if (input[0] == "1")
		{
			cout << "----请输入用户名" << endl;
			username = InputCommand()[0];
			cout << "----请输入密码" << endl;
			password = InputCommand()[0];
			if (logger.Login(User(username, password)))
			{
				username_ = username;
				mode = 1;
				cout << "----登陆成功" << endl;
			}
			else
				cout << "----用户名或密码错误" << endl;

		}
		else if (input[0] == "2")
		{
			cout << "----请输入用户名" << endl;
			username = InputCommand()[0];
			cout << "----请输入密码" << endl;
			password = InputCommand()[0];
			if (logger.Signup(User(username, password)))
			{
				username_ = username;
				cout << "----注册成功" << endl;
			}
			else cout << "----注册失败" << endl;
		}
		else if (input[0] == "3")
		{
			mode = 2;
			username_ = "";
		}
		else
			cout << "----请输入对应操作编号" << endl;
		Pause();
		ClearScreen();
	}
}

void ShellWindows::PrintWelcome() const
{
	cout << "Palabra (plb) 0.01\n\
This is free software : you are free to change and redistribute it.\n\
For help, type \"help\".\n";
}