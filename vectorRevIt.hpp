#ifndef VECTOR_REV_IT_HPP
# define VECTOR_REV_IT_HPP

# include "vectorIt.hpp"

namespace ft
{
	template <class T>
	class vectorRevIt : public iterator<std::random_access_iterator_tag, T> {
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
			vectorRevIt() : _m_ptr() {};
			explicit vectorRevIt(iterator_type _it) : _m_ptr(_it) {};
			template <class Iter>
			vectorRevIt(const vectorRevIt<Iter>& _rev_it) : _m_ptr(_rev_it.base()) {};

			iterator_type	base() const 						{ return this->_m_ptr; };
			reference		operator*() const 					{ iterator_type tmp = _m_ptr; return *--tmp; };
			vectorRevIt		operator+(difference_type n) const 	{ return vectorRevIt(this->_m_ptr - n); };
			vectorRevIt&	operator++() 						{ --this->_m_ptr; return *this; };
			vectorRevIt		operator++(int) 					{ vectorRevIt tmp = *this; --this->_m_ptr; return tmp; };
			vectorRevIt&	operator+=(difference_type n) 		{ this->_m_ptr -= n; return *this; };
			vectorRevIt		operator-(difference_type n) const 	{ return vectorRevIt(this->_m_ptr + n); };
			vectorRevIt&	operator--() 						{ ++this->_m_ptr; return *this; };
			vectorRevIt		operator--(int) 					{ vectorRevIt tmp = *this; ++this->_m_ptr; return tmp; };
			vectorRevIt&	operator-=(difference_type n) 		{ this->_m_ptr += n; return *this; };
			pointer			operator->() const 					{ return &(operator*()); };
			reference		operator[](difference_type n) const	{ return *(*this + n); };
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