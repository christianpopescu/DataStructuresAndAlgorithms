#include <iostream>
#include <functional>

template<typename T>
class TreeNode {
	public:
	TreeNode() = default;
	explicit TreeNode(T value) 
	: value(value),
	  left {nullptr},
	  right {nullptr} {
		std::cout << "I am here" << std::endl;
	}
	TreeNode* left;
	TreeNode* right;
	T value;                          
	void AcceptFunction(std::function<void(TreeNode*)>);
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
	void VisitTree (std::function<void(TreeNode<T>*)> func) {
		std::cout << "visit tree" << std::endl;
	VisitNode(root, func);
	}
	
	private:
	TreeNode<T>* root;
	
	void InsertValue(TreeNode<T>*& node, T value) {
		std::cout << "insert value " << node <<std::endl;
		if (node == nullptr) {
			node = new TreeNode<T>(value);
		} else if (node->value > value) {
			InsertValue(node->left, value);
		} else {
			InsertValue (node->right, value);
		}
	}
	
	
	void VisitNode(TreeNode<T>* node) {
		if (node == nullptr) return;
		VisitNode(node->left);
		VisitNode(node->right);
	}
	
	void VisitNode(TreeNode<T>* node, std::function<void(TreeNode<T>*)> func) {
		if (node == nullptr) return;
		func(node);
		VisitNode(node->left, func);
		VisitNode(node->right, func);
	}

	
};