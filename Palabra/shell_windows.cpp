#include"shell_windows.h"
#include"logger_simple.h"
#include"operation_search.h"
#include"operation_memorize.h"
using namespace std;

//���в���������
vector<Operation*> AllOperation{};

ShellWindows::ShellWindows() :Operation("", "", "The kernel process")
{
}

ShellWindows::~ShellWindows()
{
}
// CLI�������
void ShellWindows::Execute(const std::vector<std::string>&)
{
	vector<string> command;
	PrintWelcome();
	
	Login();//��¼
	Load(basic_dict_, user_dict_);//��������
	AllOperation.push_back(new OperationSearch(basic_dict_, user_dict_));
	AllOperation.push_back(new OperationMemorize(basic_dict_, user_dict_));

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
					ClearScreen();
				}
			}
			if (!find_operation)
				cout << "\"" << command[0] << "\"is not a command" << endl;
		}
	}
	Save(user_dict_);
}

// �������
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
	cout << "----��ѡ�����" << "\n"
		<< "\t1����½" << "\n"
		<< "\t2��ע�����û�" << "\n"
		<< "\t3���ο�ģʽ" << endl;
}

void ShellWindows::Login()
{
	//1��ʾ�Ѿ���½��2��ʾ�ο�ģʽ
	int mode = 0;
	vector<string> input;
	string username, password;
	LoggerSimple logger;

	while (!mode)
	{
		//TODO:�������½�������Load(��������)
		//ע���ʼ��
		PrintLoginInformation();
		input = InputCommand();
		if (input[0] == "1")
		{
			cout << "----�������û���" << endl;
			username = InputCommand()[0];
			cout << "----����������" << endl;
			password = InputCommand()[0];
			if (logger.Login(User(username, password)))
			{
				username_ = username;
				mode = 1;
				cout << "----��½�ɹ�" << endl;
			}
			else
				cout << "----�û������������" << endl;

		}

		else if (input[0] == "2")
		{
			cout << "----�������û���" << endl;
			username = InputCommand()[0];
			cout << "----����������" << endl;
			password = InputCommand()[0];
			if (logger.Signup(User(username, password)))
			{
				username_ = username;
				cout << "----ע��ɹ�" << endl;
			}
			else cout << "----ע��ʧ��" << endl;
		}

		else if (input[0] == "3")
		{
			mode = 2;
			username_ = "";
		}
		else
			cout << "----�������Ӧ�������" << endl;
		Pause();
		ClearScreen();
	}
}

void ShellWindows::Load(BasicDict &basic_dict, UserDict &user_dict)
{
	LoadBasicDictSimple load_basic_dict_simple;
	//LoadUserDictSimple load_user_dict_simple;
	//bool basic_dict_status = load_basic_dict_simple.Load("dict_txt_simple.txt", basic_dict);
	//bool user_dict_status = load_user_dict_simple.Load("userdata_" + username_ + ".txt", user_dict);
	//TODO:exception handle
	//basic_dict_status = user_dict_status = 0;//avoid the warning.
}

void ShellWindows::Save(UserDict & user_dict)
{
	//LoadUserDictSimple load_user_dict_simple;
	//load_user_dict_simple.Save("userdata_" + username_ + ".txt", user_dict);
}

void ShellWindows::PrintWelcome() const
{
	cout << "Palabra (plb) 0.01\n\
This is free software : you are free to change and redistribute it.\n\
For help, type \"help\".\n";
}