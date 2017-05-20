#pragma once
#ifndef OPERATION_MEMORIZE_H
#define OPERATION_MEMORIZE_H
#include "operation.h"

class OperationMemorize :
	public Operation
{
public:
	OperationMemorize(const BasicDict &basic_dict, UserDict &user_dict);
	virtual ~OperationMemorize();
	virtual void Execute(const std::vector<std::string> &parameter) override;
protected:
	const BasicDict& basic_dict_;
	UserDict& user_dict_;
	virtual void PrintHelp() const override;
};

#endif  // !OPERATION_MEMORIZE_H