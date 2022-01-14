#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& >
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	class vectorIter : public iterator<std::random_access_iterator_tag, T> {
		public:
			typedef T    											iterator_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

			reference	operator*() const 					{ return *this->_m_ptr; }
			pointer		operator->() const 					{ return this->_m_ptr; }
			vectorIter&	operator++() 						{ ++this->_m_ptr; return *this; }
			vectorIter	operator++(int) 					{ return vectorIter(this->_m_ptr++); }
			vectorIter&	operator--() 						{ --this->_m_ptr; return *this; }
			vectorIter	operator--(int) 					{ return vectorIter(this->_m_ptr--); }
			vectorIter	operator+(difference_type n) const	{ return vectorIter(this->_m_ptr + n); }
			vectorIter	operator-(difference_type n) const	{ return vectorIter(this->_m_ptr - n); }
			vectorIter&	operator+=(difference_type n) 		{ this->_m_ptr += n; return *this; }
			vectorIter&	operator-=(difference_type n) 		{ this->_m_ptr -= n; return *this; }
			reference	operator[](difference_type n) const	{ return this->_m_ptr[n]; }

		private:
			iterator_type	_m_ptr;

	};
}

#endif