#include "binary_tree.hpp"

void UsingBST() {
	std::cout << "\nBINARY SEARCH TREE DATA STRUCTURE" << std::endl;
	BSTree<int> tree;

	tree.insert(7);
	tree.insert(4);
	tree.insert(6);
	tree.insert(12);
	tree.insert(5);
	tree.insert(1);
	tree.insert(-2);
	tree.insert(50);

    std::cout << std::boolalpha << "Found: " << tree.search(-2) << std::endl;
    tree.display(false);
}
