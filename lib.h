#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Lib
{
public:
    std::ifstream input;

    Lib() = default;
    Lib(std::string file);
};