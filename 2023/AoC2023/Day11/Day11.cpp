// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector<std::string> Matrix;

typedef struct
{
    uint16_t id, x, y;
} CoOrd;

Matrix createUniverse(std::vector<CoOrd>& galaxies)
{
    Matrix universe;
    std::string line;
    std::ifstream input("input.txt");

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
            universe.push_back(line);
        }

        universe.push_back(line);
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
            for (int j = 0; j < universe.size(); j++) // iterate down the rows
            {
                universe[j].insert(i, "."); // add a new value for each one and increment the ticker for i
            }
            i++;
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
                galaxies.push_back(galaxy);
            }
        }
    }

    return universe;
}

void printMatrix(Matrix m)
{
    for (int i = 0; i < m.size(); i++)
    {
        printf("%s\n", m[i].c_str());
    }
}

void Part1(void)
{
    std::vector<CoOrd> galaxies;
    Matrix universe = createUniverse(galaxies);

    uint32_t total = 0;

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

            total += x_diff + y_diff;
        }
    }

    printf("the total for part 1 is:%d\n", total);
}

int main()
{
    Part1();
}