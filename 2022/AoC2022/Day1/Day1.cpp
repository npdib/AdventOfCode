// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>

#include <sstream>
#include <string>
#include <iostream>

void Part1(void)
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

        uint32_t temp;
        std::istringstream iss(line);
        iss >> temp;

        running_total += temp;
    }

    printf("\nfinal answer for part 1: %d\n", largest_total);

}

void Part2(void)
{
    std::string line;
    std::ifstream infile("input.txt");

    uint32_t largest_totals[3] = { 0 };
    uint32_t running_total = 0;

    printf("r_t\tl_t[0]\tl_t[1]\tl_t[2]\tsum\n");

    while (std::getline(infile, line))
    {
        if (line == "")
        {
            bool changed = false;
            for (int i = 0; i < 3; i++)
            {
                if (running_total > largest_totals[i])
                {
                    for (int j = 2; j > i; j--)
                    {
                        largest_totals[j] = largest_totals[j - 1];
                    }
                    largest_totals[i] = running_total;
                    changed = true;
                }

                if (changed)
                {
                    printf("%d,\t%d,\t%d,\t%d,\t%d\n", running_total, largest_totals[0], largest_totals[1], largest_totals[2], largest_totals[0] + largest_totals[1] + largest_totals[2]);
                    break;
                }
            }
            running_total = 0;
            continue;
        }

        uint32_t temp;
        std::istringstream iss(line);
        iss >> temp;

        running_total += temp;
    }

    printf("\nfinal answer for part 2: %d\n", largest_totals[0] + largest_totals[1] + largest_totals[2]);
}

int main()
{
    Part1();
    printf("\n");
    Part2();
}