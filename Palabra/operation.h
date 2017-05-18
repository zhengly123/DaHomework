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

class Operation
{
public:
	Operation(std::string command_name, std::string command_abbreviation,
		std::string help);
	virtual ~Operation();
	const std::string command_name_;
	const std::string command_abbreviation_;
	const std::string help_;
	// ÷¥––√¸¡Ó
	virtual void Execute(const std::vector<std::string> &parameter) = 0;

protected:
	std::vector<std::string> InputCommand() const;
	// «Â∆¡
	inline void ClearScreen() const;
	// ‘›Õ£
	void Pause(int time = 1000) const;
};

//**************************
//the definition of inline functions
//**************************
void Operation::ClearScreen() const
{
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
//#else//∑«clang
//	sleep(time);
//#endif
#ifdef _WIN32
	Sleep(time);
#else//Linux
	sleep(time);
#endif // _WIN32
}

#endif  // !OPERATION_H

