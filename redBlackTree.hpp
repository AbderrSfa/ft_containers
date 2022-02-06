#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

namespace ft
{
	template <class K, class V>
	class Node
	{
		public:
			K		key;
			V		value;
			Node*	parent;
			Node*	right;
			Node*	left;
			bool	isBlack;

			Node(K key, V value)
			{
				this->key = key;
				this->value = value;
				this->left = this->right = this->parent = NULL;
				this->isBlack = false;
			};
	};

	template <class K, class V>
	class redBlackTree
	{
		private:
			Node<K, V>*	_root;
			size_t		_size;

			void	lmao(Node<K, V>* parent, Node<K, V> newNode)
			{
				if (newNode.key > parent->key)
				{
					if (parent->right == NULL)
					{
						parent->right = &newNode;
						newNode.parent = parent;
					}
				}
			};

		protected:
			void print2DUtil(Node<K, V> *root, int space)
			{
				if (root == NULL)
					return;
				space += 10;
				print2DUtil(root->right, space);
				std::cout << std::endl;
				for (int i = 10; i < space; i++)
					std::cout << " ";
				if (root->isBlack == false)
					std::cout << RED;
				std::cout << "{" << root->key << ", " << root->value << "}\n";
				std::cout << RESET;
				print2DUtil(root->left, space);
			};
			void print2D(Node<K, V> *root)
			{
				print2DUtil(root, 0);
			};

		public:
			redBlackTree() : _root(), _size(0) {};
			void	add(K key, V value)
			{
				Node<K, V>* node = new Node<K, V>(key, value); // Needs to be changed to allocator
				if (this->_root == NULL) {
					this->_root = node;
					this->_root->isBlack = true;
					this->_size++;
					return;
				}
				lmao(this->_root, *node);
				this->_size++;
			};
			void printTree() { print2D(this->_root); };
	};
}

#endif