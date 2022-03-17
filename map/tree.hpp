/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:28 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/17 16:56:17 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>
# include "iterator.hpp"

namespace ft
{
	template <class T>
	class Node {
	public:
		T		data;
		Node*	parent;
		Node*	left;
		Node*	right;
		int		height;

		Node(T obj) : data(obj), left(NULL), right(NULL), parent(NULL), height(1) {};
	};

	template <class T, class Compare, class Allocator>
	class Tree {
	public:
		typedef T															value_type;
		typedef Compare														key_compare;
		typedef Allocator													allocator_type;

	private:
		typedef typename value_type::first_type								key_type;
		typedef typename allocator_type::template rebind<Node<T> >::other	node_allocator;
		typedef Node<value_type>											NodeType;
		typedef NodeType*													NodePtr;

	public:
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::const_reference					const_reference;
		typedef typename allocator_type::difference_type					difference_type;
		typedef typename allocator_type::pointer							pointer;
		typedef typename allocator_type::const_pointer						const_pointer;
		typedef typename allocator_type::size_type							size_type;
		typedef ft::TreeIt<pointer, NodePtr>								iterator;
		typedef ft::TreeIt<const_pointer, NodePtr>							const_iterator;
		typedef ft::RevTreeIt<pointer, NodePtr>								reverse_iterator;
		typedef ft::RevTreeIt<const_pointer, NodePtr>						const_reverse_iterator;

	private:
		NodePtr			_root;
		NodePtr			_end;
		size_t			_size;
		key_compare		_comp;
		node_allocator	_alloc;

	public:
		Tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _size(0) {
			this->_end = this->_alloc.allocate(1);
			this->_end->left = NULL;
			this->_end->right = NULL;
			this->_end->parent = NULL;
			this->_root = this->_end;
		};
		~Tree() {
			if (this->size())
				this->clear();
			this->_alloc.deallocate(this->_end, 1);
		}

		iterator		begin()							{ return iterator(this->_getMin(this->_root)); };
		const_iterator	begin() const					{ return const_iterator(this->_getMin(this->_root)); };
		iterator		end()							{ return iterator(this->_end); }
		const_iterator	end() const						{ return const_iterator(this->_end); }

		reverse_iterator		rbegin()				{ return reverse_iterator(this->_end); };
		const_reverse_iterator	rbegin() const			{ return const_reverse_iterator(this->_end); };
		reverse_iterator		rend()					{ return reverse_iterator(this->_getMin(this->_root)); };
		const_reverse_iterator	rend() const			{ return const_reverse_iterator(this->_getMin(this->_root)); };

		bool			empty() const					{ return (this->_size == 0); };
		size_type		size() const					{ return this->_size; };
		size_type		max_size() const				{ return this->_alloc.max_size(); };


		void			insert(T pair) {
			this->_root = _addNode(this->_root, this->_root, pair, pair.first);
			this->_getMax(this->_root)->right = this->_end;
			this->_end->parent = this->_getMax(this->_root);
		};
		bool			search(key_type key) const	{ return (_search(this->_root, key)); };
		NodePtr			find(key_type key) {
			if (!this->search(key))
				return this->_end;
			return _find(this->_root, key);
		};
		void			deleteNode(key_type key)		{ this->_root = _deleteNode(this->_root, key); };
		void			clear() {
			_deleteTree(this->_root);
			this->_end->parent = NULL;
			this->_root = this->_end;
			this->_size = 0;
		};
		void			printTree()						{ _print2DUtil(this->_root, 0); };

		NodePtr		lower_bound(key_type key) {
			NodePtr	temp = this->_getMin(this->_root);
			if (temp == NULL || temp == this->_end)
				return this->_end;
			while (temp->data.first <= key) {
				if (key == temp->data.first)
					break;
				temp = _getSuccessor(temp);
				if (temp == NULL || temp == this->_end)
					return this->_end;
			}
			return temp;
		}
		NodePtr		upper_bound(key_type key) {
			NodePtr	temp = this->_getMin(this->_root);
			if (temp == NULL || temp == this->_end)
				return this->_end;
			while (temp->data.first <= key) {
				temp = _getSuccessor(temp);
				if (temp == NULL || temp == this->_end)
					return this->_end;
			}
			return temp;
		}
		void	swap(Tree& x) {
			size_t			temp_size = x._size;
			NodePtr			temp_root = x._root;
			NodePtr			temp_end = x._end;
			node_allocator	temp_alloc = x._alloc;
			key_compare		temp_comp = x._comp;

			x._size = this->_size;
			x._root = this->_root;
			x._end = this->_end;
			x._alloc = this->_alloc;
			x._comp = this->_comp;

			this->_size = temp_size;
			this->_root = temp_root;
			this->_end = temp_end;
			this->_alloc = x._alloc;
			this->_comp = x._comp;
		}
		
