/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapRevIt.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:36:49 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/15 17:36:50 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REV_IT_HPP
# define MAP_REV_IT_HPP

namespace ft
{
	template <class T>
	class mapRevIt : public iterator<std::bidirectional_iterator_tag, T> {
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