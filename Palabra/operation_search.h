#pragma once
#ifndef OPERATION_SEARCH_H
#define OPERATION_SEARCH_H
#include<queue>
#include "operation.h"

class OperationSearch :
	public Operation
{
public:
	OperationSearch();
	virtual ~OperationSearch();
	virtual void Execute(const std::vector<std::string> &parameter);
private:
	std::vector<std::string> history_;
};


#endif  // !OPERATION_SEARCH_H