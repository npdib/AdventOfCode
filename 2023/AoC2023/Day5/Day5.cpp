// Day5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<vector>
#include<sstream>

typedef enum task_t
{
    InterpretSeeds,
    Blank,
    InterpretMapHeader,
    AddRowToHeader
} Task;

typedef struct header_t
{
    std::string source;
    std::string destination;
} Header;

typedef struct map_t
{
    uint32_t source;
    uint32_t destination;
    uint32_t length;
} Map;

typedef struct mapping_t
{
    Header header;
    std::vector<Map> mapping;
} Mapping;

struct current_value_t
{
    std::string type;
    uint32_t value;
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

Task CategoriseLine(std::string line)
{
    if (!line.size())
    {
        return Blank;
    }
    else if (line.find("-to-") != (-1))
    {
        return InterpretMapHeader;
    }
    else if (line.find("seeds:") != (-1))
    {
        return InterpretSeeds;
    }
    else
    {
        return AddRowToHeader;
    }
}

std::vector<uint32_t> ParseSeedsPart1(std::string line)
{
    char temp[12];
    uint8_t temp_ticker = 0;
    memset(temp, '\0', 12);

    std::vector<uint32_t> temp_seeds;

    for (int i = 0; i < line.size(); i++)
    {
        if (isNum(line[i]))
        {
            temp[temp_ticker++] = line[i];
        }

        if ((line[i] == ' ' and temp_ticker != 0) or i == line.size() - 1)
        {
            uint32_t seed = strtoull(temp, NULL, 0);
            temp_seeds.push_back(seed);
            memset(temp, '\0', 12);
            temp_ticker = 0;
        }
    }

    for (auto s : temp_seeds)
    {
        printf("%lu\n", s);
    }

    return temp_seeds;
}

typedef enum
{
    Source,
    Length
} SeedTask;

std::vector<uint32_t> ParseSeedsPart2(std::string line)
{
    char temp[12];
    uint8_t temp_ticker = 0;
    memset(temp, '\0', 12);

    SeedTask current_task = Source;
    uint32_t source = 0;

    std::vector<uint32_t> temp_seeds;

    for (int i = 0; i < line.size(); i++)
    {
        if (isNum(line[i]))
        {
            temp[temp_ticker++] = line[i];
        }

        if ((line[i] == ' ' and temp_ticker != 0) or i == line.size() - 1)
        {
            uint32_t seed = strtoull(temp, NULL, 0);

            switch (current_task)
            {
            case Source:
                source = seed;
                current_task = Length;
                break;
            case Length:
                while (seed--)
                {
                    temp_seeds.push_back(source++);
                }
                current_task = Source;
                break;
            }            
            memset(temp, '\0', 12);
            temp_ticker = 0;
        }
    }

    for (auto s : temp_seeds)
    {
        printf("%lu\n", s);
    }

    return temp_seeds;
}

void SetUpMapHeader(Mapping& mapping, std::string line)
{
    uint8_t to_num = line.find("-to-");
    uint8_t start_src = 0;
    uint8_t end_dst = line.find(" ", to_num);

    mapping.header.source = line.substr(start_src, to_num);
    mapping.header.destination = line.substr(to_num + 4, end_dst - to_num - 4);
}

void AddRow(Mapping& mapping, std::string line)
{
    char temp[12];
    memset(temp, '\0', 12);
    uint8_t temp_ticker = 0;
    uint8_t value_ticker = 0;
    uint32_t values[3] = { 0 };

    for (int i = 0; i < line.length(); i++)
    {
        if (isNum(line[i]))
        {
            temp[temp_ticker++] = line[i];
        }

        if ((line[i] == ' ' and temp_ticker != 0) or i == line.size() - 1)
        {
            values[value_ticker++] = strtoull(temp, NULL, 0);
            memset(temp, '\0', 12);
            temp_ticker = 0;
        }
    }

    Map map_temp;
    map_temp.destination = values[0];
    map_temp.source = values[1];
    map_temp.length = values[2];
    mapping.mapping.push_back(map_temp); 
}

uint32_t TranslateInputs(std::vector<Mapping> mappings, std::vector<uint32_t> inputs)
{
    uint32_t lowest_output = 0xffffffff;
    for (auto seed : inputs)
    {
        current_value_t CurrentValue;
        CurrentValue.type = "seed";
        CurrentValue.value = seed;

        while (CurrentValue.type != "location")
        {
            //printf("type: %s\tvalue: %lu\n", CurrentValue.type.c_str(), CurrentValue.value);
            for (auto mapping : mappings)
            {
                if (mapping.header.source != CurrentValue.type)
                {
                    continue;
                }

                for (auto value : mapping.mapping)
                {
                    if (!((CurrentValue.value >= value.source) and (CurrentValue.value <= value.source + value.length - 1)))
                    {
                        continue;
                    }

                    CurrentValue.value = value.destination + (CurrentValue.value - value.source);
                    break;
                }

                CurrentValue.type = mapping.header.destination;
                break;
            }
        }

        //printf("type:\t%s\nvalue:\t%d\n", CurrentValue.type.c_str(), CurrentValue.value);

        if (CurrentValue.value < lowest_output)
        {
            lowest_output = CurrentValue.value;
        }

        printf("\n");
    }

    return lowest_output;
}


uint32_t findSeed(std::vector<Mapping> mappings, std::vector<uint32_t> inputs)
{
    uint32_t counter = 0;
    current_value_t CurrentValue;
    CurrentValue.type = "location";
    CurrentValue.value = 0;
    while (true)
    {
        CurrentValue.value = counter++;
        CurrentValue.type = "location";

        while (CurrentValue.type != "seed")
        {
            //printf("type: %s\tvalue: %lu\n", CurrentValue.type.c_str(), CurrentValue.value);
            for (auto mapping : mappings)
            {
                if (mapping.header.destination != CurrentValue.type)
                {
                    continue;
                }

                for (auto value : mapping.mapping)
                {
                    if (!((CurrentValue.value >= value.destination) and (CurrentValue.value < value.destination + value.length)))
                    {
                        continue;
                    }

                    CurrentValue.value = value.source + (CurrentValue.value - value.destination);
                    break;
                }

                CurrentValue.type = mapping.header.source;
                break;
            }
        }

        bool range = false;
        bool contained = false;
        uint32_t prev = 0;
        for (auto i : inputs)
        {
            if (!range)
            {
                prev = i;
            }
            else
            {
                if (CurrentValue.value >= prev and CurrentValue.value < prev + i)
                {
                    contained = true;
                    break;
                }
            }

            range = !range;
        }

        if (counter % 1000000 == 0)
            printf("type:\t%s\nseed:\t%lu\nlocation:\t%lu\n", CurrentValue.type.c_str(), CurrentValue.value, counter);

        if (contained)
        {
            return counter--;
        }
    }
}

void Part1(void)
{
    std::string line;
    std::ifstream input("input.txt");

    std::vector<uint32_t> Seeds;
    std::vector<Mapping> Mappings;
    Mapping temp_mapping;

    Task CurrentTask = InterpretSeeds;

    bool temp_map_exists = false;


    while (std::getline(input, line))
    {
        CurrentTask = CategoriseLine(line);

        switch (CurrentTask)
        {
        case Blank:
            //printf("Blank\n");
            if (temp_map_exists)
            {
                Mappings.push_back(temp_mapping);
                temp_mapping.mapping.clear();
                temp_map_exists = false;
            }
            break;
        case InterpretMapHeader:
        {
            //printf("MapHeader\n");
            SetUpMapHeader(temp_mapping, line);           

            temp_map_exists = true;
            break;
        }
        case InterpretSeeds:
            //printf("Seeds\n");
            Seeds = ParseSeedsPart1(line);
            break;
        case AddRowToHeader:
            //printf("Row\n");
            AddRow(temp_mapping, line);
            break;
        }
    }

    if (temp_map_exists)
    {
        Mappings.push_back(temp_mapping);
    }

    for (auto m : Mappings)
    {
        printf("source:\t\t%s\ndestination:\t%s\n", m.header.source.c_str(), m.header.destination.c_str());
        for (auto map : m.mapping)
        {
            printf("%d -> %d\n", map.source, map.destination);
        }
        printf("\n");
    }

    uint32_t lowest_seed = TranslateInputs(Mappings, Seeds);

    printf("lowest output for part 1 is: %lu", lowest_seed);
}


void Part2(void)
{
    std::string line;
    std::ifstream input("input.txt");

    std::vector<uint32_t> Seeds;
    std::vector<Mapping> Mappings;
    Mapping temp_mapping;

    Task CurrentTask = InterpretSeeds;

    bool temp_map_exists = false;


    while (std::getline(input, line))
    {
        CurrentTask = CategoriseLine(line);

        switch (CurrentTask)
        {
        case Blank:
            //printf("Blank\n");
            if (temp_map_exists)
            {
                Mappings.push_back(temp_mapping);
                temp_mapping.mapping.clear();
                temp_map_exists = false;
            }
            break;
        case InterpretMapHeader:
        {
            //printf("MapHeader\n");
            SetUpMapHeader(temp_mapping, line);

            temp_map_exists = true;
            break;
        }
        case InterpretSeeds:
            //printf("Seeds\n");
            Seeds = ParseSeedsPart1(line);
            break;
        case AddRowToHeader:
            //printf("Row\n");
            AddRow(temp_mapping, line);
            break;
        }
    }

    if (temp_map_exists)
    {
        Mappings.push_back(temp_mapping);
    }

    for (auto m : Mappings)
    {
        printf("source:\t\t%s\ndestination:\t%s\n", m.header.source.c_str(), m.header.destination.c_str());
        for (auto map : m.mapping)
        {
            printf("%d -> %d\n", map.source, map.destination);
        }
        printf("\n");
    }

    uint32_t value = findSeed(Mappings, Seeds);

    printf("lowest contained seed is %lu", value);
}

int main()
{
    //Part1();

    Part2();
}