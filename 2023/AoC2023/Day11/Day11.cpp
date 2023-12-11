// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector<std::string> Matrix;

typedef struct coord_t
{
    uint16_t id, x, y;
    uint16_t x_exp = 0;
    uint16_t y_exp = 0;
} CoOrd;

std::vector<CoOrd> getGalaxies(void)
{
    Matrix universe;
    std::vector<CoOrd> galaxies;
    std::string line;
    std::ifstream input("input.txt");

    std::vector<uint16_t> horizontal_empty;
    std::vector<uint16_t> vertical_empty;

    uint16_t line_num = 0;
    while (std::getline(input, line)) // get input from file
    {
        bool empty = true;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != '.')
            {
                empty = false;
                break;
            }
        }

        if (empty) // add two for each empty line
        {
            horizontal_empty.push_back(line_num);
        }

        universe.push_back(line);
        line_num++;
    }

    for (int i = 0; i < universe[0].length(); i++) // iterate through each column
    {
        bool empty = true;
        for (int j = 0; j < universe.size(); j++) // iterate down the rows
        {
            if (universe[j][i] != '.')
            {
                empty = false;
            }
        }

        if (empty)
        {
            vertical_empty.push_back(i);
        }
    }

    uint16_t galaxy_num = 1;

    for (int y = 0; y < universe.size(); y++)
    {
        for (int x = 0; x < universe[y].length(); x++)
        {
            if (universe[y][x] == '#')
            {
                CoOrd galaxy;
                galaxy.id = galaxy_num++;
                galaxy.x = x;
                galaxy.y = y;

                for (auto v : vertical_empty)
                {
                    if (v < galaxy.x)
                        galaxy.y_exp++;
                }

                for (auto h : horizontal_empty)
                {
                    if (h < galaxy.y)
                        galaxy.x_exp++;
                }

                galaxies.push_back(galaxy);
            }
        }
    }

    return galaxies;
}

uint64_t countSteps(std::vector<CoOrd> galaxies, uint32_t expansion_coefficient = 2)
{
    uint64_t total = 0;

    for (auto g : galaxies)
    {
        for (auto h : galaxies)
        {
            if (h.id >= g.id) // only count each pair once
                continue;

            int16_t x_diff = g.x - h.x;
            if (x_diff < 0)
                x_diff *= -1;
            int16_t y_diff = g.y - h.y;
            if (y_diff < 0)
                y_diff *= -1;
            int16_t x_exp_diff = g.x_exp - h.x_exp;
            if (x_exp_diff < 0)
                x_exp_diff *= -1;
            int16_t y_exp_diff = g.y_exp - h.y_exp;
            if (y_exp_diff < 0)
                y_exp_diff *= -1;

            /*printf("id: %d\tx: %d\ty: %d\tx_expan: %d\ty_expan: %d\nid: %d\tx: %d\ty: %d\tx_expan: %d\ty_expan: %d\nx_diff: %d\ty_diff: %d\tx_exp_diff: %d\ty_exp_diff: %d\nsteps: %d\n\n",
                h.id, h.x, h.y, h.x_exp, h.y_exp,
                g.id, g.x, g.y, g.x_exp, g.y_exp,
                x_diff, y_diff, x_exp_diff, y_exp_diff,
                x_diff + y_diff + x_exp_diff + y_exp_diff);*/

            total += x_diff + y_diff + (expansion_coefficient-1) * (x_exp_diff + y_exp_diff);
        }
    }

    return total;
}

void Part1(void)
{
    std::vector<CoOrd> galaxies = getGalaxies();

    printf("the total for part 1 is:\t%llu\n", countSteps(galaxies));
}

void Part2(void)
{
    std::vector<CoOrd> galaxies = getGalaxies();

    printf("the total for part 2 is:\t%llu\n", countSteps(galaxies, 1000000));
}

int main()
{
    Part1();
    Part2();
}