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
//HACK:是否需要继承
class ShellWindows :Operation
{
public:
	ShellWindows();
	~ShellWindows();
	// CLI运行入口
	virtual void Execute(const std::vector<std::string> &parameter = std::vector<std::string>()) override;
private:
	std::string username_;

	void PrintWelcome() const;
	// 输出帮助信息
	void PrintHelp() const;
	void PrintLoginInformation() const;
	void Login();
	//载入Dict、Preference设置
	void Load(BasicDict &basic_dict, UserDict &user_dict);
	//保存Dict
	void Save(UserDict &user_dict);
};

#endif  // !SHELL_WINDOWS_H
