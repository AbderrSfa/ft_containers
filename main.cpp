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
			std::vector<int> vecd;
			std::vector<int> vec(5, -1);

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
			ft::vector<int> vecd;
			ft::vector<int> vec(5, -1);

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