	private:
		int	_getHeight(NodePtr node) const {
			if (node == NULL || node == this->_end)
				return 0;
			return node->height;
		};

		int	_getBalanceFactor(NodePtr node) const {
			if (node == NULL || node == this->_end)
				return 0;
			return _getHeight(node->left) - _getHeight(node->right);
		};

		NodePtr _getMax(NodePtr node) const {
			while (node->right != NULL && node->right != this->_end)
				node = node->right;
			return node;
		};

		NodePtr _getMin(NodePtr node) const {
			while (node->left != NULL && node != this->_end)
				node = node->left;
			return node;
		};

		NodePtr _rightRotate(NodePtr node) {
			NodePtr	temp = node->left;
			NodePtr	temp2 = temp->right;

			node->left = temp2;
			if (node->left)
				node->left->parent = node;
			temp->right = node;
			temp->parent = node->parent;
			if (node->parent && node->parent != this->_end) {
				if (node == node->parent->right)
					node->parent->right = temp;
				else
					node->parent->left = temp;
			}
			node->parent = temp;

			node->height = std::max(_getHeight(node->left),
				_getHeight(node->right)) + 1;
			temp->height = std::max(_getHeight(temp->left),
				_getHeight(temp->right)) + 1;
			return temp;
		};

		NodePtr _leftRotate(NodePtr node) {
			NodePtr	temp = node->right;
			NodePtr	temp2 = temp->left;

			node->right = temp2;
			if (node->right)
				node->right->parent = node;
			temp->left = node;
			temp->parent = node->parent;
			if (node->parent && node->parent != this->_end) {
				if (node == node->parent->right)
					node->parent->right = temp;
				else
					node->parent->left = temp;
			}
			node->parent = temp;

			node->height = std::max(_getHeight(node->left),
				_getHeight(node->right)) + 1;
			temp->height = std::max(_getHeight(temp->left),
				_getHeight(temp->right)) + 1;
			return temp;
		};

		NodePtr _checkBalance(NodePtr node, key_type key) {
			int	balanceFactor = _getBalanceFactor(node);
			if (balanceFactor > 1) {
				if (this->_comp(key, node->left->data.first))
					return _rightRotate(node);
				else {
					node->left = _leftRotate(node->left);
					return _rightRotate(node);
				}
			}
			else if (balanceFactor < -1) {
				if (this->_comp(key, node->right->data.first)) {
					node->right = _rightRotate(node->right);
					return _leftRotate(node);
				}
				else
					return _leftRotate(node);
			}
			return node;
		};

		NodePtr _reBalance(NodePtr node) {
			int balanceFactor = _getBalanceFactor(node);
			if (balanceFactor > 1) {
				if (_getBalanceFactor(node->left) >= 0)
					return _rightRotate(node);
				else {
					node->left = _leftRotate(node->left);
					return _rightRotate(node);
				}
			}
			else if (balanceFactor < -1) {
				if (_getBalanceFactor(node->right) <= 0)
					return _leftRotate(node);
				else {
					node->right = _rightRotate(node->right);
					return _leftRotate(node);
				}
			}
			return node;
		};

		void	_deleteTree(NodePtr node)
		{
			if (node == NULL || node == this->_end)
				return;
			_deleteTree(node->left);
			_deleteTree(node->right);
			this->_alloc.destroy(node);
			this->_alloc.deallocate(node, 1);
			node = NULL;
		}

