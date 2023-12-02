// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

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
    std::fstream input("input.txt");
    std::string input_temp;
    char output[3] = { 'x', 'x', '\0' };

    uint32_t total = 0;
    uint8_t temp = 0;

    while (input >> input_temp)
    {
        for (int i = 0; i < input_temp.length(); i++)
        {
            if (isNum(int(input_temp[i])) and output[0] == 'x')
            {
                output[0] = input_temp[i];
            }

            if (isNum(input_temp[input_temp.length() - 1 - i]) and output[1] == 'x')
            {
                output[1] = input_temp[input_temp.length() - 1 - i];
            }

            if (output[0] != 'x' and output[1] != 'x')
            {
                break;
            }
        }

        total += atoi(output);
        output[0] = 'x';
        output[1] = 'x';
    }

    printf("the total for part 1 is:\t%d\n", total);
}

void Part2(void)
{
    std::string search_values[20] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    }; // an array of strings to search for

    int8_t first[20] = { 0 };
    int8_t last[20] = { 0 };  // buffers to hold positions to where the numbers appear   

    std::fstream input("input.txt"); // receive input from file

    std::string input_temp; // buffer to hold each line

    uint32_t total = 0; // variable to hold the sum

    while (input >> input_temp) // while there is more lines of data to read
    {
        for (int i = 0; i < 20; i++) // iterate through the position buffers
        {
            // set both to -1 as a N/A value
            first[i] = -1;
            last[i] = -1;

            // set both to actual values by searching through the string
            first[i] = input_temp.find(search_values[i].c_str());
            last[i] = input_temp.rfind(search_values[i].c_str());
            //printf("%d:%d, ", first[i], last[i]);
        }
        //printf("]\n");       

        /* setup temporary variables to hold the positions within the string
        * that the substrings were found and also which substring they correspond
        * to */
        int8_t first_pos = -1; // set to -1 as N/A value
        int8_t last_pos = -1; 
        int8_t first_value = 127; // set to largest so everything is smaller
        int8_t last_value = -1; // set to -1 so that everything is larger

        for (int i = 0; i < 20; i++)
        {
            //if (i == 0 or i == 10)
                //continue;

            if (first[i] < first_value and first[i] != -1)
            {
                first_pos = i;
                first_value = first[i];
            }

            if (last[i] > last_value and last[i] != -1)
            {
                last_pos = i;
                last_value = last[i];
            }
        }

        //printf("%d\t%d\n%d\t%d\n\n", first_value, last_value, first_pos, last_pos);

        /*printf("first_value:\t%d\tfirst_pos:\t%d\nlast_value:\t%d\tlast_pos:\t%d\n\n",
            first_value,
            first_pos,
            last_value,
            last_pos);*/

        char output[3] = { 'x', 'x', '\0' };

        switch (first_pos)
        {
        case 0:
        case 10:
            output[0] = '0';
            break;
        case 1:
        case 11:
            output[0] = '1';
            break;
        case 2:
        case 12:
            output[0] = '2';
            break;
        case 3:
        case 13:
            output[0] = '3';
            break;
        case 4:
        case 14:
            output[0] = '4';
            break;
        case 5:
        case 15:
            output[0] = '5';
            break;
        case 6:
        case 16:
            output[0] = '6';
            break;
        case 7:
        case 17:
            output[0] = '7';
            break;
        case 8:
        case 18:
            output[0] = '8';
            break;
        case 9:
        case 19:
            output[0] = '9';
            break;
        }

        switch (last_pos)
        {
        case 0:
        case 10:
            output[1] = '0';
            break;
        case 1:
        case 11:
            output[1] = '1';
            break;
        case 2:
        case 12:
            output[1] = '2';
            break;
        case 3:
        case 13:
            output[1] = '3';
            break;
        case 4:
        case 14:
            output[1] = '4';
            break;
        case 5:
        case 15:
            output[1] = '5';
            break;
        case 6:
        case 16:
            output[1] = '6';
            break;
        case 7:
        case 17:
            output[1] = '7';
            break;
        case 8:
        case 18:
            output[1] = '8';
            break;
        case 9:
        case 19:
            output[1] = '9';
            break;
        }

        uint8_t temp = atoi(output);

        total += temp;

    }

    printf("the total for part 2 is:\t%lu", total);
}



int main()
{
    Part1();

    Part2();
}