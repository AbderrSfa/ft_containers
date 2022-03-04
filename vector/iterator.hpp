/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:12:04 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/04 13:52:32 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_ITERATOR_HPP
# define VEC_ITERATOR_HPP

# include "../iterator_traits.hpp"

namespace ft
{
	template <class T>
	class vectorIt : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		typedef T												iterator_type;
		typedef typename std::random_access_iterator_tag		iterator_category;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef typename iterator_traits<T>::reference			reference;

	private:
		iterator_type	_it;

	public:
		vectorIt() : _it() {};
		explicit vectorIt(const iterator_type& _i) : _it(_i) {};
		template <class Iter>
		vectorIt(const vectorIt<Iter>& _i) : _it(_i.base()) {};

		const iterator_type&	base() const { return this->_it; };
		reference				operator*() const { return *this->_it; };
		vectorIt				operator+(difference_type n) const { return vectorIt(this->_it + n); };
		vectorIt&				operator++() { ++this->_it; return *this; };
		vectorIt				operator++(int) { return vectorIt(this->_it++); };
		vectorIt&				operator+=(difference_type n) { this->_it += n; return *this; };
		vectorIt				operator-(difference_type n) const { return vectorIt(this->_it - n); };
		vectorIt&				operator--() { --this->_it; return *this; };
		vectorIt				operator--(int) { return vectorIt(this->_it--); };
		vectorIt&				operator-=(difference_type n) { this->_it -= n; return *this; };
		pointer					operator->() const { return this->_it; };
		reference				operator[](difference_type n) const { return this->_it[n]; };
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
	vectorIt<Iterator>	operator+(typename vectorIt<Iterator>::difference_type n, const vectorIt<Iterator>& i)
	{ return vectorIt<Iterator>(i.base() + n); };

	template <class Iterator>
	typename vectorIt<Iterator>::difference_type	operator-(const vectorIt<Iterator>& lhs, const vectorIt<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };

	template <class T>
	class vectorRevIt : public std::iterator<std::random_access_iterator_tag, T> {
	public:
		typedef T    											iterator_type;
		typedef typename std::random_access_iterator_tag		iterator_category;
		typedef typename iterator_traits<T>::difference_type	difference_type;
		typedef typename iterator_traits<T>::value_type			value_type;
		typedef typename iterator_traits<T>::pointer			pointer;
		typedef typename iterator_traits<T>::reference			reference;

	private:
		iterator_type	_it;

	public:
		vectorRevIt() : _it() {};
		explicit vectorRevIt(iterator_type _it) : _it(_it) {};
		template <class Iter>
		vectorRevIt(const vectorRevIt<Iter>& _rev_it) : _it(_rev_it.base()) {};

		iterator_type	base() const { return this->_it; };
		reference		operator*() const { iterator_type tmp = _it; return *--tmp; };
		vectorRevIt		operator+(difference_type n) const { return vectorRevIt(this->_it - n); };
		vectorRevIt&	operator++() { --this->_it; return *this; };
		vectorRevIt		operator++(int) { vectorRevIt tmp = *this; --this->_it; return tmp; };
		vectorRevIt&	operator+=(difference_type n) { this->_it -= n; return *this; };
		vectorRevIt		operator-(difference_type n) const { return vectorRevIt(this->_it + n); };
		vectorRevIt&	operator--() { ++this->_it; return *this; };
		vectorRevIt		operator--(int) { vectorRevIt tmp = *this; ++this->_it; return tmp; };
		vectorRevIt&	operator-=(difference_type n) { this->_it += n; return *this; };
		pointer			operator->() const { return &(operator*()); };
		reference		operator[](difference_type n) const { return *(*this + n); };
	};

	template <class Iterator>
	bool operator==(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() == rhs.base()); };

	template <class Iterator>
	bool operator!=(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() != rhs.base()); };

	template <class Iterator>
	bool operator<(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() > rhs.base()); };

	template <class Iterator>
	bool operator<=(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() >= rhs.base()); };

	template <class Iterator>
	bool operator>(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() < rhs.base()); };

	template <class Iterator>
	bool operator>=(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() <= rhs.base()); };

	template <class Iterator>
	vectorRevIt<Iterator>	operator+(typename vectorRevIt<Iterator>::difference_type n, const vectorRevIt<Iterator>& rev_it)
	{ return vectorRevIt<Iterator>(rev_it.base() - n); };

	template <class Iterator>
	typename vectorRevIt<Iterator>::difference_type	operator-(const vectorRevIt<Iterator>& lhs, const vectorRevIt<Iterator>& rhs)
	{ return (lhs.base() - rhs.base()); };
}

#endif