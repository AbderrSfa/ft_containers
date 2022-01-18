/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 05:15:06 by asfaihi           #+#    #+#             */
/*   Updated: 2021/12/15 05:38:05 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "iterator.hpp"

namespace ft
{
    template < typename T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T												value_type;
            typedef Alloc											allocator_type;
            typedef typename allocator_type::reference				reference;
            typedef typename allocator_type::const_reference		const_reference;
            typedef typename allocator_type::pointer				pointer;
            typedef typename allocator_type::const_pointer			const_pointer;
            typedef typename allocator_type::difference_type		difference_type;
            typedef typename allocator_type::size_type				size_type;
            typedef VectorIt<pointer>		                        iterator;
            typedef VectorIt<const_pointer>	                        const_iterator;
            typedef VectorRevIt<iterator>                           reverse_iterator;
            typedef VectorRevIt<const_iterator>                     const_reverse_iterator;

        private:
            value_type* _m_data;
            size_type   _size;
            size_type   _capacity;

        public:
            /* Constructors */
            vector(): _m_data(), _size(0), _capacity(0) {};

            /* Iterators */
            iterator        begin() { return iterator(this->_m_data); };
            const_iterator  begin() const { return const_iterator(this->_m_data); };
            iterator        end() { return iterator(this->_m_data + this->_size); };
            const_iterator  end() const { return const_iterator(this->_m_data + this->_size); };
            reverse_iterator rbegin() { return reverse_iterator(this->end()); };
            const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); };
            reverse_iterator rend() { return reverse_iterator(this->begin()); } ;
            const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); };

            /* Capacity */
            size_type   size() const { return this->_size; };
            size_type   max_size() const { return allocator_type().max_size(); };
            //void resize (size_type n, value_type val = value_type());
            size_type   capacity() const { return this->_capacity; };
            bool        empty() const { return this->_size; };
            //void reserve (size_type n);
    };
}

#endif
