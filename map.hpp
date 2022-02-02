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

		protected:
			struct bstNode
			{
				value_type	data;
				bstNode*	leftChild;
				bstNode*	rightChild;
			};

		private:
			bstNode*	_root;
			size_type	_size;

		public:
			/* Constructors - Destructor - Assignment operator */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _root(0), _size(0)
			{
				
			};
			//template <class InputIterator>
			//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {};
			//map(const map& x) {};
			//~map() {};
			//map& operator=(const map& x) {};

			/* Iterators */
			//iterator				begin()			{  };
			//const_iterator			begin() const	{  };
			//iterator				end()			{  };
			//const_iterator			end() const		{  };
			//reverse_iterator		rbegin()		{  };
			//const_reverse_iterator	rbegin() const	{  };
			//reverse_iterator		rend()			{  };
			//const_reverse_iterator	rend() const	{  };

			/* Capacity */
			bool		empty() const
			{
				if (this->size() == 0)
					return true;
				return false;
			};
			size_type	size() const { return (this->_size); };
			size_type	max_size() const { return ((allocator_type().max_size()) / 3); };

			/* Element access */
			//mapped_type	&operator[](const key_type &k) {};

			/* Modifiers */
			//pair<iterator, bool>	insert(const value_type &val) {};
			//iterator				insert(iterator position, const value_type &val) {};
			//template <class InputIterator>
			//void					insert(InputIterator first, InputIterator last) {};
			//void					erase(iterator position) {};
			//size_type				erase(const key_type &k) {};
			//void					erase(iterator first, iterator last) {};
			//void					swap(map &x) {};
			//void					clear() {};

			/* Observers */
			//key_compare		key_comp() const {};
			//value_compare	value_comp() const {};

			/* Operations */
			//iterator								find(const key_type &k) {};
			//const_iterator							find(const key_type &k) const {};
			//size_type								count(const key_type &k) const {};
			//iterator								lower_bound(const key_type &k) {};
			//const_iterator							lower_bound(const key_type &k) const {};
			//iterator								upper_bound(const key_type &k) {};
			//const_iterator							upper_bound(const key_type &k) const {};
			//pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {};
			//pair<iterator, iterator>				equal_range(const key_type &k) {};

			/* Allocator */
			allocator_type	get_allocator() const { return allocator_type(); };
	};
}

#endif