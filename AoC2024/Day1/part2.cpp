// Day1.cpp : Defines the entry point for the application.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"

std::string part2()
{
    std::list<int32_t> leftList, rightList;

	std::string input = InputTaker::readAll();

	while (InputTaker::get().moreToRead())
	{
	    std::string line = InputTaker::get().readLine();

		const size_t leftSize = line.find(' ');
		const size_t rightSize = line.find('\n') - (leftSize + 3);

		leftList.emplace_back(stoi(line.substr(0, leftSize)));
		rightList.emplace_back(stoi(line.substr(leftSize + 3, rightSize)));
	}

	int64_t simScore = 0;

	for (const auto& num : leftList)
	    simScore += num * std::ranges::count(rightList, num);

	std::stringstream retStr;
	retStr << "similarity score is " << simScore << std::endl;

	return retStr.str();
}