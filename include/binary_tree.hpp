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

    /**
    * Displays all the values in the binary search tree
    * @param ascendingOrder - boolean variable that will decide if the traversal will be in ascending or descending order
    */
    virtual void display(const bool& ascOrder = true) {
        displayHelper(root, ascOrder);
	}

    /**
    * Searches for an element in the binary search tree
    * @param data - the element that you want to search for
    */
    virtual bool search(const T& data){
        return searchHelper(root, data);
	}

	virtual void remove() {

	}

private:
	/**
	* Helper to BSTree<T>::insert()
    * @param root - the root node
    * @param node - a new node
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

    /**
    * Helper to BSTree<T>::display()
    * @param root - the root node
    * @param ascendingOrder - boolean variable that will decide if the traversal will be in ascending or descending order
    */
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

    /**
    * Helper to BSTree<T>::search()
    * @param root - the root node
    * @param data - the element that you want to search for
    */
    virtual bool searchHelper(std::unique_ptr<BSTNode<T>>& root, const T& data) {
        if(!root){
            return false;
        }
        else if(root->data == data){
            return true;
        }
        else if(root->data > data){
            return searchHelper(root->left, data);
        }
        else if(root->data < data){
            return searchHelper(root->right, data);
        }

        return false;
	}

	virtual void removeHelper() {

	}

	T successor(){

	}

	T predecessor(){

	}
};

void UsingBST();
