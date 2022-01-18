#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <class T>
	class VectorRevIt : public iterator<std::random_access_iterator_tag, T> {
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
			VectorRevIt() : _m_ptr() {};
			explicit VectorRevIt(iterator_type _it) : _m_ptr(_it) {};
			template <class Iter>
			VectorRevIt(const VectorRevIt<Iter>& _rev_it) : _m_ptr(_rev_it.base()) {};

			iterator_type	base() const { return this->_m_ptr; };
			reference		operator*() const { iterator_type tmp = _m_ptr; return *--tmp; };
	};
}

#endif