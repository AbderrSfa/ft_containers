/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/17 16:58:03 by asfaihi          ###   ########.fr       */
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
			// std::cout << "========== OG ==========" << std::endl;
			// std::map<int, char> mp;
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

			// AVLTree<std::pair<int, char>, std::less<int>,
			// 	std::allocator<Node<std::pair<int, char> > > >	tree;
			// tree.insert(std::pair<int, char>(40, 'b'));
			// tree.insert(std::pair<int, char>(38, 'a'));
			// tree.insert(std::pair<int, char>(52, 'c'));
			// tree.insert(std::pair<int, char>(25, 'd'));
			// tree.insert(std::pair<int, char>(74, 'f'));
			// tree.insert(std::pair<int, char>(35, 'g'));
			// tree.insert(std::pair<int, char>(68, 'h'));
			// tree.insert(std::pair<int, char>(61, 'e'));
			// tree.insert(std::pair<int, char>(88, 'i'));
			// tree.insert(std::pair<int, char>(49, 'j'));
			// tree.insert(std::pair<int, char>(55, 'k'));
			// tree.insert(std::pair<int, char>(65, 'l'));
			// tree.insert(std::pair<int, char>(58, 'm'));
			// tree.insert(std::pair<int, char>(47, 'n'));
			// tree.insert(std::pair<int, char>(67, 'o'));
			// tree.insert(std::pair<int, char>(11, 'p'));
			// tree.insert(std::pair<int, char>(59, 'q'));
			// tree.deleteNode(25);
			// tree.deleteNode(35);
			// tree.printTree();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}