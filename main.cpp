/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/17 12:38:23 by asfaihi          ###   ########.fr       */
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
			//std::cout << "========== OG ==========" << std::endl;
			//std::map<int, char> mp;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		try
		{
			//std::cout << "========= MINE =========" << std::endl;
			//ft::map<int, char> mp;
			AVLTree<int, char, std::allocator<Node<int, char> > >	tree;

			tree.insert(38, 'a');
			tree.insert(40, 'b');
			tree.insert(52, 'c');
			tree.insert(25, 'd');
			tree.insert(74, 'f');
			tree.insert(35, 'g');
			tree.insert(68, 'h');
			tree.insert(61, 'e');
			tree.insert(88, 'i');
			tree.insert(49, 'j');
			tree.insert(55, 'k');
			tree.insert(65, 'l');
			tree.insert(58, 'm');
			tree.insert(47, 'n');
			tree.insert(67, 'o');
			tree.insert(11, 'p');
			tree.insert(59, 'q');
			tree.deleteNode(88);
			tree.printTree();

		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}