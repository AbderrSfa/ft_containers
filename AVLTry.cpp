#include <iostream>
#include <cstdlib>

template <class T>
class Node {
public:
	T		data;
	Node*	parent;
	Node*	left;
	Node*	right;

	Node(T obj) {
		data = obj;
		parent = NULL;
		left = NULL;
		right = NULL;
	};

};

template <class T>
class AVLTree {
private:
	Node<T>*	root;
	size_t		CurrentSize;

	int maxHeight(Node<T>* node) {
		if (node == NULL)
			return -1;
		else
		{
			int lDepth = maxHeight(node->left);
			int rDepth = maxHeight(node->right);

			if (lDepth > rDepth)
				return(lDepth + 1);
			else
				return(rDepth + 1);
		}
	};
	
	void	print2DUtil(Node<T>* root, int space) {
		if (root == NULL)
			return;
		space += 10;
		print2DUtil(root->right, space);
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << "{" << root->data << "} " << abs(maxHeight(root->left) - maxHeight(root->right)) << "\n";
		print2DUtil(root->left, space);
	};

	Node<T>* rightLeftRotate(Node<T>* node) {
		node->right = rightRotate(node->right);
		return (leftRotate(node));
	};

	Node<T>* leftRightRotate(Node<T>* node) {
		node->left = leftRotate(node->left);
		return (rightRotate(node));
	};

	Node<T>* leftRotate(Node<T>* node) {
		Node<T>* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		temp->parent = node->parent;
		if (node->parent) {
			if (node == node->parent->right)
				node->parent->right = temp;
			else
				node->parent->left = temp;
		}
		else
			node->parent = temp;
		return (temp);
	};

	Node<T>* rightRotate(Node<T>* node) {
		Node<T>* temp = node->left;
		node->left = temp->right;
		temp->right = node;
		temp->parent = node->parent;
		if (node->parent) {
			if (node == node->parent->right)
				node->parent->right = temp;
			else
				node->parent->left = temp;
		}
		else
			node->parent = temp;
		return (temp);
	};

	void	rebalanceTree(Node<T>* node) {
		if (maxHeight(node->left) - maxHeight(node->right) > 1) {
			if (maxHeight(node->left->left) > maxHeight(node->left->right)) {
				std::cout << "right rotation\n";
				node = rightRotate(node);
			}
			else {
				std::cout << "left-right rotation\n";
				node = leftRightRotate(node);
			}
		}
		else {
			if (maxHeight(node->right->right) > maxHeight(node->right->left)) {
				std::cout << "left rotation\n";
				node = leftRotate(node);
			}
			else {
				std::cout << "right-left rotation\n";
				node = rightLeftRotate(node);
			}
		}
		if (node->parent == NULL)
			this->root = node;
	};

	void	checkBalance(Node<T>* node) {
		if ((maxHeight(node->left) - maxHeight(node->right) > 1)
			|| (maxHeight(node->left) - maxHeight(node->right) < -1))
		{
			rebalanceTree(node);
		}
		if (node->parent == NULL)
			return;
		checkBalance(node->parent);
	};

	void	add(Node<T>* parent, Node<T>* newNode) {
		if (newNode->data > parent->data) {
			if (parent->right == NULL) {
				parent->right = newNode;
				newNode->parent = parent;
				this->CurrentSize++;
			}
			else {
				add(parent->right, newNode);
			}
		}
		else
		{
			if (parent->left == NULL) {
				parent->left = newNode;
				newNode->parent = parent;
				this->CurrentSize++;
			}
			else {
				add(parent->left, newNode);
			}
		}
		checkBalance(newNode);
	};

public:
	AVLTree() {
		root = NULL;
		CurrentSize = 0;
	};

	void	printTree() {
		std::cout << "||||||||||||||||\n";
		print2DUtil(this->root, 0);
		std::cout << "||||||||||||||||\n\n";
	};

	void	add(T obj) {
		Node<T>* node = new Node<T>(obj);
		if (this->root == NULL) {
			this->root = node;
			this->CurrentSize++;
			return;
		}
		add(this->root, node);
	};
};

int		main() {
	AVLTree<int>	tree;

	tree.add(52);
	tree.add(38);
	tree.add(25);
	tree.add(40);
	tree.add(61);
	tree.add(74);
	tree.add(23);
	tree.add(35);
	tree.add(68);
	//tree.add(57);
	//tree.add(65);
	//tree.add(53);
	//tree.add(34);
	//tree.add(18);
	//tree.add(88);
	//tree.add(80);
	//tree.add(67);
	//tree.add(57);
	//tree.add(37);
	//tree.add(85);
	//tree.add(17);
	//tree.add(36);
	//tree.add(10);
	//tree.add(2);
	//tree.add(35);
	//tree.add(3);
	//tree.add(89);
	//tree.add(59);
	//tree.add(50);
	tree.printTree();
	return (0);
}