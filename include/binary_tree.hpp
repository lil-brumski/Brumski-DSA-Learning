#include <memory>
#include <iostream>

/**
* This is a template class that represents a Binary Search Tree. It can take any basic C++ data type.
*/
template<class T>
class BSTree {
private:
	/**
	* This is a template class that represents a node/element in a Binary Search Tree. It can take any basic C++ data type.
	*/
	template<class N>
	class BSTNode {
	public:
		N data; /**< Holds the data of a single node/element*/
		std::unique_ptr<BSTNode<N>> left; /**< Pointer to left child*/
		std::unique_ptr<BSTNode<N>> right; /**< Pointer to right child*/
	};
public:
	std::unique_ptr<BSTNode<T>> root;

	/**
	* Inserts a value into the binary search tree
	* @param value - The value you want inside the BST
	*/
	virtual void insert(const T& value) {
		std::unique_ptr<BSTNode<T>> node = std::make_unique<BSTNode<T>>();
		node->data = value;

		root = insertHelper(root, node);
	}

    virtual void display(const bool& ascOrder = true) {
        displayHelper(root, ascOrder);
	}

	virtual bool search(){
		return true;
	}

	virtual void remove() {

	}

private:
	/**
	* Helper to BSTree<T>::insert()
	* @param value - the root node
	* @param value - a new node
	*/
	virtual std::unique_ptr<BSTNode<T>> insertHelper(std::unique_ptr<BSTNode<T>>& root, std::unique_ptr<BSTNode<T>>& node) {
		T data = node->data;

		if (root == nullptr) {
			root = std::move(node);
			return std::move(root);
		}
		else if (data < root->data) {
			root->left = insertHelper(root->left, node);
		}
		else {
            root->right = insertHelper(root->right, node);
		}
		
		return std::move(root);
	}

    static void displayHelper(std::unique_ptr<BSTNode<T>>& root, const bool& ascendingOrder = true) {
        if(ascendingOrder) {
            if (root) {
                displayHelper(root->left);
                std::cout << root->data << std::endl;
                displayHelper(root->right);
            }
        }
        else{
            if (root) {
                displayHelper(root->right, ascendingOrder);
                std::cout << root->data << std::endl;
                displayHelper(root->left, ascendingOrder);
            }
        }
	}

	virtual bool searchHelper() {
		return true;
	}

	virtual void removeHelper() {

	}

	T successor(){

	}

	T predecessor(){

	}
};

void UsingBST();
