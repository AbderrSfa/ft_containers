#include "vector.hpp"
#include "iterator.hpp"
#include <vector>
#include <stack>
#include <map>

int     main() {
    ft::Integers<std::string>    integers;

    std::fill(integers.begin(), integers.end(), "lmao");
    ft::Integers<std::string>::Iterator begin = integers.begin();
    ft::Integers<std::string>::Iterator end = integers.end();
    while (begin != end)
    {
        std::cout << *begin << "\n";
        begin++;
    }
    
}