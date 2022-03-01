/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:40 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/01 15:31:48 by asfaihi          ###   ########.fr       */
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
			   class Alloc = std::allocator<ft::pair<const Key, T> >
			   >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			// key_type should be const
			typedef ft::pair<key_type, mapped_type>		value_type;
			//
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;
			typedef mapIt<pointer>								iterator;
			typedef mapIt<const_pointer>						const_iterator;
			typedef mapRevIt<iterator>							reverse_iterator;
			typedef mapRevIt<const_iterator>					const_reverse_iterator;

		private:
			Tree<value_type, key_compare, allocator_type>	_tree;

		public:
			/* Constructors - Destructor - Assignment operator */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {};

			void	printTree(void) { this->_tree.printTree(); }
			
			// template <class InputIterator>
			// map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {};
			// map(const map& x) {};
			// ~map() {};
			// map& operator=(const map& x) {};

			/* Iterators */
			iterator				begin()			{ return this->_tree.begin(); };
			// const_iterator			begin() const	{ return const_iterator(this->_tree->root->data); };
			// iterator				end()			{  };
			// const_iterator			end() const		{  };
			// reverse_iterator		rbegin()		{ return reverse_iterator(this->end()); };
			// const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(this->end()); };
			// reverse_iterator		rend()			{ return reverse_iterator(this->begin()); };
			// const_reverse_iterator	rend() const	{ return const_reverse_iterator(this->begin()); };

			/* Capacity */
			bool		empty() const		{ return this->_tree.empty(); };
			size_type	size() const		{ return this->_tree.size(); };
			size_type	max_size() const	{ return this->_tree.max_size(); };

			/* Element access */
			mapped_type	&operator[](const key_type &k)
			{
				// return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
				// if (this->count(k))
					mapped_type	&temp = this->find(k).second;
					return temp;
			};

			/* Modifiers */
			void	insert(const value_type &val) { this->_tree.insert(val); };
			// iterator				insert(iterator position, const value_type &val) {};
			// template <class InputIterator>
			// void					insert(InputIterator first, InputIterator last) {};
			// void					erase(iterator position) {};
			size_type				erase(const key_type &k)
			{
				if (!this->count(k))
					return 0;
				this->_tree.deleteNode(k);
				return 1;
			};
			// void					erase(iterator first, iterator last) {};
			// void					swap(map &x) {};
			void					clear() { this->_tree.clear(); };

			/* Observers */
			key_compare		key_comp() const { return key_compare(); };
			// value_compare	value_comp() const {};

			/* Operations */
			value_type								find(const key_type &k)
			{
				if (!this->count(k))
					return value_type(0, '\0');
				return this->_tree.find(k);
			};
			const_iterator							find(const key_type &k) const {};
			size_type								count(const key_type &k) const { return _tree.search(k); };
			value_type								lower_bound(const key_type &k)
			{
				if (this->count(k))
					return this->_tree.find(k);
				return value_type(0, '\0');
			};
			// const_iterator							lower_bound(const key_type &k) const {};
			value_type								upper_bound(const key_type &k) {};
			// const_iterator							upper_bound(const key_type &k) const {};
			// pair<iterator, iterator>				equal_range(const key_type &k) {};
			// pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {};

			/* Allocator */
			allocator_type	get_allocator() const { return allocator_type(); };
	};
}

#endif