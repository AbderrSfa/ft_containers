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
			//key_type should be const
			typedef std::pair<key_type, mapped_type>		value_type;
			//
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

			bstNode *makeNewNode(value_type data)
			{
				bstNode *newNode = new bstNode();

				newNode->data = data;
				newNode->leftChild = NULL;
				newNode->rightChild = NULL;
				return (newNode);
			};
			bstNode *insert(bstNode *root, value_type data)
			{
				if (root == NULL)
					root = makeNewNode(data);
				else if (data.first <= root->data.first)
					root->leftChild = insert(root->leftChild, data);
				else
					root->rightChild = insert(root->rightChild, data);
				return (root);
			};


			void print2DUtil(bstNode *root, int space)
			{
				if (root == NULL)
					return;
				space += 10;
				print2DUtil(root->rightChild, space);
				std::cout << std::endl;
				for (int i = 10; i < space; i++)
					std::cout << " ";
				std::cout << "{" << root->data.first << ", " << root->data.second << "}\n";
				print2DUtil(root->leftChild, space);
			};
			void print2D(bstNode *root)
			{
				print2DUtil(root, 0);
			};

		private:
			bstNode*	_root;
			size_type	_nodeCount;

		public:
			void	printTree() { print2D(this->_root); };

			/* Constructors - Destructor - Assignment operator */
			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _root(0), _nodeCount(0)
			{
				this->_root = insert(this->_root, {10, 'f'});
				this->_root = insert(this->_root, {5, 'a'});
				this->_root = insert(this->_root, {55, 'a'});
				this->_root = insert(this->_root, {7, 'd'});
			};

			//template <class InputIterator>
			//map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {};
			//map(const map& x) {};
			//~map() {};
			//map& operator=(const map& x) {};

			/* Iterators */
			//iterator				begin()			{ return iterator(this->_root->data); };
			//const_iterator			begin() const	{ return const_iterator(this->_root->data); };
			//iterator				end()			{  };
			//const_iterator			end() const		{  };
			//reverse_iterator		rbegin()		{ return reverse_iterator(this->end()); };
			//const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(this->end()); };
			//reverse_iterator		rend()			{ return reverse_iterator(this->begin()); };
			//const_reverse_iterator	rend() const	{ return const_reverse_iterator(this->begin()); };

			/* Capacity */
			bool		empty() const
			{
				if (this->size() == 0)
					return true;
				return false;
			};
			size_type	size() const { return (this->_nodeCount); };
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
			key_compare		key_comp() const { return key_compare(); };
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