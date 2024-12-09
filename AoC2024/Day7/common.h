// common.h

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"

#include "utils.h"

long long int calculateSum(const uint64_t& target, const std::vector<int>& numbers, const uint32_t& map);
unsigned long long int calculateSumWithConcatenation(const uint64_t& target, const std::vector<int>& numbers, uint64_t map);