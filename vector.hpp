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

# include <memory>
# include <iostream>

namespace ft
{
    template < typename T, class Alloc = std::allocator<T> >
    class vector
    {
        protected:
            typedef T												value_type;
            typedef typename Alloc::reference						reference;
            typedef typename Alloc::const_reference					const_reference;
            typedef typename Alloc::pointer							pointer;
            typedef typename Alloc::const_pointer					const_pointer;
            typedef typename Alloc::difference_type					difference_type;
            typedef __gnu_cxx::__normal_iterator<pointer, T>		iterator;
            typedef __gnu_cxx::__normal_iterator<const_pointer, T>	const_iterator;
            typedef std::reverse_iterator<iterator>					reverse_iterator;
            typedef	std::reverse_iterator<const_iterator>			const_reverse_iterator;

        public:
            typedef typename Alloc::size_type						size_type;
            typedef Alloc											allocator_type;

            ft_vector( void ) {};
            ~ft_vector() {};

    };
}

#endif
