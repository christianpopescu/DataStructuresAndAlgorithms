run : BellmanFord	
	./BellmanFord

BellmanFord : BellmanFord.o
	g++ -std=c++17 BellmanFord.o InputReader.o -o BellmanFord

BellmanFord.o : BellmanFord.cc InputReader.h InputReader.cc
	g++ -std=c++17 -c BellmanFord.cc InputReader.cc
