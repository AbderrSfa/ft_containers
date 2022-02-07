#include <iostream>

template <class T>
class Node {
public:
	T		data;
	Node*	parent;
	Node*	left;
	Node*	right;

	Node(T obj) {
		data = obj;
		parent = left = right = NULL;
	};

};

template <class T>
class AVLTree {
private:
	Node<T>*	root;
	size_t		CurrentSize;

	int maxHeight(Node<T>* node)
	{
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
	}
	
	void	print2DUtil(Node<T>* root, int space)
	{
		if (root == NULL)
			return;
		space += 10;
		print2DUtil(root->right, space);
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << "{" << root->data << "} " << maxHeight(root) << "\n";
		print2DUtil(root->left, space);
	};
	void	checkBalance(Node<T>* node) {
		if ((maxHeight(node->left) - maxHeight(node->right) > 1)
			|| (maxHeight(node->left) - maxHeight(node->right) < -1))
		{
			std::cout << "needs rebalancing\n";
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
		print2DUtil(this->root, 0);
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

	tree.add(5);
	tree.add(10);
	tree.add(1);
	tree.add(18);
	tree.add(16);
	tree.add(11);
	tree.printTree();
	return (0);
}