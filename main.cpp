#include <vector>
#include "vector.hpp"
#include <stack>
#include "stack.hpp"
#include <map>
#include "map.hpp"
#include "redBlackTree.hpp"

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::map<int, char> mp;

			mp.insert({10, 'f'});
			mp.insert({5, 'a'});
			mp.insert({55, 'a'});
			mp.insert({7, 'd'});

			for (auto& p: mp)
				std::cout << "{" << p.first << ", " << p.second << "} ";
			std::cout << "{" << (*mp.begin()).first << ", " << (*mp.begin()).second << "} " << std::endl;
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
			ft::map<int, char> mp;

			mp.insert({10, 'f'});
			mp.insert({5, 'a'});
			mp.insert({55, 'a'});
			mp.insert({7, 'd'});
			mp.printTree();
			ft::redBlackTree<int, char>	rb;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}