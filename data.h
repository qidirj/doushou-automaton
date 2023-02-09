/*
data.h
Constant data and necessary global variables go here.
*/

#ifndef DATA_H
#define DATA_H

#include <random>

std::mt19937_64 rng;
const int levelCounts[][5] = {
    {0, 0, 0, 0, 0}, // 0
    {0, 1, 0, 0, 0}, // 1
    {0, 1, 0, 1, 0}, // 2
    {0, 1, 1, 1, 0}, // 3
    {0, 1, 1, 1, 1}, // 4
    {0, 2, 1, 1, 1}, // 5
    {0, 2, 2, 1, 1}, // 6
    {0, 2, 2, 2, 1}, // 7
    {0, 3, 2, 2, 1}, // 8
    {0, 3, 2, 2, 2}, // 9
    {0, 3, 2, 3, 2}, // 10
};

#endif
