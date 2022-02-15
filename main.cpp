/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/15 17:36:38 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			ft::redBlackTree<int, char>	rb;

			rb.add(4, 'e');
			rb.add(5, 'f');
			rb.printTree();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}