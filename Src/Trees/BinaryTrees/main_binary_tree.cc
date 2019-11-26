#include <iostream>
#include "binary_tree.h"
using namespace std;
int main() {
	BinaryTree<int> bts;
	cout << "bts insert value" << endl;
	bts.InsertValue(10);
	cout << "End of programm" << endl;
	return 0;
}