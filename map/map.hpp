/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:40 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/15 14:05:31 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "iterator.hpp"
# include "utils.hpp"
# include "tree.hpp"

namespace ft
{
	template < class Key,
			   class T,
			   class Compare = std::less<Key>,
			   ////
			   class Alloc = std::allocator<ft::pair<const Key, T> >
			   ////
			   >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			////
			typedef ft::pair<const key_type, mapped_type>			value_type;
			////
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::difference_type		difference_type;
			typedef typename allocator_type::size_type				size_type;

		private:
			typedef Node<value_type>								Node_type;
			typedef Node_type*										NodePtr;
			typedef Tree<value_type, key_compare, allocator_type>	Tree_type;

		public:
			typedef typename Tree_type::iterator					iterator;
			typedef typename Tree_type::const_iterator				const_iterator;
			typedef typename Tree_type::reverse_iterator			reverse_iterator;
			typedef typename Tree_type::const_reverse_iterator		const_reverse_iterator;

		private:
			Tree_type	_tree;

		public:
			/* Constructors - Destructor - Assignment operator */
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _tree(comp, alloc) {};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _tree(comp, alloc) { this->insert(first, last); };
			map(const map& x) { *this = x; };
			void	printTree(void) { this->_tree.printTree(); }

			iterator				begin()							{ return this->_tree.begin(); };
			const_iterator			begin() const					{ return this->_tree.begin(); };
			iterator				end()							{ return this->_tree.end(); };
			const_iterator			end() const						{ return this->_tree.end(); };
			
			reverse_iterator		rbegin()						{ return this->_tree.rbegin(); };
			const_reverse_iterator	rbegin() const					{ return this->_tree.rbegin(); };
			reverse_iterator		rend()							{ return this->_tree.rend(); };
			const_reverse_iterator	rend() const					{ return this->_tree.rend(); };
			
			bool					empty() const					{ return this->_tree.empty(); };
			size_type				size() const					{ return this->_tree.size(); };
			size_type				max_size() const				{ return this->_tree.max_size(); };
			void					clear()							{ this->_tree.clear(); };
			key_compare				key_comp() const				{ return key_compare(); };
			size_type				count(const key_type& k) const	{ return _tree.search(k); };
			allocator_type			get_allocator() const			{ return allocator_type(); };
			iterator				find(const key_type& k)			{ return iterator(this->_tree.find(k)); };
			const_iterator			find(const key_type& k) const	{ return const_iterator(this->_tree.find(k)); };
			
			~map() { this->clear(); };
			// map& operator=(const map& x) {};

			/* Iterators */

			/* Capacity */

			/* Element access */
			mapped_type	&operator[](const key_type& k)
			{
				return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
			};

			/* Modifiers */
			pair<iterator, bool> insert(const value_type& val) {
				if (this->count(val.first))
					return ft::make_pair(this->find(val.first), false);
				this->_tree.insert(val);
				return ft::make_pair(this->find(val.first), true);
			}
			// iterator				insert(iterator position, const value_type &val) {};
			template <class InputIterator>
			void					insert(InputIterator first, InputIterator last) {
				while (first != last)
					this->insert((*first++));
			};
			// void					erase(iterator position) {};
			// size_type				erase(const key_type &k)
			// {
			// 	if (!this->count(k))
			// 		return 0;
			// 	this->_tree.deleteNode(k);
			// 	return 1;
			// };
			// void					erase(iterator first, iterator last) {};
			// void					swap(map &x) {};

			/* Observers */
			// value_compare	value_comp() const {};

			/* Operations */
			
			iterator		lower_bound(const key_type& k)			{ return iterator(this->_tree.lower_bound(k)); };
			const_iterator	lower_bound(const key_type &k) const	{ return const_iterator(this->_tree.lower_bound(k)); };
			iterator		upper_bound(const key_type &k)			{ return iterator(this->_tree.upper_bound(k)); };
			const_iterator	upper_bound(const key_type &k) const	{ return const_iterator(this->_tree.upper_bound(k)); };
			// pair<iterator, iterator>				equal_range(const key_type &k) {};
			// pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {};

			/* Allocator */
	};
}

#endif