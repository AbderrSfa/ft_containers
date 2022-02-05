#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

namespace ft
{
	template <class K, class V>
	struct Node
	{
		K		key;
		V		value;
		Node*	parent;
		Node*	right;
		Node*	left;
		bool	isBlack;
	};

	template <class K, class V>
	class redBlackTree
	{
		private:
			Node<K, V>	_root;
			size_t		_size;

		public:
			void	add(K key, V value)
			{
				Node<K, V> node = new Node<K, V>(key, value); // Needs to be changed to allocator
				if (this->_root == NULL) {
					this->_root = node;
					this->_root.isBlack = true;
					this->_size++;
					return ;
				}
			};
	};
}

#endif