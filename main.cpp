#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::cout << "========== OG ==========" << std::endl;
	std::vector<int> std_vec;

	std_vec.reserve(3);
	std_vec.push_back(1);
	std::cout << "size: " << std_vec.size() << " capacity: " << std_vec.capacity() << std::endl;
	std_vec.push_back(2);
	std::cout << "size: " << std_vec.size() << " capacity: " << std_vec.capacity() << std::endl;
	std_vec.push_back(2);
	std_vec.push_back(2);
	std::cout << "size: " << std_vec.size() << " capacity: " << std_vec.capacity() << std::endl;
	std_vec.push_back(2);
	std::cout << "size: " << std_vec.size() << " capacity: " << std_vec.capacity() << std::endl;
	for (size_t i = 0; i < 7; i++)
		std::cout << std_vec[i] << std::endl;

	std::cout << "========== MINE ==========" << std::endl;
	ft::vector<int> ft_vec;

	ft_vec.reserve(3);
	ft_vec.push_back(1);
	std::cout << "size: " << ft_vec.size() << " capacity: " << ft_vec.capacity() << std::endl;
	ft_vec.push_back(2);
	std::cout << "size: " << ft_vec.size() << " capacity: " << ft_vec.capacity() << std::endl;
	ft_vec.push_back(2);
	ft_vec.push_back(2);
	std::cout << "size: " << ft_vec.size() << " capacity: " << ft_vec.capacity() << std::endl;
	ft_vec.push_back(2);
	std::cout << "size: " << ft_vec.size() << " capacity: " << ft_vec.capacity() << std::endl;
	for (size_t i = 0; i < 7; i++)
		std::cout << ft_vec[i] << std::endl;
}