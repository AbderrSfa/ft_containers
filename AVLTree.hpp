/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:28 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/18 13:54:09 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_PAIR_HPP
# define AVL_TREE_PAIR_HPP

# include <iostream>
# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

template <class T>
class Node {
public:
	T		data;
	Node*	left;
	Node*	right;
	int		height;


	Node(T obj) {
		data = obj;
		left = NULL;
		right = NULL;
		height = 1;
	};
};

template <class T, class Compare, class Alloc = std::allocator<Node<T> > >
class AVLTree {
private:
	typedef typename T::first_type	first_type;
	Node<T>*			root;
	size_t				CurrentSize;

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
		temp->right = node;
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
		temp->left = node;
		node->height = max(getHeight(node->left),
			getHeight(node->right)) + 1;
		temp->height = max(getHeight(temp->left),
			getHeight(temp->right)) + 1;
		return temp;
	};
	
	Node<T>* checkBalance(Node<T>* node, first_type key) {
		int	balanceFactor = getBalanceFactor(node);
		if (balanceFactor > 1) {
			if (key < node->left->data.first)
				return rightRotate(node);
			else {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		else if (balanceFactor < -1) {
			if (key > node->right->data.first)
				return leftRotate(node);
			else {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
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

	
	Node<T>* deleteNode(Node<T>* node, first_type key) {
		if (node == NULL)
			return node;
		if (key < node->data.first)
			node->left = deleteNode(node->left, key);
		else if (key > node->data.first)
			node->right = deleteNode(node->right, key);
		else {
			if ((node->left == NULL) || (node->right == NULL)) {
				Node<T>*	temp = node->left ? node->left : node->right;
				if (temp == NULL) {
					temp = node;
					node = NULL;
				}
				else
					*node = *temp;
				Alloc().destroy(temp);
				Alloc().deallocate(temp, 1);
				this->CurrentSize--;
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
		else if (node->data.first == key)
			return node->data;
		else if (key < node->data.first)
			return find(node->left, key);
		else
			return find(node->right, key);
	}
	
	bool	search(Node<T>* node, first_type key) const {
		if (node == NULL)
			return false;
		else if (node->data.first == key)
			return true;
		else if (key < node->data.first)
			return search(node->left, key);
		else
			return search(node->right, key);
	};

	Node<T>* addNode(Node<T>* node, T pair, first_type key) {
		if (node == NULL)
		{
			Node<T>*	ret = Alloc().allocate(1);
			Alloc().construct(ret, Node<T>(pair));
			this->CurrentSize++;
			return ret;
		}
		if (key < node->data.first)
			node->left = addNode(node->left, pair, key);
		else if (key > node->data.first)
			node->right = addNode(node->right, pair, key);
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
		std::cout << "{" << node->data.first << " " << node->data.second << "} ";
		std::cout << GREEN;
		std::cout << node->height << "\n";
		std::cout << RESET;
		print2DUtil(node->left, space);
	};
	
public:
	AVLTree() {
		this->root = NULL;
		this->CurrentSize = 0;
	};

	void	insert(T pair) {
		this->root = addNode(this->root, pair, pair.first);
	};

	bool	search(first_type key) const {
		return (search(this->root, key));
	};

	T		find(first_type key) {
		return (find(this->root, key));
	};

	void	deleteNode(first_type key) {
		this->root = deleteNode(this->root, key);
	};
	
	void	printTree() const {
		print2DUtil(this->root, 0);
	};
};

#endif