#include <iostream>
#include <cstdlib>

template <class K, class V>
class Node {
public:
	K		key;
	V		value;
	Node* parent;
	Node* left;
	Node* right;

	Node(K objKey, V objVal) {
		key = objKey;
		value = objVal;
		parent = NULL;
		left = NULL;
		right = NULL;
	};
};

template <class K, class V>
class AVLTree {
private:
	Node<K, V>* root;
	size_t		CurrentSize;

	int maxHeight(Node<K, V>* node) {
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
	
	void	print2DUtil(Node<K, V>* root, int space) {
		if (root == NULL)
			return;
		space += 10;
		print2DUtil(root->right, space);
		std::cout << std::endl;
		for (int i = 10; i < space; i++)
			std::cout << " ";
		std::cout << "{" << root->key << " " << root->value << "} " << abs(maxHeight(root->left) - maxHeight(root->right)) << "\n";
		print2DUtil(root->left, space);
	};

	Node<K, V>* rightLeftRotate(Node<K, V>* node) {
		node->right = rightRotate(node->right);
		return (leftRotate(node));
	};

	Node<K, V>* leftRightRotate(Node<K, V>* node) {
		node->left = leftRotate(node->left);
		return (rightRotate(node));
	};

	Node<K, V>* leftRotate(Node<K, V>* node) {
		Node<K, V>* temp = node->right;
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

	Node<K, V>* rightRotate(Node<K, V>* node) {
		Node<K, V>* temp = node->left;
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
	
	void	rebalanceTree(Node<K, V>* node) {
		if (maxHeight(node->left) - maxHeight(node->right) > 1) {
			if (maxHeight(node->left->left) > maxHeight(node->left->right)) {
				//std::cout << "right rotation\n";
				node = rightRotate(node);
			}
			else {
				//std::cout << "left-right rotation\n";
				node = leftRightRotate(node);
			}
		}
		else {
			if (maxHeight(node->right->right) > maxHeight(node->right->left)) {
				//std::cout << "left rotation\n";
				node = leftRotate(node);
			}
			else {
				//std::cout << "right-left rotation\n";
				node = rightLeftRotate(node);
			}
		}
		if (node->parent == NULL)
			this->root = node;
	};

	void	checkBalance(Node<K, V>* node) {
		if ((maxHeight(node->left) - maxHeight(node->right) > 1)
			|| (maxHeight(node->left) - maxHeight(node->right) < -1))
		{
			rebalanceTree(node);
		}
		if (node->parent == NULL)
			return;
		checkBalance(node->parent);
	};

	void	add(Node<K, V>* parent, Node<K, V>* newNode) {
		if (newNode->key > parent->key) {
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

	Node<K, V>* getSuccessor(Node<K, V>* node) {
		Node<K, V>* current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	};
	
	Node<K, V>* deleteNode(Node<K, V>* node, K key) {
		if (node == NULL)
			return NULL;
		else if (key < node->key)
			node->left = deleteNode(node->left, key);
		else if (key > node->key)
			node->right = deleteNode(node->right, key);
		else
		{
			std::cout << "Gotcha: " << node->value << std::endl;
			if (node->left == NULL && node->right == NULL) {
				delete node;
				node = NULL;
				std::cout << "No children\n";
			}
			else if (node->left == NULL) {
				std::cout << "One right child\n";
				Node<K, V>* temp = node;
				node = node->right;
				delete temp;
			}
			else if (node->right == NULL) {
				std::cout << "One left child\n";
				Node<K, V>* temp = node;
				node = node->left;
				delete temp;
			}
			else {
				std::cout << "two children\n";
				Node<K, V>* temp = getSuccessor(node->right);
				node->key = temp->key;
				node->value = temp->value;
				node->right = deleteNode(node->right, temp->key);
			}
		}
		return node;
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

	void	add(K objKey, V objVal) {
		Node<K, V>* node = new Node<K, V>(objKey, objVal);
		if (this->root == NULL) {
			this->root = node;
			this->CurrentSize++;
			return;
		}
		add(this->root, node);
	};

	bool	search(K key) {
		return (search(this->root, key));
	};

	void	deleteNode(K key) {
		deleteNode(this->root, key);
	};
};

int		main() {
	AVLTree<int, char>	tree;

	tree.add(40, 'd');
	tree.add(38, 'b');
	tree.add(52, 'a');
	tree.add(25, 'c');
	tree.add(61, 'e');
	tree.add(74, 'f');
	tree.add(35, 'h');
	tree.add(68, 'i');
	//tree.deleteNode(40);
	//std::cout << tree.search(53) << std::endl;
	tree.printTree();
	return (0);
}