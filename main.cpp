#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::vector<int> vec2;
			vec2.push_back(1);
			vec2.push_back(2);
			vec2.push_back(3);
			vec2.push_back(4);
			vec2.push_back(5);
			std::vector<int> vec(vec2.begin(), vec2.end());

			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << std::endl;
			std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			std::cout << "========== MINE ==========" << std::endl;
			ft::vector<int> vec2;
			vec2.push_back(1);
			vec2.push_back(2);
			vec2.push_back(3);
			vec2.push_back(4);
			vec2.push_back(5);
			ft::vector<int> vec(vec2.begin(), vec2.end());

			for (size_t i = 0; i < vec.size(); i++)
				std::cout << vec[i] << std::endl;
			std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}