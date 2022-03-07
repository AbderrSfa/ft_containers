/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:25:18 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/07 14:12:25 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../iterator_traits.hpp"

namespace ft
{
	template <class T, class NodePtr>
	class TreeIt : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef T												iterator_type;
		typedef typename std::bidirectional_iterator_tag		iterator_category;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::reference			reference;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef NodePtr											node_pointer;

	private:
		node_pointer	_it;

	public:
		TreeIt() : _it() {};
		explicit TreeIt(node_pointer _p) : _it(_p) {};
		template <class Iter>
		TreeIt(const TreeIt<Iter, node_pointer>& _i) : _it(_i.base()) {};

		node_pointer	base() const		{ return this->_it; };
		reference		operator*() const	{ return this->_it->data; };
		TreeIt&			operator++()		{ this->_it = _getSuccessor(this->_it); return (*this); };
		TreeIt			operator++(int)		{ TreeIt temp(*this); ++(*this); return (temp); };
		TreeIt&			operator--()		{ this->_it = _getPredecessor(this->_it); return (*this); };
		TreeIt			operator--(int)		{ TreeIt temp(*this); --(*this); return (temp); };
		pointer			operator->() const	{ return (&(operator*())); };
	};

	// template <class Iterator>
	// bool	operator==(const TreeIt<Iterator>& lhs, const TreeIt<Iterator>& rhs)
	// {
	// 	return (lhs.base() == rhs.base());
	// };

	// template <class Iterator>
	// bool	operator!=(const TreeIt<Iterator>& lhs, const TreeIt<Iterator>& rhs)
	// {
	// 	return (lhs.base() != rhs.base());
	// };
}

#endif