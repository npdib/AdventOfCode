// Day6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

#define STRING_LENGTH 18

bool isNum(int c)
{
    if (c >= 48 and c <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}

typedef struct game_t
{
    uint64_t time;
    uint64_t record = 0;
    uint64_t ways_to_beat = 0;
} Game;

std::vector<Game> parseGamesPart1(void)
{
    std::fstream input("input.txt");
    std::string line;
    std::vector<Game> Games;

    input >> line;
    while (input >> line)
    {
        if (!isNum(line[0]))
        {
            break;
        }

        uint8_t temp_ticker = 0;
        char temp[STRING_LENGTH];
        memset(temp, '\0', STRING_LENGTH);

        for (int i = 0; i < line.length(); i++)
        {
            temp[temp_ticker++] = line[i];
        }

        Game temp_game;
        temp_game.time = atoi(temp);
        Games.push_back(temp_game);
    }

    for (auto g = Games.begin(); g != Games.end(); g++)
    {
        if (!(input >> line))
        {
            break;
        }

        uint8_t temp_ticker = 0;
        char temp[STRING_LENGTH];
        memset(temp, '\0', STRING_LENGTH);

        for (int i = 0; i < line.length(); i++)
        {
            temp[temp_ticker++] = line[i];
        }

        g->record = atoi(temp);
    }

    return Games;
}

Game parseGamePart2(void)
{
    std::fstream input("input.txt");
    std::string line;
    Game Game;

    uint8_t temp_ticker = 0;
    char temp[STRING_LENGTH];
    memset(temp, '\0', STRING_LENGTH);

    input >> line;
    while (input >> line)
    {
        if (!isNum(line[0]))
        {
            Game.time = strtoul(temp, nullptr, 0);
            temp_ticker = 0;
            memset(temp, '\0', STRING_LENGTH);
            continue;
        }        

        for (int i = 0; i < line.length(); i++)
        {
            temp[temp_ticker++] = line[i];
        }        
    }

    Game.record = strtoull(temp, nullptr, 0);

    printf("Time: %lu\tRecord: %llu\n", Game.time, Game.record);

    return Game;
}

int main()
{
    std::vector<Game> Games = parseGamesPart1();

    uint32_t total = 1;

    for (auto g = Games.begin(); g != Games.end(); g++)
    {
        for (int i = 1; i < g->time; i++)
        {
            if ((g->time - i) * i > g->record)
            {
                g->ways_to_beat++;
            }
        }

        total *= g->ways_to_beat;
    }

    printf("total for part 1 is: %lu\n\n", total);

    Game Game = parseGamePart2();
    total = 1;

    for (int i = 1; i < Game.time; i++)
    {
        if ((Game.time - i) * i > Game.record)
        {
            Game.ways_to_beat++;
        }
    }

    total *= Game.ways_to_beat;

    printf("total for part 1 is: %lu", total);
}