/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:37 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/15 15:30:25 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector/vector.hpp"
#include <stack>
#include "stack/stack.hpp"
#include <map>
#include "map/map.hpp"

		/*************************************/
		/*                                   */
		/*             MAP TESTS             */
		/*                                   */
		/*************************************/

#define ARG 87

int main()
{
	{
		try
		{
			std::cout << "========== OG ==========" << std::endl;
			std::map<int, char> mp;

			// mp.insert(std::make_pair(38, 'a'));
			// mp.insert(std::make_pair(52, 'c'));
			// mp.insert(std::make_pair(40, 'b'));
			// mp.insert(std::make_pair(25, 'd'));
			// mp.insert(std::make_pair(74, 'f'));
			// mp.insert(std::make_pair(35, 'g'));
			// mp.insert(std::make_pair(68, 'h'));
			// mp.insert(std::make_pair(61, 'e'));
			// mp.insert(std::make_pair(88, 'i'));
			// mp.insert(std::make_pair(49, 'j'));
			// mp.insert(std::make_pair(55, 'k'));
			// mp.insert(std::make_pair(65, 'l'));
			// mp.insert(std::make_pair(58, 'm'));
			// mp.insert(std::make_pair(47, 'n'));
			// mp.insert(std::make_pair(67, 'o'));
			// mp.insert(std::make_pair(11, 'p'));
			// mp.insert(std::make_pair(59, 'q'));

			std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator>	er = mp.equal_range(ARG);

			std::cout << er.first->first << " " << er.first->second << " --- " << er.second->first << " " << er.second->second << std::endl;
			// for (std::map<int, char >::iterator it = mp.begin(); it != mp.end(); ++it)
			// {
			// 	std::cout << it->first << " " << it->second << "\n";
			// }

			// std::map<int, char>::iterator			it = mp.begin();
			// std::map<int, char>::iterator			ite = mp.end();
			// std::map<int, char>::reverse_iterator	rit = mp.rbegin();
			// std::map<int, char>::reverse_iterator	rite = mp.rend();

			// std::cout << "begin:\t" << it->first << " " << it->second << std::endl;
			// std::cout << "end:\t" << ite->first << " " << ite->second << std::endl;
			// std::cout << "rbegin:\t" << rit->first << " " << rit->second << std::endl;
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

			// mp.insert(ft::make_pair(38, 'a'));
			// mp.insert(ft::make_pair(52, 'c'));
			// mp.insert(ft::make_pair(40, 'b'));
			// mp.insert(ft::make_pair(25, 'd'));
			// mp.insert(ft::make_pair(74, 'f'));
			// mp.insert(ft::make_pair(35, 'g'));
			// mp.insert(ft::make_pair(68, 'h'));
			// mp.insert(ft::make_pair(61, 'e'));
			// mp.insert(ft::make_pair(88, 'i'));
			// mp.insert(ft::make_pair(49, 'j'));
			// mp.insert(ft::make_pair(55, 'k'));
			// mp.insert(ft::make_pair(65, 'l'));
			// mp.insert(ft::make_pair(58, 'm'));
			// mp.insert(ft::make_pair(47, 'n'));
			// mp.insert(ft::make_pair(67, 'o'));
			// mp.insert(ft::make_pair(11, 'p'));
			// mp.insert(ft::make_pair(59, 'q'));

			ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator>	er = mp.equal_range(ARG);

			std::cout << er.first->first << " " << er.first->second << " --- " << er.second->first << " " << er.second->second << std::endl;
			// for (ft::map<int, char >::iterator it = mp.begin(); it != mp.end(); ++it)
			// {
			// 	std::cout << it->first << " " << it->second << "\n";
			// }

			// ft::map<int, char>::iterator			it = mp.begin();
			// ft::map<int, char>::iterator			ite = mp.end();
			// ft::map<int, char>::reverse_iterator	rit = mp.rbegin();
			// ft::map<int, char>::reverse_iterator	rite = mp.rend();

			// std::cout << "begin:\t" << it->first << " " << it->second << std::endl;
			// std::cout << "end:\t" << ite->first << " " << ite->second << std::endl;
			// std::cout << "rbegin:\t" << rit->first << " " << rit->second << std::endl;

			// mp.printTree();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}

		/****************************************/
		/*                                      */
		/*             VECTOR TESTS             */
		/*                                      */
		/****************************************/

// int main()
// {
// 	{
// 		try
// 		{
// 			std::cout << "========== OG ==========" << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// 	{
// 		try
// 		{
// 			std::cout << "========= MINE =========" << std::endl;
// 			ft::vector<int>	vec2(10, 0);
// 			ft::vector<int>	vec(5, 1);

// 			for (int i = 0; i < vec.size(); i++)
// 				std::cout << vec.at(i) << ' ';
// 			std::cout << std::endl;

// 			for (int i = 0; i < vec2.size(); i++)
// 				std::cout << vec2.at(i) << ' ';
// 			std::cout << std::endl;

// 			std::cout << "vec: " << vec.size() << " " << vec.capacity() << std::endl;
// 			std::cout << "vec2: " << vec2.size() << " " << vec2.capacity() << std::endl;


// 			swap(vec, vec2);

// 			for (int i = 0; i < vec.size(); i++)
// 				std::cout << vec.at(i) << ' ';
// 			std::cout << std::endl;

// 			for (int i = 0; i < vec2.size(); i++)
// 				std::cout << vec2.at(i) << ' ';
// 			std::cout << std::endl;

// 			std::cout << "vec: " << vec.size() << " " << vec.capacity() << std::endl;
// 			std::cout << "vec2: " << vec2.size() << " " << vec2.capacity() << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// 	return 0;
// }

		/****************************************/
		/*                                      */
		/*             STACK TESTS              */
		/*                                      */
		/****************************************/

// int main()
// {
// 	{
// 		try
// 		{
// 			std::cout << "========== OG ==========" << std::endl;
// 			std::stack<int> st;
// 			std::stack<int> st2;

// 			std::cout << st.empty() << std::endl;
// 			std::cout << st.size() << std::endl;
// 			st.push(10);
// 			std::cout << st.top() << std::endl;
// 			st.push(20);
// 			std::cout << st.top() << std::endl;
// 			st.pop();
// 			std::cout << st.top() << std::endl;
// 			std::cout << st.empty() << std::endl;
// 			std::cout << st.size() << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// 	{
// 		try
// 		{
// 			std::cout << "========== MINE ==========" << std::endl;
// 			ft::stack<int>	st;
// 			ft::stack<int>	st2;

// 			std::cout << st.empty() << std::endl;
// 			std::cout << st.size() << std::endl;
// 			st.push(10);
// 			std::cout << st.top() << std::endl;
// 			st.push(20);
// 			std::cout << st.top() << std::endl;
// 			st.pop();
// 			std::cout << st.top() << std::endl;
// 			std::cout << st.empty() << std::endl;
// 			std::cout << st.size() << std::endl;
// 		}
// 		catch (const std::exception &e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 	}
// }