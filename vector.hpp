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


    };
}

#endif
