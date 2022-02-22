/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/22 16:31:15 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
// #include "vector/vector.hpp"
#include <stack>
//#include "stack/stack.hpp"
#include <map>
#include "map/map.hpp"

template<typename T>
void f(T a, T b)
{
	typedef std::less<T>	compare;
	if (compare(a, b))
	{
		std::cout << "Hello\n";
	}
}

int main()
{
	// f(0, 1);
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::map<int, char> mp;
			std::pair<int, char>(1, 'f');

			mp.insert(std::make_pair(40, 'b'));
			mp.insert(std::make_pair(38, 'a'));
			mp.insert(std::make_pair(52, 'c'));

			std::cout << mp[40] << std::endl;
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

			mp.insert(ft::make_pair(40, 'b'));
			mp.insert(ft::make_pair(52, 'c'));
			mp.insert(ft::make_pair(38, 'a'));
			mp.insert(ft::make_pair(25, 'd'));
			mp.insert(ft::make_pair(74, 'f'));
			mp.insert(ft::make_pair(35, 'g'));
			mp.insert(ft::make_pair(68, 'h'));
			mp.insert(ft::make_pair(61, 'e'));
			mp.insert(ft::make_pair(88, 'i'));
			mp.insert(ft::make_pair(49, 'j'));
			mp.insert(ft::make_pair(55, 'k'));
			mp.insert(ft::make_pair(65, 'l'));
			mp.insert(ft::make_pair(58, 'm'));
			mp.insert(ft::make_pair(47, 'n'));
			mp.insert(ft::make_pair(67, 'o'));
			mp.insert(ft::make_pair(11, 'p'));
			mp.insert(ft::make_pair(59, 'q'));
			mp.erase(68);
			mp.erase(67);
			mp.erase(52);
			mp.erase(11);
			std::cout << mp.count(59) << std::endl;
			std::cout << mp.count(100) << std::endl;
			mp.printTree();
		}
		// if (node == NULL)
		// 	return false;
		// else if (compare(key, node->data.first, key_compare()))
		// 	return search(node->left, key);
		// else if (compare(node->data.first, key, key_compare()))
		// 	return search(node->right, key);
		// else
		// 	return true;
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}


	
	return 0;
}