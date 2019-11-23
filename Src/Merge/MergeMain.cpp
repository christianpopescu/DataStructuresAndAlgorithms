#include <iostream>
#include "SimpleLinkedList"
int main(){
  using namespace std;
  SingleLinkedList<int> sll;
  cout << sll.empty() << endl;
   sll.AddFront(10);
    sll.AddFront(20);
  //  sll.AddFront(30);
  //  while ( !sll.empty()){
    sll.Front() ;
    //   sll.RemoveFront();
    // }
  cout << "End of program" << endl;
}
