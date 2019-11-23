#include <iostream>
#include <vector>
#include <memory>
using namespace std;
vector<int>*  merge2Ways(vector<int>* lst1, vector<int>* lst2){
  int n1((*lst1).size());
  int n2((*lst2).size());

  vector<int>* result = new vector<int>();

  int i1(0);
  int i2(0);

  while (i1 < n1 && i2 < n2) {
    if ((*lst1)[i1] == (*lst2)[i2] ) {
      result->push_back((*lst1)[i1]);
			 ++i1;
			 ++i2;
    } else if ((*lst1)[i1] < (*lst2)[i2] ) {
      result->push_back((*lst1)[i1]);
			 ++i1;
      } else {
      result->push_back((*lst2)[i2]);
			 ++i2;
	}
	
    }
    if (i1 < n1) {
      while (i1 < n1) {
	result->push_back((*lst1)[i1]);
		++i1;
		}
	} else {
      while (i2 < n2) {
	result->push_back((*lst2)[i2]);
			 ++i2;
      }
    }
    delete(lst1);
    delete(lst2);
  return result;
  
}

class SetNode {
public:
	vector<int>* pSet;
	int nbElem;	
};

vector<SetNode> DisjointSet(10);

void MakeDisjointSet(vector<SetNode>& ds) {
	for (int i=0; i < ds.size(); ++i){
		ds[i].pSet = new vector<int>(1,i);
		ds[i].nbElem = 1;
	} 
}

void Union(int set1, int set2) {
	if (DisjointSet[set1].pSet == DisjointSet[set2].pSet ) return; // nothing to do
	cout << DisjointSet[set1].nbElem << "  <   " << DisjointSet[set2].nbElem << endl;
	if (DisjointSet[set1].nbElem > DisjointSet[set2].nbElem ){
	  DisjointSet[set1].pSet = merge2Ways(DisjointSet[set1].pSet, DisjointSet[set2].pSet);
	  cout << set1 <<  "Nb elem = " << (DisjointSet[set1].nbElem =DisjointSet[set1].pSet->size()) << endl;
		 DisjointSet[set2].pSet =  DisjointSet[set1].pSet;
	 cout << set2 <<  "Nb elem = " << (DisjointSet[set2].nbElem =DisjointSet[set2].pSet->size()) << endl;
	} else {

    	DisjointSet[set2].pSet = merge2Ways(DisjointSet[set1].pSet, DisjointSet[set2].pSet);
	cout <<  set2 << "Nb elem = " <<	(DisjointSet[set2].nbElem =DisjointSet[set2].pSet->size()) << endl;
		DisjointSet[set1].pSet =  DisjointSet[set2].pSet;
		DisjointSet[set1].nbElem =DisjointSet[set1].pSet->size();
	}
}

int Find(int i) {
  return (*(DisjointSet[i].pSet))[0]; // return first element of set
}

int SizeSet(int i) {
  return DisjointSet[i].nbElem; // return first element of set
}



int main(){ 
  
  MakeDisjointSet(DisjointSet);
  for (int i=1; i<10; ++i) {
    cout << SizeSet(i) << "set id =" << Find(i) <<  endl;
  }
  Union(1,2);
  Union(1,3);
  cout << SizeSet(1) << endl;
  cout << SizeSet(2) << endl;
  cout << SizeSet(3) << endl;
  cout << "------------------------" << endl;
  cout << Find(2) << endl;
  cout << Find(3) << endl;
  cout << Find(4) << endl;
  cout << "End of program" << endl;
}
