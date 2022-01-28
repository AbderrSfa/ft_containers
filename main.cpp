#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <stack>
#include <map>
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

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::vector<int> vec2(5, -1);
			std::vector<int> vec(5, -1);

			std::cout << GREEN;
			for (size_t i = 0; i < vec.capacity(); i++)
			{
				if (i == vec.size())
					std::cout << RED;
				std::cout << vec[i] << " | ";
			}
			std::cout << RESET << std::endl;
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
			ft::vector<int> vec2(5, -1);
			ft::vector<int> vec(5, -1);

			std::cout << GREEN;
			for (size_t i = 0; i < vec.capacity(); i++)
			{
				if (i == vec.size())
					std::cout << RED;
				std::cout << vec[i] << " | ";
			}
			std::cout << RESET << std::endl;
			std::cout << "size: " << vec.size() << " capacity: " << vec.capacity() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}