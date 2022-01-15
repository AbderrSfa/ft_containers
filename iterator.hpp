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
	class VectorIt : public iterator<std::random_access_iterator_tag, T> {
		public:
			typedef T    											iterator_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::value_type			value_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
			typedef typename iterator_traits<T>::iterator_category	iterator_category;

			VectorIt() : _m_ptr() {};
			explicit VectorIt(const iterator_type& _i) : _m_ptr(_i) {};
			template <typename Iter>
			VectorIt(const VectorIt<Iter>& _i) : _m_ptr(_i.base()) {};

			const iterator_type&	base() const						{ return this->_m_ptr; };
			reference				operator*() const 					{ return *this->_m_ptr; };
			pointer					operator->() const 					{ return this->_m_ptr; };
			VectorIt&				operator++() 						{ ++this->_m_ptr; return *this; };
			VectorIt				operator++(int) 					{ return VectorIt(this->_m_ptr++); };
			VectorIt&				operator--() 						{ --this->_m_ptr; return *this; };
			VectorIt				operator--(int) 					{ return VectorIt(this->_m_ptr--); };
			VectorIt				operator+(difference_type n) const	{ return VectorIt(this->_m_ptr + n); };
			VectorIt				operator-(difference_type n) const	{ return VectorIt(this->_m_ptr - n); };
			VectorIt&				operator+=(difference_type n) 		{ this->_m_ptr += n; return *this; };
			VectorIt&				operator-=(difference_type n) 		{ this->_m_ptr -= n; return *this; };
			reference				operator[](difference_type n) const	{ return this->_m_ptr[n]; };

		private:
			iterator_type	_m_ptr;
	};

    template <class Iterator>
    bool    operator==(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() == rhs.base()); };
    template <class Iterator>
    bool    operator!=(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() != rhs.base()); };
    template <class Iterator>
    bool    operator<(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() < rhs.base()); };
    template <class Iterator>
    bool    operator>(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() > rhs.base()); };
    template <class Iterator>
    bool    operator<=(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() <= rhs.base()); };
    template <class Iterator>
    bool    operator>=(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() >= rhs.base()); };
    template <class Iterator>
    VectorIt<Iterator>  operator+(typename VectorIt<Iterator>::difference_type n, const VectorIt<Iterator>& i) { return VectorIt<Iterator>(i.base() + n); };
    template <class Iterator>
    typename VectorIt<Iterator>::difference_type    operator-(const VectorIt<Iterator>& lhs, const VectorIt<Iterator>& rhs) { return (lhs.base() - rhs.base()); };
}

#endif