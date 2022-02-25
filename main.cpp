/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/25 13:44:23 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
// #include "vector/vector.hpp"
#include <stack>
// #include "stack/stack.hpp"
#include <map>
#include "map/map.hpp"

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::map<int, char> mp;

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

			mp.printTree();


			// ft::vector<int>	vec2(10, 0);
			// ft::vector<int>	vec(5, 1);

			// for (int i = 0; i < vec.size(); i++)
			// 	std::cout << vec.at(i) << ' ';
			// std::cout << std::endl;
			
			// for (int i = 0; i < vec2.size(); i++)
			// 	std::cout << vec2.at(i) << ' ';
			// std::cout << std::endl;

			// std::cout << "vec: " << vec.size() << " " << vec.capacity() << std::endl;
			// std::cout << "vec2: " << vec2.size() << " " << vec2.capacity() << std::endl;

			
			// swap(vec, vec2);

			// for (int i = 0; i < vec.size(); i++)
			// 	std::cout << vec.at(i) << ' ';
			// std::cout << std::endl;

			// for (int i = 0; i < vec2.size(); i++)
			// 	std::cout << vec2.at(i) << ' ';
			// std::cout << std::endl;

			// std::cout << "vec: " << vec.size() << " " << vec.capacity() << std::endl;
			// std::cout << "vec2: " << vec2.size() << " " << vec2.capacity() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}