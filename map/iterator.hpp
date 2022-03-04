/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:25:18 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/04 13:40:25 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>

namespace ft
{
#ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};
#endif

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::bidirectional_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::bidirectional_iterator_tag iterator_category;
	};

	template <class T, class NodePtr>
	class TreeIt : public std::iterator<std::bidirectional_iterator_tag, T> {
	public:
		typedef T												iterator_type;
		typedef typename iterator_traits<T>::iterator_category	iterator_category;
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
		// TreeIt&			operator++()		{ ++this->_it; return *this; };
		// TreeIt			operator++(int)		{ return TreeIt(this->_it++); };
		// TreeIt&			operator--()		{ --this->_it; return *this; };
		// TreeIt			operator--(int)		{ return TreeIt(this->_it--); };
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