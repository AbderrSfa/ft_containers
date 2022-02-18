/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/18 12:20:11 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"
#include <stack>
#include "stack.hpp"
#include <map>
#include "map.hpp"
#include "AVLTree.hpp"

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::map<int, char> mp;

			mp.insert(std::pair<int, char>(40, 'b'));
			mp.insert(std::pair<int, char>(38, 'a'));
			mp.insert(std::pair<int, char>(52, 'c'));

			std::cout << mp.count(0) << std::endl;
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

			mp.insert(std::pair<int, char>(40, 'b'));
			mp.insert(std::pair<int, char>(38, 'a'));
			mp.insert(std::pair<int, char>(52, 'c'));

			std::cout << mp.count(0) << std::endl;
			// mp.insert(std::pair<int, char>(25, 'd'));
			// mp.insert(std::pair<int, char>(74, 'f'));
			// mp.insert(std::pair<int, char>(35, 'g'));
			// mp.insert(std::pair<int, char>(68, 'h'));
			// mp.insert(std::pair<int, char>(61, 'e'));
			// mp.insert(std::pair<int, char>(88, 'i'));
			// mp.insert(std::pair<int, char>(49, 'j'));
			// mp.insert(std::pair<int, char>(55, 'k'));
			// mp.insert(std::pair<int, char>(65, 'l'));
			// mp.insert(std::pair<int, char>(58, 'm'));
			// mp.insert(std::pair<int, char>(47, 'n'));
			// mp.insert(std::pair<int, char>(67, 'o'));
			// mp.insert(std::pair<int, char>(11, 'p'));
			// mp.insert(std::pair<int, char>(59, 'q'));
			// mp.deleteNode(25);
			// mp.deleteNode(35);
			//mp.printTree();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}