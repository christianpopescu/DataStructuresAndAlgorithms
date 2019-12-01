/*
Bellman-Ford determins the shortest path from one given node to all the nodes of the graph
============
Assumption: The graph is stored as list of edges
----------


*/

#include <bits/stdc++.h>
#include "InputReader.h"


#define INF INT_MAX
std::vector<std::tuple<int,int,int>> edges;

int main() {
	using namespace std;
	
	InputReader ir;
	ir.SetInputStreamFile("input.txt");
	ir.ReadGraphAsEdges(edges);
	
	cout << edges.size();
	
}