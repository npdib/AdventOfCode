// Day4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

typedef struct card_t
{
    uint8_t id;
    uint32_t copies = 1;
} Scratchcard;

enum state_t
{
    Winners,
    Actual
};

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

void Part1(void)
{
    std::string line;
    std::ifstream input("input.txt");

    std::vector<uint8_t> winners;
    std::vector<uint8_t> actual;

    char temp[4];
    memset(temp, '\0', 4);
    uint8_t temp_ticker = 0;

    uint32_t total = 0;

    while (std::getline(input, line))
    {
        enum state_t State = Winners;

        uint8_t colon = line.find(":");

        for (int i = colon; i < line.length(); i++)
        {
            if (line[i] == '|')
            {
                State = Actual;
                continue;
            }

            switch (State)
            {
                case Winners:                
                    if (line[i] == ' ' and temp_ticker != 0)
                    {
                        winners.push_back(atoi(temp));
                        memset(temp, '\0', 4);
                        temp_ticker = 0;
                    }
                    if (isNum(line[i]))
                    {
                        temp[temp_ticker++] = line[i];
                    }
                    break;
                
                case Actual:                
                    if (line[i] == ' ' and temp_ticker != 0)
                    {
                        actual.push_back(atoi(temp));
                        memset(temp, '\0', 4);
                        temp_ticker = 0;
                    }
                    if (isNum(line[i]))
                    {
                        temp[temp_ticker++] = line[i];
                    }
                    break;
                
            }
        }

        if (temp_ticker != 0)
        {
            actual.push_back(atoi(temp));
            memset(temp, '\0', 4);
            temp_ticker = 0;
        }

        uint32_t score = 0;

        for (auto a : actual)
        {
            for (auto w : winners)
            {
                //printf("a: %d\tw: %d\n", a, w);
                if (a == w)
                {
                    if (!score)
                    {
                        score = 1;
                    }
                    else
                    {
                        score *= 2;
                    }
                    break;
                }
            }
        }

        total += score;

        //printf("score: %d\n", score);

        winners.clear();
        actual.clear();      

        //for (auto w : winners)
        //{
        //    printf("%d ", w);
        //}
        //printf("\n");
        //for (auto a : actual)
        //{
        //    printf("%d ", a);
        //}
        //printf("\n");
    }

    printf("the total for part 1 is: %d", total);
}

void Part2(void)
{
    std::string line;
    std::ifstream input("input.txt");

    std::vector<Scratchcard> Cards;
    uint8_t id = 1;

    while (std::getline(input, line))
    {
        Scratchcard temp;
        temp.id = id++;
        Cards.push_back(temp);
    }

    uint32_t total = 0;

    char temp[4];
    memset(temp, '\0', 4);
    uint8_t temp_ticker = 0;

    std::vector<uint8_t> winners;
    std::vector<uint8_t> actual;

    for (auto s = Cards.begin(); s != Cards.end(); s++)
    {
        
        std::ifstream input("input.txt");
        uint8_t line_counter = 0;
        while (line_counter++ != s->id)
        {
            std::getline(input, line);
        }

        enum state_t State = Winners;

        uint8_t colon = line.find(":");

        for (int i = colon; i < line.length(); i++)
        {
            if (line[i] == '|')
            {
                State = Actual;
                continue;
            }

            switch (State)
            {
            case Winners:
                if (line[i] == ' ' and temp_ticker != 0)
                {
                    winners.push_back(atoi(temp));
                    memset(temp, '\0', 4);
                    temp_ticker = 0;
                }
                if (isNum(line[i]))
                {
                    temp[temp_ticker++] = line[i];
                }
                break;

            case Actual:
                if (line[i] == ' ' and temp_ticker != 0)
                {
                    actual.push_back(atoi(temp));
                    memset(temp, '\0', 4);
                    temp_ticker = 0;
                }
                if (isNum(line[i]))
                {
                    temp[temp_ticker++] = line[i];
                }
                break;

            }
        }

        if (temp_ticker != 0)
        {
            actual.push_back(atoi(temp));
            memset(temp, '\0', 4);
            temp_ticker = 0;
        }

        uint32_t score = 0;

        for (auto a : actual)
        {
            for (auto w : winners)
            {
                if (a == w)
                {
                    score++;
                    break;
                }
            }
        }

        winners.clear();
        actual.clear();

        //printf("score: %d\n", score);

        uint16_t line_ticker = 1;

        while (score)
        {
            if (s->id + line_ticker > Cards.size())
            {
                break;
            }
            (s + line_ticker)->copies += s->copies;
            line_ticker++;
            score--;
        }        
    }

    for (auto s : Cards)
    {
        //printf("copies: %d\n", s.copies);
        total += s.copies;
    }    

    printf("the total for part 2 is: %d", total);
}

int main()
{
    Part1();
    printf("\n");
    Part2();
}