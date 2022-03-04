/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:28 by asfaihi           #+#    #+#             */
/*   Updated: 2022/03/04 11:11:48 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <iostream>

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
	typedef Compare														value_compare;
	typedef Allocator													allocator_type;

private:
	typedef typename value_type::first_type	first_type;
	typedef typename allocator_type::template rebind<Node<T> >::other	node_allocator;
	typedef Node<value_type>											Node_type;
	typedef Node_type*													Node_ptr;

public:
	typedef typename allocator_type::reference							reference;
	typedef typename allocator_type::const_reference					const_reference;
	typedef typename allocator_type::difference_type					difference_type;
	typedef typename allocator_type::pointer							pointer;
	typedef typename allocator_type::const_pointer						const_pointer;
	typedef typename allocator_type::size_type							size_type;
	typedef ft::TreeIt<Node_ptr>										iterator;
	typedef ft::TreeIt<Node_ptr>										const_iterator;

private:
	Node_ptr		_root;
	Node_ptr		_end;
	size_t			_CurrentSize;
	value_compare	_comp;
	node_allocator	_alloc;

public:
	Tree() {
		this->_end = this->_alloc.allocate(1);
		// this->_root = this->_end;
		this->_CurrentSize = 0;
	};
	~Tree() {
		if (this->size())
			this->clear();
	}

	iterator		begin()							{ return iterator(this->_root); };
	const_iterator	begin() const					{ return const_iterator(this->_root); };
	iterator		end()							{ return iterator(this->end); }
	const_iterator	end() const						{ return const_iterator(this->end); }

	bool			empty() const					{ return (this->_CurrentSize == 0); };
	size_type		size() const					{ return this->_CurrentSize; };
	size_type		max_size() const				{ return this->_alloc.max_size(); };


	void			insert(T pair)					{ this->_root = _addNode(this->_root, this->_root, pair, pair.first); };
	bool			search(first_type key) const	{ return (_search(this->_root, key)); };
	Node_ptr		find(first_type key)			{ return (_find(this->_root, key)); };
	void			deleteNode(first_type key)		{ this->_root = _deleteNode(this->_root, key); };
	void			clear()							{ _deleteTree(this->_root); this->_CurrentSize = 0; };
	void			printTree() const				{ _print2DUtil(this->_root, 0); };

private:
	int	_getHeight(Node_ptr node) const {
		if (node == NULL)
			return 0;
		return node->height;
	};

	int _max(int a, int b) const {
		return (a > b) ? a : b;
	};

	int	_getBalanceFactor(Node_ptr node) const {
		if (node == NULL)
			return 0;
		return _getHeight(node->left) - _getHeight(node->right);
	};

	Node_ptr _rightRotate(Node_ptr node) {
		Node_ptr	temp = node->left;
		Node_ptr	temp2 = temp->right;

		node->left = temp2;
		if (node->left)
			node->left->parent = node;
		temp->right = node;
		temp->parent = node->parent;
		if (node->parent) {
			if (node == node->parent->right)
				node->parent->right = temp;
			else
				node->parent->left = temp;
		}
		node->parent = temp;
		
		node->height = _max(_getHeight(node->left),
			_getHeight(node->right)) + 1;
		temp->height = _max(_getHeight(temp->left),
			_getHeight(temp->right)) + 1;
		return temp;
	};

	Node_ptr _leftRotate(Node_ptr node) {
		Node_ptr	temp = node->right;
		Node_ptr	temp2 = temp->left;

		node->right = temp2;
		if (node->right)
			node->right->parent = node;
		temp->left = node;
		temp->parent = node->parent;
		if (node->parent) {
			if (node == node->parent->right)
				node->parent->right = temp;
			else
				node->parent->left = temp;
		}
		node->parent = temp;
		
		node->height = _max(_getHeight(node->left),
			_getHeight(node->right)) + 1;
		temp->height = _max(_getHeight(temp->left),
			_getHeight(temp->right)) + 1;
		return temp;
	};

	Node_ptr _checkBalance(Node_ptr node, first_type key) {
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

	Node_ptr _getMinSuccessor(Node_ptr node) const {
		Node_ptr	current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	};

	Node_ptr _reBalance(Node_ptr node) {
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

	void	_deleteTree(Node_ptr node)
	{
		if (node == NULL)
			return;
		_deleteTree(node->left);
		_deleteTree(node->right);
		this->_alloc.destroy(node);
		this->_alloc.deallocate(node, 1);
	}

	Node_ptr _deleteNode(Node_ptr node, first_type key) {
		if (node == NULL)
			return node;
		if (this->_comp(key, node->data.first))
			node->left = _deleteNode(node->left, key);
		else if (this->_comp(node->data.first, key))
			node->right = _deleteNode(node->right, key);
		else {
			if ((node->left == NULL) || (node->right == NULL)) {
				Node_ptr	temp = node->left ? node->left : node->right;
				if (temp == NULL) {
					temp = node;
					node = NULL;
				}
				else {
					Node_ptr	tempParent = node->parent;
					*node = *temp;
					node->parent = tempParent;
				}
				this->_alloc.destroy(temp);
				this->_alloc.deallocate(temp, 1);
				this->_CurrentSize--;
			}
			else {
				Node_ptr	temp = _getMinSuccessor(node->right);
				node->data = temp->data;
				node->right = _deleteNode(node->right, temp->data.first);
			}
		}
		if (node == NULL)
			return node;
		node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));
		return _reBalance(node);
	};

	T		_find(Node_ptr node, first_type key) {
		if (node == NULL)
			return node->data;
		else if (this->_comp(key, node->data.first))
			return _find(node->left, key);
		if (this->_comp(node->data.first, key))
			return _find(node->right, key);
		else
			return node->data;
	}

	bool	_search(Node_ptr node, first_type key) const {
		if (node == NULL)
			return false;
		else if (this->_comp(key, node->data.first))
			return _search(node->left, key);
		if (this->_comp(node->data.first, key))
			return _search(node->right, key);
		else
			return true;
	};

	Node_ptr _addNode(Node_ptr node, Node_ptr parent, T pair, first_type key) {
		if (node == NULL)
		{
			Node_ptr	ret = this->_alloc.allocate(1);
			this->_alloc.construct(ret, Node<T>(pair));
			ret->parent = parent;
			this->_CurrentSize++;
			return ret;
		}
		if (this->_comp(key, node->data.first))
			node->left = _addNode(node->left, node, pair, key);
		else if (this->_comp(node->data.first, key))
			node->right = _addNode(node->right, node, pair, key);
		else
			return node;
		node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));		
		return _checkBalance(node, key);
	};

	void	_print2DUtil(Node_ptr node, int space) const {
		if (node == NULL)
			return;
		space += 20;
		_print2DUtil(node->right, space);
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << "\033[32m";
		if (node->parent)
			std::cout << "(" << node->parent->data.first << ")<-";
		std::cout << "\033[0m";
		std::cout << "{" << node->data.first << " " << node->data.second << "} ";
		std::cout << "\033[32m";
		std::cout << node->height << "\n";
		std::cout << "\033[0m";
		_print2DUtil(node->left, space);
	};
};

#endif