		NodePtr _deleteNode(NodePtr node, key_type key) {
			if (node == NULL || node == this->_end)
				return node;
			if (this->_comp(key, node->data.first))
				node->left = _deleteNode(node->left, key);
			else if (this->_comp(node->data.first, key))
				node->right = _deleteNode(node->right, key);
			else {
				if (node->left == NULL) {
					NodePtr	temp = node;
					node = node->right;
					if (node)
						node->parent = temp->parent;
					this->_alloc.deallocate(temp, 1);
					temp = NULL;
					this->_size--;
				}
				else if (node->right == NULL) {
					NodePtr	temp = node;
					node = node->left;
					if (node)
						node->parent = temp->parent;
					this->_alloc.deallocate(temp, 1);
					temp = NULL;
					this->_size--;
				}
				else {
					NodePtr	temp = node;
					node = _getMin(node->right);
					node->parent = temp->parent;
					node->left = temp->left;
					temp->left->parent = node;
					this->_alloc.deallocate(temp, 1);
					this->_size--;
					// this->_alloc.construct(node, temp->data);
					// node->right = _deleteNode(node->right, temp->data.first);
				}
			}
			// else {
			// 	if ((node->left == NULL) || (node->right == NULL)) {
			// 		NodePtr	temp = node->left ? node->left : node->right;
			// 		if (temp == NULL) {
			// 			temp = node;
			// 			node = NULL;
			// 		}
			// 		else {
			// 			NodePtr	tempParent = node->parent;
			// 			*node = *temp;
			// 			node->parent = tempParent;
			// 		}
			// 		this->_alloc.destroy(temp);
			// 		this->_alloc.deallocate(temp, 1);
			// 		this->_size--;
			// 	}
			// 	else {
			// 		NodePtr	temp = _getMin(node->right);
			// 		node->data = temp->data;
			// 		node->right = _deleteNode(node->right, temp->data.first);
			// 	}
			// }
			if (node == NULL)
				return node;
			node->height = 1 + std::max(_getHeight(node->left), _getHeight(node->right));
			return _reBalance(node);
		};

		NodePtr		_find(NodePtr node, key_type key) const {
			if (node == NULL)
				return node;
			else if (this->_comp(key, node->data.first))
				return _find(node->left, key);
			if (this->_comp(node->data.first, key))
				return _find(node->right, key);
			else
				return node;
		}

		bool	_search(NodePtr node, key_type key) const {
			if (node == NULL || node == this->_end)
				return false;
			else if (this->_comp(key, node->data.first))
				return _search(node->left, key);
			if (this->_comp(node->data.first, key))
				return _search(node->right, key);
			else
				return true;
		};

		NodePtr _addNode(NodePtr node, NodePtr parent, T pair, key_type key) {
			if (node == NULL || node == this->_end)
			{
				NodePtr	ret = this->_alloc.allocate(1);
				this->_alloc.construct(ret, Node<T>(pair));
				if (parent != this->_end)
					ret->parent = parent;
				this->_size++;
				return ret;
			}
			if (this->_comp(key, node->data.first))
				node->left = _addNode(node->left, node, pair, key);
			else if (this->_comp(node->data.first, key))
				node->right = _addNode(node->right, node, pair, key);
			else
				return node;
			node->height = 1 + std::max(_getHeight(node->left), _getHeight(node->right));
			return _checkBalance(node, key);
		};

		void	_print2DUtil(NodePtr node, int space) const {
			if (node == NULL || node == this->_end)
				return;
			space += 20;
			_print2DUtil(node->right, space);
			std::cout << std::endl;
			for (int i = 10; i < space; i++)
				std::cout << " ";
			std::cout << "\033[32m";
			if (node->parent != NULL && node->parent != this->_end)
				std::cout << "(" << node->parent->data.first << ")<-";
			std::cout << "\033[0m";
			std::cout << "{" << node->data.first << " " << node->data.second << "} ";
			std::cout << "\033[32m";
			std::cout << node->height << "\n";
			std::cout << "\033[0m";
			_print2DUtil(node->left, space);
		};
	};

	template <class NodePtr>
	NodePtr _getMin(NodePtr node) {
		while (node->left != NULL)
			node = node->left;
		return node;
	};

	template <class NodePtr>
	NodePtr _getMax(NodePtr node) {
		while (node->right != NULL)
			node = node->right;
		return node;
	};

	template <class NodePtr>
	NodePtr	_getSuccessor(NodePtr node) {
		if (node->right)
			return _getMin(node->right);
		NodePtr	temp = node->parent;
		while (temp && node == temp->right) {
			node = temp;
			temp = temp->parent;
		}
		return temp;
	};

	template <class NodePtr>
	NodePtr	_getPredecessor(NodePtr node) {
		if (node->left)
			return _getMax(node->left);
		NodePtr	temp = node->parent;
		while (temp && node == temp->left) {
			node = temp;
			temp = temp->parent;
		}
		return temp;
	};
}

#endif