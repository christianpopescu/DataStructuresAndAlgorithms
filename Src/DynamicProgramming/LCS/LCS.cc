#include <bits/stdc++.h>

int main() {
	using namespace std;
	string x, y;
	cin >> x >> y;
	int n (x.length());
	int m (y.length());
	vector<int> line(n+1,0);
	vector<vector<int>> lcs(m+1,line);
	// computation
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			if (x[i] == y[j]) {
				lcs[j+1][i+1] = lcs[j][i] + 1;
			} else {
				lcs[j+1][i+1] = max(lcs[j+1][i], lcs[j][i+1]);
			}		
		}
	cout << "Lcs result =  " << lcs[m][n] << endl;
	
	if (lcs[m][n] > 0) {
		// print result;
		pair<int,int> cr {m,n};
		deque<pair<int,int>> match;
		while (cr.first>0 && cr.second>0) {
			if (y[cr.first-1] == x[cr.second-1]) {
				match.push_front(cr);
				--cr.first;
				--cr.second;
			} else {
				if ( lcs[cr.first][cr.second] == lcs[cr.first][cr.second-1])
					--cr.second;
				else
					--cr.first;
			}
		}
		for (auto e : match) cout << e.second << " " << e.first << endl;
	}
}