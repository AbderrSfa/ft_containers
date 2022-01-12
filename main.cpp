#include "iterator.hpp"
#include <vector>
#include <iostream>

int     main() {
    ft::Integers<std::string>    integers;

    std::fill(integers.begin(), integers.end(), "lmao");
    ft::Iterator<std::string> begin = integers.begin();
    ft::Iterator<std::string> end = integers.end();
    while (begin != end)
    {
        std::cout << *begin << "\n";
        begin++;
    }
    
}