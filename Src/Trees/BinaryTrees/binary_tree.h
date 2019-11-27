#include <iostream>
template<typename T>
class TreeNode {
	public:
	TreeNode() = default;
	explicit TreeNode(T value) : value(value) {
		std::cout << "I am here" << std::endl;
	}
	TreeNode* left;
	TreeNode* right;
	T value;
};

template<typename T>
class BinaryTree {
	public:
	BinaryTree() :root(nullptr) {}
	void InsertValue(T value) {
			std::cout << "I am here" << std::endl;
		InsertValue(root, value);
	}
	void VisitTree(){
		
	}	
	private:
	TreeNode<T>* root;
	
	void InsertValue(TreeNode<T>* node, T value) {
		std::cout << "insert value " << node <<std::endl;
		if (node == nullptr) {
			std::cout << "nullptr" << std::endl;
			node = new TreeNode<T>(value);
			std::cout << "nullptr end" << std::endl;
		} else if (node->value > value) {
			std::cout << "left" << std::endl;
			InsertValue(node->left, value);
		} else {
			std::cout << "right" << std::endl;
			InsertValue (node->right, value);
		}
	}
	
	void VisitNode(TreeNode<T>* node) {
		if (node == nullptr) return;
		VisitNode(node->left);
		VisitNode(node->right);
	}
	
};