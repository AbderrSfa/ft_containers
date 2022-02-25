/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:28 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/25 13:44:55 by asfaihi          ###   ########.fr       */
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

template <class T, class Compare, class Allocator = std::allocator<Node<T> > >
class Tree {
public:
	typedef T						value_type;
	typedef Compare					value_compare;
	typedef Allocator				allocator_type;

private:
	typedef typename T::first_type	first_type;
	Node<T>*		_root;
	size_t			_CurrentSize;
	value_compare	_comp;
	
	int	getHeight(Node<T>* node) const {
		if (node == NULL)
			return 0;
		return node->height;
	};

	int max(int a, int b) const {
		return (a > b) ? a : b;
	};

	int	getBalanceFactor(Node<T>* node) const {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	};

	Node<T>* rightRotate(Node<T>* node) {
		Node<T>*	temp = node->left;
		Node<T>*	temp2 = temp->right;

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
		
		node->height = max(getHeight(node->left),
			getHeight(node->right)) + 1;
		temp->height = max(getHeight(temp->left),
			getHeight(temp->right)) + 1;
		return temp;
	};

	Node<T>* leftRotate(Node<T>* node) {
		Node<T>*	temp = node->right;
		Node<T>*	temp2 = temp->left;

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
		
		node->height = max(getHeight(node->left),
			getHeight(node->right)) + 1;
		temp->height = max(getHeight(temp->left),
			getHeight(temp->right)) + 1;
		return temp;
	};
	
	Node<T>* checkBalance(Node<T>* node, first_type key) {
		int	balanceFactor = getBalanceFactor(node);
		if (balanceFactor > 1) {
			if (this->_comp(key, node->left->data.first))
				return rightRotate(node);
			else {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		else if (balanceFactor < -1) {
			if (this->_comp(key, node->right->data.first)) {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			else
				return leftRotate(node);
		}
		return node;
	};

	Node<T>* getMinSuccessor(Node<T>* node) const {
		Node<T>*	current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	};
	
	Node<T>* reBalance(Node<T>* node) {
		int balanceFactor = getBalanceFactor(node);
		if (balanceFactor > 1) {
			if (getBalanceFactor(node->left) >= 0)
				return rightRotate(node);
			else {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		else if (balanceFactor < -1) {
			if (getBalanceFactor(node->right) <= 0)
				return leftRotate(node);
			else {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		}
		return node;
	};

	void	deleteTree(Node<T>* node)
	{
		if (node == NULL)
			return;
		deleteTree(node->left);
		deleteTree(node->right);
		allocator_type().destroy(node);
		allocator_type().deallocate(node, 1);
	}
	
	Node<T>* deleteNode(Node<T>* node, first_type key) {
		if (node == NULL)
			return node;
		if (this->_comp(key, node->data.first))
			node->left = deleteNode(node->left, key);
		else if (this->_comp(node->data.first, key))
			node->right = deleteNode(node->right, key);
		else {
			if ((node->left == NULL) || (node->right == NULL)) {
				Node<T>*	temp = node->left ? node->left : node->right;
				if (temp == NULL) {
					temp = node;
					node = NULL;
				}
				else {
					Node<T>*	tempParent = node->parent;
					*node = *temp;
					node->parent = tempParent;
				}
				allocator_type().destroy(temp);
				allocator_type().deallocate(temp, 1);
				this->_CurrentSize--;
			}
			else {
				Node<T>*	temp = getMinSuccessor(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data.first);
			}
		}
		if (node == NULL)
			return node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		return reBalance(node);
	};

	T		find(Node<T>* node, first_type key) {
		if (node == NULL)
			return node->data;
		else if (this->_comp(key, node->data.first))
			return find(node->left, key);
		if (this->_comp(node->data.first, key))
			return find(node->right, key);
		else
			return node->data;
	}
	
	bool	search(Node<T>* node, first_type key) const {
		if (node == NULL)
			return false;
		else if (this->_comp(key, node->data.first))
			return search(node->left, key);
		if (this->_comp(node->data.first, key))
			return search(node->right, key);
		else
			return true;
	};

	Node<T>* addNode(Node<T>* node, Node<T>* parent, T pair, first_type key) {
		if (node == NULL)
		{
			Node<T>*	ret = allocator_type().allocate(1);
			allocator_type().construct(ret, Node<T>(pair));
			ret->parent = parent;
			this->_CurrentSize++;
			return ret;
		}
		if (this->_comp(key, node->data.first))
			node->left = addNode(node->left, node, pair, key);
		else if (this->_comp(node->data.first, key))
			node->right = addNode(node->right, node, pair, key);
		else
			return node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));		
		return checkBalance(node, key);
	};

	void	print2DUtil(Node<T>* node, int space) const {
		if (node == NULL)
			return;
		space += 20;
		print2DUtil(node->right, space);
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
		print2DUtil(node->left, space);
	};
	
public:
	Tree() {
		this->_root = NULL; this->_CurrentSize = 0;
	};
	void	insert(T pair) { this->_root = addNode(this->_root, this->_root, pair, pair.first); };
	size_t	size() const					{ return this->_CurrentSize; };
	bool	search(first_type key) const	{ return (search(this->_root, key)); };
	T		find(first_type key)			{ return (find(this->_root, key)); };
	void	deleteNode(first_type key)		{ this->_root = deleteNode(this->_root, key); };
	void	clear()							{ deleteTree(this->_root); this->_CurrentSize = 0; };
	void	printTree() const				{ print2DUtil(this->_root, 0); };
};

#endif