#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

/*{
	std::cout << BLUE;
	for (size_t i = 0; i < this->capacity(); i++)
	{
		if (i == this->size())
			std::cout << MAGENTA;
		std::cout << this->_m_data[i] << " | ";
	}
	std::cout << RESET << std::endl;
}*/

int		main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::vector<int> vec2;
			vec2.push_back(-11);
			vec2.push_back(-22);
			vec2.push_back(-33);
			vec2.push_back(-44);
			std::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			vec.push_back(6);
			vec.push_back(7);

			vec.swap(vec2);
			std::cout << "vec: " << GREEN;
			for (size_t i = 0; i < vec.capacity(); i++)
			{
				if (i == vec.size())
					std::cout << RED;
				std::cout << vec[i] << " | ";
			}
			std::cout << RESET << std::endl;
			std::cout << "vec: size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
			std::cout << "vec2: " << GREEN;
			for (size_t i = 0; i < vec2.capacity(); i++)
			{
				if (i == vec2.size())
					std::cout << RED;
				std::cout << vec2[i] << " | ";
			}
			std::cout << RESET << std::endl;
			std::cout << "vec2: size: " << vec2.size() << " capacity: " << vec2.capacity() << std::endl;
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
			vec2.push_back(-11);
			vec2.push_back(-22);
			vec2.push_back(-33);
			vec2.push_back(-44);
			ft::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			vec.push_back(6);
			vec.push_back(7);

			vec.swap(vec2);
			std::cout << "vec: " << GREEN;
			for (size_t i = 0; i < vec.capacity(); i++)
			{
				if (i == vec.size())
					std::cout << RED;
				std::cout << vec[i] << " | ";
			}
			std::cout << RESET << std::endl;
			std::cout << "vec: size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
			std::cout << "vec2: " << GREEN;
			for (size_t i = 0; i < vec2.capacity(); i++)
			{
				if (i == vec2.size())
					std::cout << RED;
				std::cout << vec2[i] << " | ";
			}
			std::cout << RESET << std::endl;
			std::cout << "vec2: size: " << vec2.size() << " capacity: " << vec2.capacity() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}