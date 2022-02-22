/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/22 14:38:04 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
// #include "vector/vector.hpp"
#include <stack>
//#include "stack/stack.hpp"
#include <map>
#include "map/map.hpp"

int main()
{
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

			mp.insert(std::make_pair(52, 'c'));
			mp.insert(std::make_pair(40, 'b'));
			mp.insert(std::make_pair(38, 'a'));
			mp.insert(std::make_pair(25, 'd'));
			mp.insert(std::make_pair(74, 'f'));
			mp.insert(std::make_pair(35, 'g'));
			mp.insert(std::make_pair(68, 'h'));
			mp.insert(std::make_pair(61, 'e'));
			mp.insert(std::make_pair(88, 'i'));
			mp.insert(std::make_pair(49, 'j'));
			mp.insert(std::make_pair(55, 'k'));
			mp.insert(std::make_pair(65, 'l'));
			mp.insert(std::make_pair(58, 'm'));
			mp.insert(std::make_pair(47, 'n'));
			mp.insert(std::make_pair(67, 'o'));
			mp.insert(std::make_pair(11, 'p'));
			mp.insert(std::make_pair(59, 'q'));
			// mp.erase(25);
			// mp.erase(35);
			mp.printTree();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}