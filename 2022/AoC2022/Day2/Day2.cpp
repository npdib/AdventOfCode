// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>

#define WIN         6
#define DRAW        3
#define LOSS        0

#define ROCK        1
#define PAPER       2
#define SCISSORS    3

int RPSPart1(char in1, char in2)
{
    switch (in1)
    {
    case 'A':
        switch (in2)
        {
        case 'X':
            return ROCK + DRAW;
        case 'Y':
            return PAPER + WIN;
        case 'Z':
            return SCISSORS + LOSS;
        }
        break;
    case 'B':
        switch (in2)
        {
        case 'X':
            return ROCK + LOSS;
        case 'Y':
            return PAPER + DRAW;
        case 'Z':
            return SCISSORS + WIN;
        }
        break;
    case 'C':
        switch (in2)
        {
        case 'X':
            return ROCK + WIN;
        case 'Y':
            return PAPER + LOSS;
        case 'Z':
            return SCISSORS + DRAW;
        }
        break;
    }
}

int RPSPart2(char in1, char in2)
{
    switch (in1)
    {
    case 'A':
        switch (in2)
        {
        case 'X':
            return SCISSORS + LOSS;
        case 'Y':
            return ROCK + DRAW;
        case 'Z':
            return PAPER + WIN;
        }
        break;
    case 'B':
        switch (in2)
        {
        case 'X':
            return ROCK + LOSS;
        case 'Y':
            return PAPER + DRAW;
        case 'Z':
            return SCISSORS + WIN;
        }
        break;
    case 'C':
        switch (in2)
        {
        case 'X':
            return PAPER + LOSS;
        case 'Y':
            return SCISSORS + DRAW;
        case 'Z':
            return ROCK + WIN;
        }
        break;
    }
}

void Part1(void)
{
    std::ifstream infile("input.txt");

    char a, b;
    uint32_t total_score = 0;

    while (infile >> a >> b)
    {
        total_score += RPSPart1(a, b);
    }

    printf("final score is: %d\n", total_score);
}

void Part2(void)
{
    std::ifstream infile("input.txt");

    char a, b;
    uint32_t total_score = 0;

    while (infile >> a >> b)
    {
        total_score += RPSPart2(a, b);
    }

    printf("final score is: %d\n", total_score);
}

int main()
{
    Part1();

    printf("\n");

    Part2();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
