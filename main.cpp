#include "iterator.hpp"
#include <vector>
#include <iostream>

int     main() {
	std::vector<int>::iterator	tis;
	std::vector<int>::iterator	tis2;
	tis++;
	ft::vectorIter<ft::iterator<std::forward_iterator_tag, int> >	g;
	(void)g;
}