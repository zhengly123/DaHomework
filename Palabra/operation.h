#pragma once
#ifndef OPERATION_H
#define OPERATION_Hs
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#ifdef _WIN32
#include<Windows.h>
#else //Linux
#include<unistd.h>
#endif // _WIN32
#include"user_dict.h"
#include"basic_dict.h"
//操作抽象类，是所有控制台操作的父类
class Operation
{
public:
	Operation(std::string command_name, std::string command_abbreviation,
		std::string help);
	virtual ~Operation();
	const std::string command_name_;
	const std::string command_abbreviation_;
	const std::string help_;
	// 执行命令
	virtual void Execute(const std::vector<std::string> &parameter) = 0;
protected:

	std::vector<std::string> InputCommand() const;
	// 清屏
	inline void ClearScreen() const;
	// 暂停
	void Pause(int time = 1000) const;
	virtual void PrintHelp() const = 0;
};

//**************************
//the definition of inline functions
//**************************
void Operation::ClearScreen() const
{
	//TODO:Linux测试
#ifdef _WIN32
	system("cls");
#else//Linux
	system("clear");
#endif // _WIN32
}

inline void Operation::Pause(int time) const
{
//#ifdef _MSC_VER//clang
//	Sleep(time);
//#else//非clang
//	sleep(time);
//#endif
	//TODO:Linux测试
#ifdef _WIN32
	Sleep(time);
#else//Linux
	sleep(time);
#endif // _WIN32
}

#endif  // !OPERATION_H

