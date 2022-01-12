#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>

namespace ft
{
	template < typename T >
	class Iterator
	{
		typedef	std::forward_iterator_tag	iterator_category;
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef	T*	    					pointer;
		typedef	T&  						reference;

		public:
			Iterator(pointer ptr) : m_ptr(ptr) {}

			reference	operator*() const { return *m_ptr; }
			pointer		operator->() { return m_ptr; }

			Iterator&	operator++() { m_ptr++; return (*this); }
			Iterator	operator++(int) { Iterator	tmp = *this; ++(*this); return tmp; }

			friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
			friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };
			
		private:
			pointer	m_ptr;
	};


	template < typename T >
	class   Integers {
		private:
			T m_data[200];

		public:


			Iterator<T>    begin() { return Iterator<T>(&m_data[0]); }
			Iterator<T>    end() { return Iterator<T>(&m_data[200]); }
	};
}

#endif