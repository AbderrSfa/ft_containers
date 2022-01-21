#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	ft::vector<int> vec;

	vec.reserve(5);
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(10);
	std::cout << vec.size() << std::endl;
	vec.clear();
	std::cout << vec.size() << std::endl;
}