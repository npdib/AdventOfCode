// Day8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <cmath>

typedef struct
{
    std::string left;
    std::string right;
} Node;

void Part1(std::string instruction, std::map<std::string, Node> Nodes)
{
    uint16_t instruction_counter = 0;
    uint32_t steps = 0;

    std::string current_node = "AAA";


    while (current_node != "ZZZ")
    {
        current_node = (instruction[instruction_counter++] == 'L') ? Nodes[current_node].left : Nodes[current_node].right;

        //printf("%s\n", current_node.name.c_str());

        instruction_counter %= instruction.length();
        steps++;
    }

    printf("Number of steps in part 1 is: %d\n", steps);
}

typedef struct test_node_t
{
    std::string name;
    uint32_t steps = 0;
} TestNode;

void Part2(std::string instruction, std::map<std::string, Node> Nodes)
{
    uint16_t instruction_counter = 0;
    uint64_t steps = 0;

    std::vector<TestNode> TestNodes;
    std::vector<uint16_t> finishVals;

    for (auto n : Nodes)
    {
        if (n.first[2] == 'A')
        {
            TestNode temp;
            temp.name = n.first;
            TestNodes.push_back(temp);
            //printf("%s\n", n.first.c_str());
        }
    }

    for (auto n = TestNodes.begin(); n != TestNodes.end(); n++)
    {
        while (n->name[2] != 'Z')
        {
            n->name = (instruction[instruction_counter++] == 'L') ? Nodes[n->name].left : Nodes[n->name].right;

            instruction_counter %= instruction.length();
            n->steps++;
        }

        finishVals.push_back(n->steps);
    }

    std::map<uint16_t, uint16_t> currentFactors;
    std::map<uint16_t, uint16_t> tempFactors;

    for (auto i : finishVals)
    {
        while (i != 1)
        {
            for (int j = 2; j <= i; j++)
            {
                if (i % j == 0)
                {
                    tempFactors[j]++;
                    i /= j;
                }
            }
        }

        for (auto f : tempFactors)
        {
            currentFactors[f.first] = std::max(f.second, currentFactors[f.first]);
        }

        tempFactors.clear();
    }

    double total = 1;

    for (auto f : currentFactors)
    {
        total *= pow(f.first, f.second);
    }

    printf("Number of steps in part 2 is: %.0f", total);
}

int main()
{
    std::string line;
    std::ifstream input("input.txt");
    std::string instruction;

    std::map<std::string, Node> Nodes;

    std::getline(input, instruction);
    std::getline(input, line);

    while (std::getline(input, line))
    {
        //printf("%s\n", line.c_str());
        Node temp_node;
        char temp_string[4];
        temp_string[3] = '\0';

        temp_string[0] = line[7];
        temp_string[1] = line[8];
        temp_string[2] = line[9];
        temp_node.left = temp_string;

        temp_string[0] = line[12];
        temp_string[1] = line[13];
        temp_string[2] = line[14];
        temp_node.right = temp_string;

        temp_string[0] = line[0];
        temp_string[1] = line[1];
        temp_string[2] = line[2];

        Nodes[temp_string] = temp_node;
    }

    Part1(instruction, Nodes);

    Part2(instruction, Nodes);
}