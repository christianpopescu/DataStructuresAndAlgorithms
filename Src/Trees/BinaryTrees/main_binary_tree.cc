#include <iostream>
#include "binary_tree.h"
using namespace std;
int main() {
	BinaryTree<int> bts;
	cout << "bts insert value" << endl;
	bts.InsertValue(10);
	bts.InsertValue(1);
	bts.InsertValue(20);
	bts.VisitTree([](TreeNode<int>* node){cout << node->value <<endl;});
	cout << "End of programm" << endl;
	return 0;
}