// main.cpp : Defines the entry point for the application.

#include "inputtaker.h"
#include <iostream>

std::string part1();
std::string part2();

int main()
{
	std::cout << part1() << std::endl;

	InputTaker::get().reset();

	std::cout << part2() << std::endl;

    return 0;
}
