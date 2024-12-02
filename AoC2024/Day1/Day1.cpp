// Day1.cpp : Defines the entry point for the application.
//

#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <stdint.h>

#include "inputtaker.h"

void part1()
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


	leftList.sort();
	rightList.sort();

	int64_t diffSum = 0;

	for (auto leftIt = leftList.begin(), rightIt = rightList.begin(); leftIt != leftList.end(); ++leftIt, ++rightIt)
		diffSum += std::abs(*leftIt - *rightIt);

	std::cout << "sum of differences is " << diffSum << std::endl;

	InputTaker::get().reset();
}

void part2()
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

	std::cout << "similarity score is " << simScore << std::endl;

}

int main()
{
	part1();
	part2();
    return 0;
}
