# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

#include "AVLTree.hpp"

int		main() {
	AVLTree<int, char>	tree;

	tree.insert(38, 'a');
	tree.insert(40, 'b');
	tree.insert(52, 'c');
	tree.insert(25, 'd');
	tree.insert(74, 'f');
	tree.insert(35, 'g');
	tree.insert(68, 'h');
	tree.insert(61, 'e');
	tree.insert(88, 'i');
	tree.insert(49, 'j');
	tree.insert(55, 'k');
	tree.insert(65, 'l');
	tree.insert(58, 'm');
	tree.insert(47, 'n');
	tree.insert(67, 'o');
	tree.insert(11, 'p');
	tree.insert(59, 'q');
	tree.deleteNode(88);
	tree.printTree();
}