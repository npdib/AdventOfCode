// main.cpp : Defines the entry point for the application.

#include "inputtaker.h"
#include <iostream>

std::string part1();
std::string part2();

int main()
{
	std::cout << "Part 1:\t"  << part1() << std::endl;

	InputTaker::get().reset();

	std::cout << "Part 2:\t" << part2() << std::endl;

    return 0;
}
