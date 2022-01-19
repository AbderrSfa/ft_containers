#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int     main() {
    ft::vector<int>   f;
    ft::vector<int>::iterator   it = f.begin();
    ft::vector<int>::iterator   ite = f.end();

    std::cout << "size:\t\t" << f.size() << std::endl;
    std::cout << "capacity:\t" << f.capacity() << std::endl;
    std::cout << "max_size:\t" << f.max_size() << std::endl;
    std::cout << "empty:\t\t" << f.empty() << std::endl;
    ft::vector<int>::reverse_iterator   lol;

    std::vector<int>    vec;

    vec[0] = 5;
}