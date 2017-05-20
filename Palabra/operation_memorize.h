#pragma once
#ifndef OPERATION_MEMORIZE_H
#define OPERATION_MEMORIZE_H
#include "operation.h"

class OperationMemorize :
	public Operation
{
public:
	OperationMemorize();
	virtual ~OperationMemorize();
	virtual void Execute(const std::vector<std::string> &parameter) override;
protected:
	virtual void PrintHelp() const override;
};

#endif  // !OPERATION_MEMORIZE_H