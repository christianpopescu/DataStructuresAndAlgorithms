#include <iostream>
#include <vector>
#include <memory>
using namespace std;
vector<int> merge2Ways(const vector<int>& lst1, const vector<int> lst2){
  int n1(lst1.size());
  int n2(lst2.size());

  vector<int> result;

  int i1(0);
  int i2(0);

  while (i1 < n1 && i2 < n2) {
      if (lst1[i1] == lst2[i2] ) {
	result.push_back(lst1[i1]);
			 ++i1;
			 ++i2;
      } else if (lst1[i1] < lst2[i2] ) {
	result.push_back(lst1[i1]);
			 ++i1;
      } else {
	result.push_back(lst2[i2]);
			 ++i2;
	}
	
    }
    if (i1 < n1) {
      while (i1 < n1) {
	result.push_back(lst1[i1]);
		++i1;
		}
	} else {
      while (i2 < n2) {
	result.push_back(lst2[i2]);
			 ++i2;
      }
    }
  return move(result);
  
}

class SetNode {
public:
	shared_ptr<vector<int>> pSet;
	int nbElem;	
};

vector<SetNode> DisjointSet(10);

void MakeDisjointSet(vector<SetNode>& ds) {
	for (int i=0; i < ds.size(); ++i){
		ds[i].pSet = make_shared<vector<int>>(i,1);
		ds[i].nbElem = 1;
	} 
}

void Union(int set1, int set2) {
	if (DisjointSet[set1].pSet == DisjointSet[set2].pSet ) return; // nothing to do
	if (DisjointSet[set1].nbElem > DisjointSet[set2].nbElem ){
	  DisjointSet[set1].pSet = &merge2Ways(*(DisjointSet[set1].pSet), *(DisjointSet[set2].pSet));
		DisjointSet[set1].nbElem =DisjointSet[set1].pSet->size();
		 DisjointSet[set2].pSet =  DisjointSet[set1].pSet;
		DisjointSet[set2].nbElem =DisjointSet[set2].pSet->size();
	} else {

    	DisjointSet[set2].pSet = &merge2Ways(DisjointSet[set1].pSet, DisjointSet[set2].pSet);
		DisjointSet[set2].nbElem =DisjointSet[set2].pSet->size();
		DisjointSet[set1].pSet =  DisjointSet[set2].pSet;
		DisjointSet[set1].nbElem =DisjointSet[set1].pSet->size();
	}
}

int main(){ 
  
		
	vector<int> v1 = {2, 4, 7, 9};
  vector<int> v2 = {2, 3, 4, 9, 13, 15};

  for(auto i : merge2Ways(v1, v2)) cout << i << endl;
  cout << "End of program" << endl;
}
