#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "mapIt.hpp"
# include "mapRevIt.hpp"

namespace ft
{
	template < class Key,
			   class T,
			   class Compare = std::less<Key>,
			   class Alloc = std::allocator<std::pair<const Key, T>>
			   >
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef mapIt<pointer>								iterator;
			typedef mapIt<const_pointer>						const_iterator;
			typedef mapRevIt<iterator>							reverse_iterator;
			typedef mapRevIt<const_iterator>					const_reverse_iterator;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			/* Constructors - Destructor - Assignment operator */
			explicit map(const key_compare &comp = key_compare(),
						 const allocator_type &alloc = allocator_type()) {};

			/* Iterators */
			iterator                begin()         {  };
			const_iterator          begin() const   {  };
			iterator                end()           {  };
			const_iterator          end() const     {  };
			reverse_iterator        rbegin()        {  };
			const_reverse_iterator  rbegin() const  {  };
			reverse_iterator        rend()          { } ;
			const_reverse_iterator  rend() const    {  };

			/* Capacity */

			/* Element access */

			/* Modifiers */

			/* Observers */

			/* Operations */

			/* Allocator */
			allocator_type	get_allocator() const { return allocator_type(); };
	};
}

#endif