run : main_binary_tree
	./main_binary_tree

main_binary_tree : main_binary_tree.o
	g++ -std=c++14 main_binary_tree.o -o main_binary_tree

main_binary_tree.o : main_binary_tree.cc binary_tree.h binary_tree_ex.h
	g++ -std=c++14 -c main_binary_tree.cc binary_tree.h
