#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	{
		std::cout << "========== OG ==========" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		vec.resize(10, 8);

		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << std::endl;
		}
		std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
	}

	{
		std::cout << "========== MINE ==========" << std::endl;
		ft::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		vec.resize(10);

		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << std::endl;
		}
		std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
	}
}