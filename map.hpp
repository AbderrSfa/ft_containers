#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>

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
			
			/*			typedef ;
						typedef ;
						typedef ;
						typedef ;
						typedef ;
						typedef ;
						typedef ;
						typedef ;*/

			explicit map(const key_compare &comp = key_compare(),
						 const allocator_type &alloc = allocator_type()) {};
	};
}

#endif