#include "operation.h"
using namespace std;

Operation::Operation(std::string command_name, std::string command_abbreviation,
	std::string help) :command_name_(command_name),
	command_abbreviation_(command_abbreviation), help_(help)
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