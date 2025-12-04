#include "lib.h"

Lib::Lib(std::string file)
{
    input.open(file);
    if (!input.is_open())
    {
        std::cout << "Input error." << std::endl;
        exit(1);
    }
}