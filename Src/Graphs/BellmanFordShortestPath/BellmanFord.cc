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
	int n{0};   // nodes number
	int s{0};   // starting node
	InputReader ir;
	ir.SetInputStreamFile("input.txt");
	cout << "Number of Nodes = " ;
	cin >> n;
	cout << endl;
	vector<int> distance(n+1,INF);
    cout << "Starting node = " ;
	cin >> s;
	cout << endl;
	ir.ReadGraphAsEdges(edges);
	distance[s] = 0;
	int a{0}, b{0}, w{0};
	for (int i=1; i < n; ++i) {
		for (auto e: edges) {
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a]!= INF ? distance[a] + w : INF);
		}
	}
		
	cout << edges.size();
	for (int i=1; i<=n; ++i) cout << i << " min distance = " << distance[i] << endl;
	
}