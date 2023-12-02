// Day2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#define RED_MAX     12
#define GREEN_MAX   13
#define BLUE_MAX    14

void decode(std::string input, uint8_t& r, uint8_t& g, uint8_t& b)
{
    //printf("%s\n", input.c_str());

    uint8_t max_temp = 0;
    size_t pos = 0;
    uint8_t start = 0;

    char num_buff[4] = { 0 };
    memset(num_buff, '\0', 4);

    pos = input.find("red", 0);

    do
    {
        //printf("%d\n", pos);

        uint8_t num_pos_end = input.rfind(" ", pos);
        //printf("np_1: %d\n", num_pos_end);

        uint8_t num_pos_start = input.rfind(" ", pos - 2);
        //printf("np_2: %d\n", num_pos_start);

        uint8_t ticker = 0;
        memset(num_buff, '\0', 3);

        for (int i = num_pos_start + 1; i < num_pos_end; i++)
        {
            num_buff[ticker] = input[i];
            ticker++;
        }

        if (atoi(num_buff) > max_temp)
        {
            //printf("%c%c%c\n", input[pos - 2], input[pos - 1], input[pos]);
            max_temp = atoi(num_buff);
            //printf("%d\n", max_temp);
        }

        start = pos;
        pos = input.find("red", start + 1);

    } while (pos != -1);

    r = max_temp;

    max_temp = 0;
    start = 0;
    pos = input.find("green", 0);

    do
    {
        //printf("%d\n", pos);

        uint8_t num_pos_end = input.rfind(" ", pos);
        //printf("np_1: %d\n", num_pos_end);

        uint8_t num_pos_start = input.rfind(" ", pos - 2);
        //printf("np_2: %d\n", num_pos_start);

        memset(num_buff, '\0', 3);
        uint8_t ticker = 0;

        for (int i = num_pos_start + 1; i < num_pos_end; i++)
        {
            num_buff[ticker] = input[i];
            ticker++;
        }

        if (atoi(num_buff) > max_temp)
        {
            //printf("%c%c%c\n", input[pos - 2], input[pos - 1], input[pos]);
            max_temp = atoi(num_buff);
            //printf("%d\n", max_temp);
        }

        start = pos;
        pos = input.find("green", start + 1);

    } while (pos != -1);

    g = max_temp;

    max_temp = 0;
    start = 0;
    pos = input.find("blue", 0);

    do
    {
        //printf("%d\n", pos);

        uint8_t num_pos_end = input.rfind(" ", pos);
        //printf("np_1: %d\n", num_pos_end);

        uint8_t num_pos_start = input.rfind(" ", pos - 2);
        //printf("np_2: %d\n", num_pos_start);

        memset(num_buff, '\0', 3);
        uint8_t ticker = 0;

        for (int i = num_pos_start + 1; i < num_pos_end; i++)
        {
            num_buff[ticker] = input[i];
            ticker++;
        }

        if (atoi(num_buff) > max_temp)
        {
            //printf("%c%c%c\n", input[pos - 2], input[pos - 1], input[pos]);
            max_temp = atoi(num_buff);
            //printf("%d\n", max_temp);
        }

        start = pos;
        pos = input.find("blue", start + 1);

    } while (pos != -1);

    b = max_temp;
}

void Part1(void)
{
    std::ifstream input("input.txt");
    std::string input_line;

    uint32_t total = 0;
    uint16_t id = 1;

    while (std::getline(input, input_line))
    {
        uint8_t r, g, b;
        decode(input_line, r, g, b);

        printf("id:\t%d\tr:\t%d\tg:\t%d\tb:\t%d\n", id, r, g, b);

        if (r <= RED_MAX and g <= GREEN_MAX and b <= BLUE_MAX)
        {
            total += id;
        }

        id ++;
    }

    printf("total for part 1 is:\t%d\n", total);
}

void Part2(void)
{
    std::ifstream input("input.txt");
    std::string input_line;

    uint32_t total = 0;
    uint16_t id = 1;

    while (std::getline(input, input_line))
    {
        uint8_t r, g, b;
        decode(input_line, r, g, b);

        total += r * g * b;
    }

    printf("total for part 2 is:\t%d", total);
}

int main()
{
    Part1();
    Part2();
}