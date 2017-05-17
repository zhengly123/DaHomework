#include "operation.h"
using namespace std;

Operation::Operation()
{
}


Operation::~Operation()
{

}

std::vector<std::string> Operation::InputCommand() const
{
	string input, parameter;
	getline(cin, input);

	istringstream iss(input);
	vector<string> array_of_parameter;
	while (iss >> parameter)
		array_of_parameter.push_back(parameter);
	return array_of_parameter;
}