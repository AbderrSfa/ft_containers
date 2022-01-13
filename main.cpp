#include "iterator.hpp"
#include <vector>
#include <iostream>

int     main() {
/*    ft::integers<int>    numbers;

	std::fill(numbers.begin(), numbers.end(), 4);
	ft::iterator<int, std::forward_iterator_tag> begin = numbers.begin();
	ft::iterator<int, std::forward_iterator_tag> end = numbers.end();
	while (begin != end)
	{
		std::cout << *begin << "\n";
		begin++;
	}*/
	ft::integers<int>	numbers;
	ft::iterator_traits<ft::iterator<int, std::forward_iterator_tag> >	it;
	(void)it;
	(void)numbers;
}