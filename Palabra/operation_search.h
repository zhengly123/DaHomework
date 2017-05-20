#pragma once
#ifndef OPERATION_SEARCH_H
#define OPERATION_SEARCH_H
#include<queue>
#include "operation.h"

class OperationSearch :
	public Operation
{
public:
	//OperationSearch();
	OperationSearch(const BasicDict &basic_dict, UserDict &user_dict);
	virtual ~OperationSearch();
	virtual void Execute(const std::vector<std::string> &parameter) override;
private:
	const BasicDict& basic_dict_;
	UserDict& user_dict_;
	std::vector<std::string> history_;
	virtual void PrintHelp() const override;
};


#endif  // !OPERATION_SEARCH_H