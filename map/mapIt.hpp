/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIt.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:46 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/20 01:04:08 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_IT_HPP
# define MAP_IT_HPP

# include "iterator_traits.hpp"

namespace ft
{
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
}

#endif