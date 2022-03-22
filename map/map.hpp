/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:40 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/22 01:26:53 by asfaihi          ###   ########.fr       */
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
			   class Alloc = std::allocator<ft::pair< Key, T> >
			   >
	class map
	{
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair< key_type, mapped_type>			value_type;
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

		class value_compare
		{
			friend class map;

		protected:
			Compare	comp;
			value_compare(Compare c) : comp(c) {}

		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool	operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			};
		};

	private:
		Tree_type	_tree;
		key_compare	_comp;

	public:
		/************************************************************************/
		/*																		*/
		/*			CONSTRUCTORS - DESTRUCTORS - ASSIGNMENT OPERATOR			*/
		/*																		*/
		/************************************************************************/
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc), _comp(comp) {};
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc), _comp(comp) { this->insert(first, last); };
		map(const map& x) { *this = x; };

		~map() { this->clear(); };

		map& operator=(const map& x) {
			if (this == &x)
				return (*this);
			this->clear();
			this->insert(x.begin(), x.end());
			return (*this);
		};


		/************************************************************************/
		/*																		*/
		/*								ITERATORS								*/
		/*																		*/
		/************************************************************************/
		iterator				begin()				{ return this->_tree.begin(); };
		const_iterator			begin() const		{ return this->_tree.begin(); };
		iterator				end()				{ return this->_tree.end(); };
		const_iterator			end() const			{ return this->_tree.end(); };
		reverse_iterator		rbegin()			{ return this->_tree.rbegin(); };
		const_reverse_iterator	rbegin() const		{ return this->_tree.rbegin(); };
		reverse_iterator		rend()				{ return this->_tree.rend(); };
		const_reverse_iterator	rend() const		{ return this->_tree.rend(); };


		/************************************************************************/
		/*																		*/
		/*								CAPACITY								*/
		/*																		*/
		/************************************************************************/
		bool					empty() const		{ return this->_tree.empty(); };
		size_type				size() const		{ return this->_tree.size(); };
		size_type				max_size() const	{ return this->_tree.max_size(); };


		/************************************************************************/
		/*																		*/
		/*							 ELEMENT ACCESS 							*/
		/*																		*/
		/************************************************************************/
		mapped_type				&operator[](const key_type& k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		};


		/************************************************************************/
		/*																		*/
		/*								MODIFIERS								*/
		/*																		*/
		/************************************************************************/
		pair<iterator, bool> 	insert(const value_type& val) {
			if (this->count(val.first))
				return ft::make_pair(this->find(val.first), false);
			this->_tree.insert(val);
			return ft::make_pair(this->find(val.first), true);
		}
		iterator				insert(iterator position, const value_type &val) {
			std::cout << "We sall shee\n";
			NodePtr temp = position.base();
			if ((!_getPredecessor(temp) || val.first > _getPredecessor(temp)->data.first) && val.first < _getSuccessor(temp)->data.first)
				std::cout << "yoink\n";
			else
				std::cout << "boink\n";
			return position;
		};
		template <class InputIterator>
		void					insert(InputIterator first, InputIterator last) {
			while (first != last)
				this->insert((*first++));
		};
		void					erase(iterator position) { this->erase((*position).first); };
		size_type				erase(const key_type &k) {
			size_type	temp_size = this->size();
			this->_tree.deleteNode(k);
			if (this->size() != temp_size)
				return 1;
			return 0;
		};
		void					erase(iterator first, iterator last) {
			iterator	position = first;
			while ((*first).first < (*last).first) {
				position = first;
				this->erase(position);
				first++;
			}
		};
		void					swap(map &x)		{ this->_tree.swap(x._tree); };
		void					clear()				{ this->_tree.clear(); };


		/************************************************************************/
		/*																		*/
		/*								OBSERVERS								*/
		/*																		*/
		/************************************************************************/
		key_compare				key_comp() const	{ return key_compare(); };
		value_compare			value_comp() const	{ return value_compare(this->_comp); };


		/************************************************************************/
		/*																		*/
		/*								OPERATIONS								*/
		/*																		*/
		/************************************************************************/
		iterator								find(const key_type& k)					{ return iterator(this->_tree.find(k)); };
		const_iterator							find(const key_type& k) const			{ return const_iterator(this->_tree.find(k)); };
		size_type								count(const key_type& k) const			{ return _tree.search(k); };
		iterator								lower_bound(const key_type& k)			{ return iterator(this->_tree.lower_bound(k)); };
		const_iterator							lower_bound(const key_type &k) const	{ return const_iterator(this->_tree.lower_bound(k)); };
		iterator								upper_bound(const key_type &k)			{ return iterator(this->_tree.upper_bound(k)); };
		const_iterator							upper_bound(const key_type &k) const	{ return const_iterator(this->_tree.upper_bound(k)); };
		pair<iterator, iterator>				equal_range(const key_type &k)			{ return ft::make_pair(this->lower_bound(k), this->upper_bound(k)); };
		pair<const_iterator, const_iterator>	equal_range(const key_type &k) const	{ return ft::make_pair(this->lower_bound(k), this->upper_bound(k)); };


		/************************************************************************/
		/*																		*/
		/*								ALLOCATOR								*/
		/*																		*/
		/************************************************************************/
		allocator_type							get_allocator() const					{ return this->_tree._alloc(); };

		void	printTree(void) { this->_tree.printTree(); }
	};

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	};

}

#endif