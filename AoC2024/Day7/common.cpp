// common.cpp 
// common code for day 1 and 2

#include "common.h"

long long int calculateSum(const uint64_t& target, const std::vector<int>& numbers, const uint32_t& map)
{
    long long int sum = numbers[0];

    for (size_t index = 1; index < numbers.size(); ++index)
    {
        if (map & (1 << (index - 1)))
            sum += numbers[index];
        else
            sum *= numbers[index];

        if (sum > target)
            return 0;
    }

    return sum;
}

unsigned long long int calculateSumWithConcatenation(const uint64_t& target, const std::vector<int>& numbers,
    uint64_t map)
{
    unsigned long long int sum = numbers[0];

    for (size_t index = 1; index < numbers.size(); ++index)
    {
        switch (map % 3)
        {
        case 0:
            sum += numbers[index];
            break;
        case 1:
            sum *= numbers[index];
            break;
        case 2:
            sum *= static_cast<int>(pow(10.0, static_cast<unsigned>(log10(numbers[index]) + 1)));
            sum += numbers[index];
            break;
        }

        map /= 3;

        if (sum > target)
            return 0;
    }

    return sum;
}
