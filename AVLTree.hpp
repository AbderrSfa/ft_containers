/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asfaihi <asfaihi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:41:28 by asfaihi           #+#    #+#             */
/*   Updated: 2022/02/17 15:02:22 by asfaihi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP

# include <iostream>

template <class K, class V>
class Node {
public:
	K		key;
	V		value;
	Node*	left;
	Node*	right;
	int		height;


	Node(K objKey, V objVal) {
		key = objKey;
		value = objVal;
		left = NULL;
		right = NULL;
		height = 1;
	};

};

template <class K, class V, class Alloc>
class AVLTree {
private:
	Node<K, V>*	root;
	size_t		CurrentSize;

	int	getHeight(Node<K, V>* node) {
		if (node == NULL)
			return 0;
		return node->height;
	};

	int max(int a, int b) {
		return (a > b) ? a : b;
	};

	int	getBalanceFactor(Node<K, V>* node) {
		if (node == NULL)
			return 0;
		return getHeight(node->left) - getHeight(node->right);
	};

	Node<K, V>* rightRotate(Node<K, V>* node) {
		Node<K, V>*	temp = node->left;
		Node<K, V>*	temp2 = temp->right;
		node->left = temp2;
		temp->right = node;
		node->height = max(getHeight(node->left),
			getHeight(node->right)) + 1;
		temp->height = max(getHeight(temp->left),
			getHeight(temp->right)) + 1;
		return temp;
	};

	Node<K, V>* leftRotate(Node<K, V>* node) {
		Node<K, V>*	temp = node->right;
		Node<K, V>*	temp2 = temp->left;
		node->right = temp2;
		temp->left = node;
		node->height = max(getHeight(node->left),
			getHeight(node->right)) + 1;
		temp->height = max(getHeight(temp->left),
			getHeight(temp->right)) + 1;
		return temp;
	};

	Node<K, V>* checkBalance(Node<K, V>* node, K key) {
		int	balanceFactor = getBalanceFactor(node);
		if (balanceFactor > 1) {
			if (key < node->left->key)
				return rightRotate(node);
			else {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		else if (balanceFactor < -1) {
			if (key > node->right->key)
				return leftRotate(node);
			else {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		}
		return node;
	};

	Node<K, V>* getMinSuccessor(Node<K, V>* node) {
		Node<K, V>*	current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	};

	Node<K, V>* reBalance(Node<K, V>* node) {
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

	bool	search(Node<K, V>* node, K key) {
		if (node == NULL)
			return false;
		else if (node->key == key)
			return true;
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	};

	Node<K, V>* deleteNode(Node<K, V>* node, K key) {
		if (node == NULL)
			return node;
		if (key < node->key)
			node->left = deleteNode(node->left, key);
		else if (key > node->key)
			node->right = deleteNode(node->right, key);
		else {
			if ((node->left == NULL) || (node->right == NULL)) {
				Node<K, V>*	temp = node->left ? node->left : node->right;
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
				Node<K, V>*	temp = getMinSuccessor(node->right);
				node->key = temp->key;
				node->value = temp->value;
				node->right = deleteNode(node->right, temp->key);
			}
		}
		if (node == NULL)
			return node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		return reBalance(node);
	};

	Node<K, V>* addNode(Node<K, V>* node, K key, V value) {
		if (node == NULL)
		{
			Node<K, V>*	ret = Alloc().allocate(1);
			Alloc().construct(ret, Node<K, V>(key, value));
			this->CurrentSize++;
			return ret;
		}
		if (key < node->key)
			node->left = addNode(node->left, key, value);
		else if (key > node->key)
			node->right = addNode(node->right, key, value);
		else
			return node;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		return checkBalance(node, key);
	};

	void	print2DUtil(Node<K, V>* node, int space) {
		if (node == NULL)
			return;
		space += 20;
		print2DUtil(node->right, space);
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << "{" << node->key << " " << node->value << "} ";
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

	void	insert(K objKey, V objVal) {
		this->root = addNode(this->root, objKey, objVal);
	};

	bool	search(K key) {
		return (search(this->root, key));
	};

	void	deleteNode(K objKey) {
		this->root = deleteNode(this->root, objKey);
	};

	void	printTree() {
		print2DUtil(this->root, 0);
	};
};

#endif