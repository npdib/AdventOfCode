// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>

#include <sstream>
#include <string>
#include <iostream>

int main()
{
    std::string line; 
    std::ifstream infile("input.txt");

    uint32_t largest_total = 0;
    uint32_t running_total = 0;

    while (std::getline(infile, line))
    {
        if (line == "")
        {
            if (running_total > largest_total)
            {
                largest_total = running_total;
                printf("%d\n", largest_total);
            }
            running_total = 0;
            continue;
        }

        uint16_t temp;
        std::istringstream iss(line);
        iss >> temp;

        running_total += temp;
    }
}