// main.cpp : Defines the entry point for the application.

#include "inputtaker.h"
#include "utils.h"
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
    util::SimpleTimer timer;

	std::cout << "Part 1:\t" << timer << Part1::run() << timer << std::endl;

	InputTaker::get().reset();

	std::cout << "Part 2:\t" << timer << Part2::run() << timer << std::endl;

    return 0;
}
