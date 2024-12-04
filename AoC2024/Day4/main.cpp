// main.cpp : Defines the entry point for the application.

#include "inputtaker.h"
#include <iostream>

namespace Part1
{
    std::string run();
}

namespace Part2
{
    std::string run();
}

int main()
{
	std::cout << "Part 1:\t"  << Part1::run() << std::endl;

	InputTaker::get().reset();

	std::cout << "Part 2:\t" << Part2::run() << std::endl;

    return 0;
}
