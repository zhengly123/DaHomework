#pragma once
#ifndef SHELL_WINDOWS_H
#define SHELL_WINDOWS_H
#include<vector>
#include<string>
#include"operation.h"
//HACK:是否需要继承
class ShellWindows :Operation
{
public:
	ShellWindows();
	~ShellWindows();
	// CLI运行入口
	virtual void Execute(const std::vector<std::string> &parameter = std::vector<std::string>()) override;
	// 输出帮助
private:
	std::string username_;
	void PrintWelcome() const;
	void PrintHelp() const;
	void PrintLoginInformation() const;
	void Login();
};

#endif  // !SHELL_WINDOWS_H
