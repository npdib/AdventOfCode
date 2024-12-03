// common.cpp 
// common code for day 1 and 2

#include "common.h"

int64_t parseMulCommand(const std::string& input, size_t pos)
{
	size_t leftLen = 0;
	size_t rightLen = 0;

	pos += 3;

	while (std::isdigit(input[++pos]))
		++leftLen;

	if (input[pos] != ',' || leftLen == 0)
		return 0;

	std::string str = input.substr(pos - leftLen, leftLen);
	const int16_t leftNum = std::stoi(str);

	while (std::isdigit(input[++pos]))
		++rightLen;

	if (input[pos] != ')' || rightLen == 0)
		return 0;

	const int16_t rightNum = std::stoi(input.substr(pos - rightLen, rightLen));

	return leftNum * rightNum;
}