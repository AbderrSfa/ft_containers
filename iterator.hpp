#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <	class Category,
				class T,
				class Distance = std::ptrdiff_t,
				class Pointer = T*,
				class Reference = T& >
	class iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;

		public:
			iterator(pointer ptr) : m_ptr(ptr) {}

			reference	operator*() const { return *m_ptr; }
			pointer		operator->() { return m_ptr; }

			iterator&	operator++() { m_ptr++; return (*this); }
			iterator	operator++(int) { iterator	tmp = *this; ++(*this); return tmp; }

			friend bool operator== (const iterator& a, const iterator& b) { return a.m_ptr == b.m_ptr; };
			friend bool operator!= (const iterator& a, const iterator& b) { return a.m_ptr != b.m_ptr; };
			
		private:
			pointer	m_ptr;
	};

	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template < class T >
	class   integers {
		private:
			T m_data[200];

		public:
			iterator<T, std::forward_iterator_tag>	begin() { return iterator<T, std::forward_iterator_tag>(&m_data[0]); }
			iterator<T, std::forward_iterator_tag>	end() { return iterator<T, std::forward_iterator_tag>(&m_data[200]); }
	};
}

#endif