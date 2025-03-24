#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

// Headers to be included in all other source files
#include <iostream>
#include <regex>
#include <deque>
#include <set>
#include "math.h"

// Data structures by multiple classes
enum Input_Flag{
    INVALID  = 0,
    NUMBER   = 1,
    MATH_OP  = 2,
    STACK_OP = 3
};

struct User_Input{
    std::string input_string;
    Input_Flag  input_flag;
};

void shutdown_program();

#endif