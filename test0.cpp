#include <iostream>
#include "SkewHeap.h"

using namespace std;
int PriorityCalc1(Node *);

int main(){
  SkewHeap s(PriorityCalc1);
  cout << "INSERTING 10 - 1" << endl;
  for (int i = 10; i > 0; --i){
    s.insert(i);
    s.inorder(); cout << endl;
  }
  cout << "INSERTING STRING 'haha' " << endl;
  s.insert("haha");
  s.inorder(); 
  s.dump();
  return 0;
}

int PriorityCalc1(Node *node){
  int sum = 0;
  if(node->tagged_union == ISINT){
    return node->data_int;
  }
  else{
    int size = node->data_string.size();
    for(int i = 0; i < size; i++){
      sum = sum + node->data_string[i];
    }
  }
  return sum;
}
