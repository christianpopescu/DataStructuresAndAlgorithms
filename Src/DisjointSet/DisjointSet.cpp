#include <iostream>
#include <vector>
#include <memory>
using namespace std;


vector<vector<int>*> DisjointSet(10);

void MakeDisjointSet(vector<vector<int>*>& ds) {
	for (int i=0; i < ds.size(); ++i){
		ds[i] = new vector<int>(1,i);
	} 
}

void Union(int set1, int set2) {
  if (set1 == set2) return;
  int s,d;
  vector<int>* tmp;
  if (DisjointSet[set1]->size() > DisjointSet[set2]->size()) {
    d = set1;
    s = set2;
    tmp = DisjointSet[set2];
  } else {
    d = set2;
    s = set1;
    tmp = DisjointSet[set1];
  }
  for (auto e : (*tmp)) {
    DisjointSet[e] = DisjointSet[d];
    DisjointSet[e]->push_back(e);
  }

  delete tmp;

}

int SizeSet(int i) {
  return DisjointSet[i]->size(); 
}



int main(){ 
  
  MakeDisjointSet(DisjointSet);
  for (int i=1; i<10; ++i) {
    cout << SizeSet(i)  <<  endl;
  }
  cout << "-------------------" << endl;
  Union(1,2);
  Union(1,3);
  cout << SizeSet(1) << endl;
  cout << SizeSet(2) << endl;
  cout << SizeSet(3) << endl;
  Union(5,7);
  Union(7,8);
  
  cout << "-------------------" << endl;

  for (int i=1; i<10; ++i) {
    cout << SizeSet(i)  <<  endl;
  }

  
  cout << "End of program" << endl;
}
