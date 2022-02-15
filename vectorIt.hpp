/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIt.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:37:09 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/15 17:37:10 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_IT_HPP
# define VECTOR_IT_HPP

# include "iterator_traits.hpp"

namespace ft
{
	template <class T>
	class vectorIt : public iterator<std::random_access_iterator_tag, T> {
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
			vectorIt() : _m_ptr() {};
			explicit vectorIt(const iterator_type& _i) : _m_ptr(_i) {};
			template <class Iter>
			vectorIt(const vectorIt<Iter>& _i) : _m_ptr(_i.base()) {};

			const iterator_type&	base() const						{ return this->_m_ptr; };
			reference				operator*() const 					{ return *this->_m_ptr; };
			vectorIt				operator+(difference_type n) const	{ return vectorIt(this->_m_ptr + n); };
			vectorIt&				operator++() 						{ ++this->_m_ptr; return *this; };
			vectorIt				operator++(int) 					{ return vectorIt(this->_m_ptr++); };
			vectorIt&				operator+=(difference_type n) 		{ this->_m_ptr += n; return *this; };
			vectorIt				operator-(difference_type n) const	{ return vectorIt(this->_m_ptr - n); };
			vectorIt&				operator--() 						{ --this->_m_ptr; return *this; };
			vectorIt				operator--(int) 					{ return vectorIt(this->_m_ptr--); };
			vectorIt&				operator-=(difference_type n) 		{ this->_m_ptr -= n; return *this; };
			pointer					operator->() const 					{ return this->_m_ptr; };
			reference				operator[](difference_type n) const	{ return this->_m_ptr[n]; };
	};

	template <class Iterator>
	bool	operator==(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() == rhs.base()); };

	template <class Iterator>
	bool	operator!=(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() != rhs.base()); };

	template <class Iterator>
	bool	operator<(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() < rhs.base()); };

	template <class Iterator>
	bool	operator<=(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() <= rhs.base()); };

	template <class Iterator>
	bool	operator>(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() > rhs.base()); };

	template <class Iterator>
	bool	operator>=(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	vectorIt<Iterator>  operator+(typename vectorIt<Iterator>::difference_type n, const vectorIt<Iterator>& i)
		{ return vectorIt<Iterator>(i.base() + n); };

	template <class Iterator>
	typename vectorIt<Iterator>::difference_type    operator-(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
		{ return (lhs.base() - rhs.base()); };
}

#endif