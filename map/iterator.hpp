/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:25:18 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/23 12:01:03 by asfaihi          ###   ########.fr       */
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

	template <class T>
	class mapIt : public std::iterator<std::bidirectional_iterator_tag, T> {
		public:
			typedef T												iterator_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

		private:
			iterator_type	_m_ptr;

		public:
			mapIt() : _m_ptr(){};
			explicit mapIt(const iterator_type &_i) : _m_ptr(_i){};
			template <class Iter>
			mapIt(const mapIt<Iter> &_i) : _m_ptr(_i.base()){};

			const iterator_type&	base() const						{ return this->_m_ptr; };
			reference				operator*() const 					{ return *this->_m_ptr; };
			mapIt&					operator++() 						{ ++this->_m_ptr; return *this; };
			mapIt					operator++(int) 					{ return mapIt(this->_m_ptr++); };
			mapIt&					operator--() 						{ --this->_m_ptr; return *this; };
			mapIt					operator--(int) 					{ return mapIt(this->_m_ptr--); };
			pointer					operator->() const 					{ return this->_m_ptr; };
	};

	template <class Iterator>
	bool	operator==(const mapIt<Iterator>& lhs, const mapIt<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); };

	template <class Iterator>
	bool	operator!=(const mapIt<Iterator>& lhs, const mapIt<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); };

	template <class T>
	class mapRevIt : public std::iterator<std::bidirectional_iterator_tag, T> {
		public:
			typedef T    											iterator_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

		private:
			iterator_type	_m_ptr;

		public:
			mapRevIt() : _m_ptr() {};
			explicit mapRevIt(iterator_type _it) : _m_ptr(_it) {};
			template <class Iter>
			mapRevIt(const mapRevIt<Iter>& _rev_it) : _m_ptr(_rev_it.base()) {};

			iterator_type	base() const 						{ return this->_m_ptr; };
			reference		operator*() const 					{ iterator_type tmp = _m_ptr; return *--tmp; };
			mapRevIt&		operator++() 						{ --this->_m_ptr; return *this; };
			mapRevIt		operator++(int) 					{ mapRevIt tmp = *this; --this->_m_ptr; return tmp; };
			mapRevIt&		operator--() 						{ ++this->_m_ptr; return *this; };
			mapRevIt		operator--(int) 					{ mapRevIt tmp = *this; ++this->_m_ptr; return tmp; };
			pointer			operator->() const 					{ return &(operator*()); };
	};

	template <class Iterator>
	bool operator==(const mapRevIt<Iterator>& lhs, const mapRevIt<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); };
	
	template <class Iterator>
	bool operator!=(const mapRevIt<Iterator>& lhs, const mapRevIt<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); };
}

#endif