/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 05:15:06 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/24 14:13:03 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include "iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template < typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;
			typedef vectorIt<pointer>							iterator;
			typedef vectorIt<const_pointer>						const_iterator;
			typedef vectorRevIt<iterator>						reverse_iterator;
			typedef vectorRevIt<const_iterator>					const_reverse_iterator;

		private:
			value_type*	_m_data;
			size_type	_size;
			size_type	_capacity;

		protected:
			void	_range_check(size_type n) const
			{
				if (n >= this->size())
				{
					std::string exception = "vector::_M_range_check: n (which is ";
					exception.append(std::to_string(n));
					exception.append(") >= this->size() (which is ");
					exception.append(std::to_string(this->size()));
					exception.append(")");
					throw std::out_of_range(exception);
				}
			};
			value_type*	_reallocate(size_type n)
			{
				value_type *tmp = allocator_type().allocate(n);
				for (size_t i = 0; i < this->size(); i++)
					allocator_type().construct(tmp + i, this->_m_data[i]);
				for (size_t i = 0; i < this->size(); i++)
					allocator_type().destroy(this->_m_data + i);
				if (this->_m_data)
					allocator_type().deallocate(this->_m_data, this->capacity());
				return tmp;
			};
			void	_erase_end_elements(size_type n)
			{
				for (size_t i = n; i < this->size(); i++)
					allocator_type().destroy(this->_m_data + i);
			};
			void	_append_elements(size_type n, value_type val)
			{
				for (size_t i = this->size(); i < n; i++)
					allocator_type().construct(this->_m_data + i, val);
			};
			void	_fill_vector_elements(size_type n, value_type val)
			{
				for (size_t i = 0; i < n; i++)
					allocator_type().construct(this->_m_data + i, val);
			};
			template <class InputIterator>
			void	_fill_vector_elements(InputIterator first, InputIterator last)
			{
				int i = 0;
				for (InputIterator it = first; it != last; it++)
					allocator_type().construct(this->_m_data + i++, *it);
			};

		public:
			/* Constructors - Destructor - Assignment operator */
			explicit vector(const allocator_type& alloc = allocator_type()) : _m_data(), _size(0), _capacity(0) {};
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _m_data(), _size(n), _capacity(n)
			{
				if (n > this->max_size())
					throw std::length_error("cannot create ft::vector larger than max_size()");
				if (n)
				{
					this->_m_data = allocator_type().allocate(n);
					_fill_vector_elements(n, val);
				}
			};
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
				: _m_data(), _size(0), _capacity(0)
			{
				int n = std::distance(first, last);
				this->_m_data = allocator_type().allocate(n);
				_fill_vector_elements(first, last);
				this->_size = n;
				this->_capacity = n;
			};
			vector(const vector& x) : _m_data(), _size(0), _capacity(0) { *this = x; };

			~vector()
			{
				for (size_t i = 0; i < this->size(); i++)
					allocator_type().destroy(this->_m_data + i);
				if (this->capacity())
					allocator_type().deallocate(this->_m_data, this->capacity());
			};

			vector& operator=(const vector& x)
			{
				if (this == &x)
					return (*this);
				this->clear();
				if (x.size() > this->capacity())
					this->reserve(x.size());
				int i = 0;
				for (size_t i = 0; i < x.size(); i++)
					allocator_type().construct(this->_m_data + i, x[i]);
				this->_size = x.size();
				return (*this);
			};

			/* Iterators */
			iterator				begin()			{ return iterator(this->_m_data); };
			const_iterator			begin() const	{ return const_iterator(this->begin()); };
			iterator				end()			{ return iterator(this->begin() + this->size()); };
			const_iterator			end() const		{ return const_iterator(this->begin() + this->size()); };
			reverse_iterator		rbegin()		{ return reverse_iterator(this->end()); };
			const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(this->end()); };
			reverse_iterator		rend()			{ return reverse_iterator(this->begin()); };
			const_reverse_iterator	rend() const	{ return const_reverse_iterator(this->begin()); };

			/* Capacity */
			size_type	size() const		{ return this->_size; };
			size_type	max_size() const	{ return allocator_type().max_size(); };
			void		resize (size_type n, value_type val = value_type())
			{
				if (n < this->size())
					_erase_end_elements(n);
				if (n > this->size())
				{
					if (n > this->capacity())
						(n < (this->capacity() * 2)) ? this->reserve(this->capacity() * 2) : this->reserve(n);
					_append_elements(n, val);
				}
				this->_size = n;
			};
			size_type	capacity() const	{ return this->_capacity; };
			bool		empty() const
			{
				if (this->size() == 0)
					return true;
				return false;
			};
			void		reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("cannot create ft::vector larger than max_size()");
				if (n > this->capacity())
				{
					this->_m_data = _reallocate(n);
					this->_capacity = n;
				}
			};

			/* Element access */
			reference		operator[](size_type n)			{ return *(this->_m_data + n); };
			const_reference	operator[](size_type n) const	{ return *(this->_m_data + n); };
			reference		at(size_type n)					{ _range_check(n); return (*this)[n]; };
			const_reference	at(size_type n) const			{ _range_check(n); return (*this)[n]; };
			reference		front()							{ return *this->begin(); };
			const_reference	front() const					{ return *this->begin(); };
			reference		back()							{ return *(this->end() - 1); };
			const_reference	back() const					{ return *(this->end() - 1); };

			/* Modifiers */
			template <class InputIterator>
			void		assign(InputIterator first, InputIterator last)
			{
				int n = std::distance(first, last);
				this->clear();
				if (n > this->capacity())
					this->reserve(n);
				_fill_vector_elements(first, last);
				this->_size = n;
			};
			void		assign(size_type n, const value_type &val)
			{
				this->clear();
				if (n > this->capacity())
					this->reserve(n);
				_fill_vector_elements(n, val);
				this->_size = n;
			};
			void		push_back(const value_type& val)
			{
				if ((this->size() + 1) > this->capacity())
					(this->capacity() > 0) ? this->reserve(this->capacity() * 2) : this->reserve(1);
				allocator_type().construct(this->_m_data + this->size(), val);
				this->_size++;
			};
			void		pop_back()
			{
				allocator_type().destroy(this->_m_data + (this->size() - 1));
				this->_size--;
			};
			iterator	insert(iterator position, const value_type &val)
			{
				difference_type	diff = this->end() - position;
				if ((this->size() + 1) > this->capacity())
					reserve(this->capacity() * 2);
				iterator	it = this->end() - 1;
				if (diff < 0)
				{
					this->_size++;
					return (it);
				}
				while (diff > 0)
				{
					*(it + 1) = *it;
					it--;
					diff--;
				}
				it++;
				*it = val;
				this->_size++;
				return it;
			};
			void		insert(iterator position, size_type n, const value_type &val)
			{
				if (n > this->max_size())
					throw std::length_error("cannot create ft::vector larger than max_size()");
				difference_type	diff = this->end() - position;
				if ((this->size() + n) > this->capacity())
					((this->size() + n) < (this->capacity() * 2)) ? this->reserve(this->capacity() * 2) : this->reserve(this->size() + n);
				iterator it = this->end() - 1;
				while (diff > 0)
				{
					*(it + n) = *it;
					it--;
					diff--;
				}
				it++;
				for (size_t i = 0; i < n; i++)
				{
					*it = val;
					it++;
				}
				this->_size += n;
			};
			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				difference_type diff = this->end() - position;
				difference_type n = last - first;
				if ((this->size() + n) > this->capacity())
					((this->size() + n) < (this->capacity() * 2)) ? this->reserve(this->capacity() * 2) : this->reserve(this->size() + n);
				iterator	it = this->end() - 1;
				while (diff > 0)
				{
					*(it + n) = *it;
					it--;
					diff--;
				}
				it++;
				for (size_t i = 0; i < n; i++)
				{
					*it = *(first + i);
					it++;
				}
				this->_size += n;
			};
			iterator	erase(iterator position)
			{
				difference_type index = position - this->begin();
				allocator_type().destroy(this->_m_data + index);
				for (size_t i = index; i < (this->size() - 1); i++)
					this->_m_data[index] = this->_m_data[index + 1];
				this->_size--;
				return position;
			};
			iterator	erase(iterator first, iterator last)
			{
				difference_type index = first - this->begin();
				difference_type n = last - first;
				for (size_t i = 0; i < n; i++)
				{
					allocator_type().destroy(this->_m_data + index);
					index++;
				}
				for (size_t i = index; i < this->size(); i++)
					this->_m_data[i - n] = this->_m_data[i];
				this->_size -= n;
				return first;
			};
			void		swap(vector &x)
			{
				vector	tmp(x);
				x = *(this);
				x._capacity = this->_capacity;
				*(this) = tmp;
				this->_capacity = tmp._capacity;
			};
			void		clear()
			{
				for (size_t i = 0; i < this->size(); i++)
					allocator_type().destroy(this->_m_data + i);
				this->_size = 0;
			};

			/* Allocator */
			allocator_type  get_allocator() const { return allocator_type(); };
	};

	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	};

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(rhs < lhs);

	};

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return rhs < lhs;
	};

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		return !(lhs < rhs);
	};

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	};
}


#endif
