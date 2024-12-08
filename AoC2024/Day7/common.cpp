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
