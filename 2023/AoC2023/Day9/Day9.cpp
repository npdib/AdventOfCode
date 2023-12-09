// Day9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

/* Checks if all values in a row are equal
    In this situation the next row would be all 0s
    */
bool allSame(std::vector<int32_t> row)
{
    int32_t val = row[0];
    for (auto e : row)
    {
        if (e != val)
        {
            return false;
        }
        val = e;
    }

    return true;
}

void printHistory(std::vector<std::vector<int32_t>> history)
{
    for (auto a : history)
    {
        for (auto b : a)
        {
            printf("%d\t", b);
        }
        printf("\n");
    }
}

void Part1(void)
{
    std::fstream input("input.txt");
    int32_t value;

    int32_t total = 0;

    while (input >> value) // read number into value
    {
        std::vector<std::vector<int32_t>> History;
        std::vector<int32_t> rowOne; // initialise temporary vector
        rowOne.push_back(value); // push value into vector
        for (int i = 1; i < 21; i++) // for rest of numbers in row
        {
            input >> value; // read number
            rowOne.push_back(value); // add number to row
            //printf("%d ", value);
        }
        History.push_back(rowOne); // push row to history

        uint8_t row = 0;
        while (!allSame(History[row]))
        {
            std::vector<int32_t> newRow; // hold new row values
            for (int i = 0; i < History[row].size() - 1; i++) // iterate through the row
            {
                newRow.push_back(History[row][i + 1] - History[row][i]); // take difference of elements
            }
            History.push_back(newRow); // add new row to the vector
            row++; // increment the row number
        }

        row++;
        while (--row)
        {
            History[row - 1].push_back(History[row - 1].back() + History[row].back());
        }

        //printHistory(History);

        total += History[0].back();
    }

    printf("total for part 1 is %ld\n", total);
}

void Part2(void)
{
    std::fstream input("input.txt");
    int32_t value;

    int32_t total = 0;

    while (input >> value) // read number into value
    {
        std::vector<std::vector<int32_t>> History;
        std::vector<int32_t> rowOne; // initialise temporary vector
        rowOne.push_back(value); // push value into vector
        for (int i = 1; i < 21; i++) // for rest of numbers in row
        {
            input >> value; // read number
            rowOne.push_back(value); // add number to row
            //printf("%d ", value);
        }
        History.push_back(rowOne); // push row to history

        uint8_t row = 0;
        while (!allSame(History[row]))
        {
            std::vector<int32_t> newRow; // hold new row values
            for (int i = 0; i < History[row].size() - 1; i++) // iterate through the row
            {
                newRow.push_back(History[row][i + 1] - History[row][i]); // take difference of elements
            }
            History.push_back(newRow); // add new row to the vector
            row++; // increment the row number
        }

        row++;
        while (--row)
        {
            History[row - 1].insert(History[row - 1].begin(), History[row - 1].front() - History[row].front());
        }

        //printHistory(History);

        total += History[0].front();
    }

    printf("total for part 2 is %ld\n", total);
}


int main()
{
    Part1();
    Part2();
}