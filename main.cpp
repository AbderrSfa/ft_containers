#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	ft::vector<int> vec;

	/*    std::cout << "size:\t\t" << vec.size() << std::endl;
		std::cout << "capacity:\t" << vec.capacity() << std::endl;
		std::cout << "max_size:\t" << vec.max_size() << std::endl;
		std::cout << "empty:\t\t" << vec.empty() << std::endl;*/

	/*    std::cout << vec.size() << std::endl;
		vec.push_back(5);
		std::cout << vec.size() << std::endl;
		vec.pop_back();
		std::cout << vec.size() << std::endl;
		std::cout << vec[0] << std::endl;*/

	vec.push_back(5);
	vec.push_back(10);
	std::cout << vec.size() << std::endl;
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	vec.clear();
	std::cout << vec.size() << std::endl;
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
}