#include <vector>
#include "vector.hpp"
#include <stack>
#include "stack.hpp"
#include <map>
#include <iterator>
#include "map.hpp"

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
			std::map<char, int>	mp;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			std::cout << "========= MINE =========" << std::endl;
			ft::map<char, int>	mp;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}