#pragma once
#ifndef SHELL_WINDOWS_H
#define SHELL_WINDOWS_H
#include<vector>
#include<string>
#include"operation.h"
#include"basic_dict.h"
#include"user_dict.h"
#include"load_basic_dict_simple.h"
#include"load_user_dict_simple.h"
//HACK:�Ƿ���Ҫ�̳�
class ShellWindows :Operation
{
public:
	ShellWindows();
	~ShellWindows();
	// CLI�������
	virtual void Execute(const std::vector<std::string> &parameter = std::vector<std::string>()) override;
private:
	std::string username_;

	void PrintWelcome() const;
	// ���������Ϣ
	void PrintHelp() const;
	void PrintLoginInformation() const;
	void Login();
	//����Dict��Preference����
	void Load(BasicDict &basic_dict, UserDict &user_dict);
	//����Dict
	void Save(UserDict &user_dict);
};

#endif  // !SHELL_WINDOWS_H
