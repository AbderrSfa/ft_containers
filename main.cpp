#include "iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int     main() {
    ft::vector<int> f;
	ft::VectorIt<ft::iterator<std::forward_iterator_tag, int> >	g;
    ft::vector<float>::iterator it;
    ft::vector<float>::iterator ite;
	(void)g;
}