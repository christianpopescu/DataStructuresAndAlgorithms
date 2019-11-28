/*
 Name : Binary Tree Extended
 Node with left, right, parent

*/

#include <iostream>
#include <functional>

template<typename T>
class TreeNodeEx {
	public:
	TreeNode() = default;
	explicit TreeNode(T value) 
	: value(value),
      parent {nullptr},
	  left {nullptr},
	  right {nullptr} {
	}
	TreeNode* parent
	TreeNode* left;
	TreeNode* right;
	
	T value;                          
	void AcceptFunction(std::function<void(TreeNode*)>);
};
struct Position {
	Positon(TreeNode<T>* pr, TreeNode<T>* pos) 
	: parent {pr},
	position{ps} {}
	TreeNode<T>* parent;
	TreeNode<T>* position;
}
template<typename T>
class BinaryTreeEx {
	public:
	BinaryTree() :root(nullptr) {}
	void InsertValue(T value) {
		TreeNode<T>* node = new TreeNode<T>(value);
		if (root == null) {
			root = node;
		} else {
			Position p (root, nullptr);
			InsertValue(root, value);
		}
	}
	void VisitTree(){
	
	}
	void VisitTree (std::function<void(TreeNode<T>*)> func) {
	VisitNode(root, func);
	}
	
	private:
	TreeNode<T>* root;
	
	void InsertValue(TreeNode<T>*& node, T value) {
		if (node == nullptr) {
			node = 
			
		if (node->value > value) {
			if (node->left == nullptr) {
				node->left = new TreeNode<T>(value);
				node->left->parent = node;
			} else {
			InsertValue(node->left, value);
			}
		} else if (node->right == nullptr) {
				node->right = new TreeNode<T>(value);
				node->right->parent = node;
			} else {
			InsertValue(node->right, value);
			}
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