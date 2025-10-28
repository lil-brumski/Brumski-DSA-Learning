#include "binary_tree.hpp"

void UsingBST() {
	std::cout << "\nBINARY SEARCH TREE DATA STRUCTURE" << std::endl;
	BSTree<int> tree;

	tree.insert(7);
	tree.insert(4);
	tree.insert(6);
	tree.insert(12);
	tree.insert(5);

	tree.display();
}