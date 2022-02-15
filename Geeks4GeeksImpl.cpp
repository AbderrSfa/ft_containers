#include <iostream>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

// An AVL tree node
class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					  // added at leaf
	return(node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node* N)
{
	if (N == NULL)
		return 0;
	return height(N->left) -
		height(N->right);
}

Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
		height(node->right));

/* 3. Get the balance factor of this
	ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node* minValueNode(Node* node)
{
	Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
Node* deleteNode(Node* root, int key)
{

	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;

	// If the key to be deleted is smaller
	// than the root's key, then it lies
	// in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater
	// than the root's key, then it lies
	// in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then
	// This is the node to be deleted
	else
	{
		// node with only one child or no child
		if ((root->left == NULL) ||
			(root->right == NULL))
		{
			Node* temp = root->left ?
				root->left :
				root->right;

   // No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
				*root = *temp; // Copy the contents of
							   // the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			Node* temp = minValueNode(root->right);

			// Copy the inorder successor's
			// data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right,
				temp->key);
		}
	}

	// If the tree had only one node
	// then return
	if (root == NULL)
		return root;

		// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
		height(root->right));

// STEP 3: GET THE BALANCE FACTOR OF
// THIS NODE (to check whether this
// node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void	print2DUtil(Node* node, int space)
{
	if (node == NULL)
		return;
	space += 20;
	print2DUtil(node->right, space);
	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	std::cout << "{" << node->key << "} ";
	std::cout << GREEN;
	std::cout << " " << node->height << "\n";
	std::cout << RESET;
	print2DUtil(node->left, space);
}

void printTree(Node* node) {
	print2DUtil(node, 0);
}

// Driver Code
int main()
{
	Node* root = NULL;

	root = insert(root, 38);
	root = insert(root, 40);
	root = insert(root, 52);
	// root = insert(root, 25);
	// root = insert(root, 61);
	// root = insert(root, 74);
	// root = insert(root, 35);
	// root = insert(root, 68);
	// root = insert(root, 88);
	// root = insert(root, 49);
	// root = insert(root, 55);
	// root = insert(root, 65);
	// root = insert(root, 58);
	// root = insert(root, 47);
	// root = insert(root, 67);
	// root = insert(root, 11);
	// root = insert(root, 59);

	// root = deleteNode(root, 88);
	printTree(root);
	return 0;
}
