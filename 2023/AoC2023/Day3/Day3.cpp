// Day3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

typedef struct part_number_t
{
    uint16_t value = 0;
    uint8_t start_pos;
    uint8_t end_pos;
    bool check = false;
    bool part = false;
} PartNumber;

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

bool isSym(char c)
{
    if (c >= 35 and c <= 64)
    {
        if (!isNum(c) and c != '.')
        {
            return true;
        }
    }

    return false;
}

bool removeElement(PartNumber& p)
{
    if (p.check)
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
    std::fstream input("input.txt");
    std::string input_temp; 
    bool in_number = false;
    char num_temp[4];
    uint8_t num_temp_tick = 0;
    memset(num_temp, '\0', 4);
    PartNumber temp;

    uint32_t total = 0;

    std::vector<PartNumber> parts;
    std::vector<uint8_t> symbols;
    std::vector<uint8_t> prev_symbols;

    while (input >> input_temp)
    {
        for (int i = 0; i < input_temp.length(); i++)
        {
            if (isSym(input_temp[i]))
            {
                symbols.push_back(i);
            }

            if (!in_number and isNum(input_temp[i]))
            {
                in_number = true;
                temp.start_pos = i;
            }

            if (in_number and !isNum(input_temp[i]))
            {
                in_number = false;
                temp.value = atoi(num_temp);
                memset(num_temp, '\0', 4);
                num_temp_tick = 0;
                temp.end_pos = i - 1;

                for (int i : prev_symbols)
                {
                    if (i >= temp.start_pos - 1 and i <= temp.end_pos + 1)
                    {
                        temp.part = true;
                    }

                }

                parts.push_back(temp);

                temp.part = false;
            }

            if (in_number)
            {
                num_temp[num_temp_tick] = input_temp[i];
                num_temp_tick++;
            }
        }

        if (in_number)
        {
            in_number = false;
            temp.value = atoi(num_temp);
            memset(num_temp, '\0', 4);
            num_temp_tick = 0;
            temp.end_pos = input_temp.length() - 1;

            for (int i : prev_symbols)
            {
                if (i >= temp.start_pos - 1 and i <= temp.end_pos + 1)
                {
                    temp.part = true;
                }
            }

            parts.push_back(temp);

            temp.part = false;
        }

        std::vector<PartNumber>::iterator it;

        for (it = parts.begin(); it != parts.end(); it++)
        {
            for (int i : symbols) // symbols just found
            {
                if (!it->check) // row just done
                {
                    if (i == it->start_pos - 1 or i == it->end_pos + 1)
                    {
                        it->part = true;
                    }
                }
                else // previous row
                {
                    if (i >= it->start_pos - 1 and i <= it->end_pos + 1)
                    {
                        it->part = true;
                    }
                }
            }
        }



        prev_symbols.clear();
        prev_symbols = symbols;
        symbols.clear();

        for (PartNumber p : parts)
        {
            if (p.check and p.part)
            {
                total += p.value;
            }

            //printf("%d: %d: %d,\t", p.value, p.check, p.part);
        }

        //printf("\n");

        parts.erase(std::remove_if(parts.begin(), parts.end(), removeElement), parts.end());

        for (it = parts.begin(); it != parts.end(); it++)
        {
            it->check = true;
        }
    }

    for (PartNumber p : parts)
    {
        if (p.check and p.part)
        {
            total += p.value;
        }

        //printf("%d: %d: %d,\t", p.value, p.check, p.part);
    }

    printf("%d\n", total);
}

void Part2(void)
{

}

int main()
{
    Part1();

    Part2();
}