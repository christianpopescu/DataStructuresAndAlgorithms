#include <iostream>
#include <vector>

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
int main(){ 
  vector<int> v1 = {2, 4, 7};
  vector<int> v2 = {2, 3, 4};
  
  cout << "End of program" << endl;
}
