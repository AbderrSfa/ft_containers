#include <vector>
#include <stack>
#include <map>
#include <iostream>

int		main() {
	std::vector<int>	v;
	for (size_t i = 1; i < 8; i++)
	{
		v.push_back(i);
	}
	
	std::cout << "v.begin() => " << *v.begin() << std::endl;
	std::cout << "v.end() => " << *v.end() << std::endl;
	return (0);
}