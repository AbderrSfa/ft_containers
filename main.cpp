#include "vector.hpp"
#include "stack.hpp"
#include <vector>
#include <stack>
#include <map>

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
			std::stack<int> st;
			std::stack<int> st2;

			std::cout << st.empty() << std::endl;
			std::cout << st.size() << std::endl;
			st.push(10);
			std::cout << st.top() << std::endl;
			st.push(20);
			std::cout << st.top() << std::endl;
			st.pop();
			std::cout << st.top() << std::endl;
			std::cout << st.empty() << std::endl;
			std::cout << st.size() << std::endl;
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
			ft::stack<int>	st;
			ft::stack<int>	st2;

			std::cout << st.empty() << std::endl;
			std::cout << st.size() << std::endl;
			st.push(10);
			std::cout << st.top() << std::endl;
			st.push(20);
			std::cout << st.top() << std::endl;
			st.pop();
			std::cout << st.top() << std::endl;
			std::cout << st.empty() << std::endl;
			std::cout << st.size() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}