/*
#include <iostream>
#include "SkewHeap.h"

using namespace std;
int PriorityCalc1(Node *);

int main(){
  SkewHeap s(PriorityCalc1);
  cout << "INSERTING 10 - 0" << endl;
  for (int i = 10; i >= 0; --i){
    s.insert(i);
    s.inorder(); cout << endl;
  }

  s.insert("Ha Ha I'm a string");
  s.dump();
  cout << "MAKING s2, copy of s" << endl;
  SkewHeap s2(s);
  s2.inorder(); cout << endl;

  cout << "removing top of s" << endl;
  s.removeTop();

  s.inorder(); cout << endl;
  s2.inorder(); cout << endl;


  cout << "DUMPING S" << endl;

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
*/

// CMSC 341 - Fall 2019 - Project 4
// Basic tests of SkewHeap class

#include <iostream>
#include "SkewHeap.h"

// Prototypes for sample priority functions
int PriorityCalc1(Node *);
int PriorityCalc2(Node *);

int main() {

  // Create a SkewHeap s1; insert some integers and a string; dump the
  // skew heap
  
  SkewHeap s1(PriorityCalc1);

  cout << "\nInserting 0..10 into skew heap:\n";
  
  for(int i = 0; i <= 10; i++){
    s1.insert(i);
    s1.inorder(); cout << endl;
  }
  s1.insert("Ha Ha I'm a String");
  s1.dump();
  s1.inorder(); cout << endl;

  // Test of removeTop(), copy constructor, and assignment operators
  
  SkewHeap s2(s1);

  // Following line would just call copy constructor, not assignment
  // operator
  //  SkewHeap s3 = s2; 

  s1.removeTop();
  
  cout << "\nRemove Test:\n";

  cout << "Dumping s1:\n";
  s1.dump();
  s1.inorder(); cout << endl;

  cout << "\nCopy Construtor Test:\n";

  cout << "Dumping s1:\n";
  s1.dump();
  s1.inorder(); cout << endl;

  cout << "Dumping s2:\n";
  s2.dump();
  s2.inorder(); cout << endl;

  cout << "\nAssignment Operator Test:\n";

  s2 = s1;   // A "real" assignment call
  
  cout << "Dumping s1:\n";
  s1.dump();
  s1.inorder(); cout << endl;

  cout << "Dumping s2:\n";
  s2.dump();
  s2.inorder(); cout << endl;
  
  cout << "\nAdditional Remove Test:\n";
  for ( int i = 0; i < 4; i++ ) {
    s1.removeTop();
  }
  cout << "Dumping s1:\n";
  s1.dump();
  s1.inorder(); cout << endl;

  // Test of merge function

  cout << "\nTest of merge function:\n";
  
  SkewHeap s4(PriorityCalc1);

  s4.insert("This is some data");
  s4.insert("This is More Data");

  cout << "Merging Existing Heaps...\n";

  s4.skewHeapMerge(s2);
  
  s4.dump();
  s4.inorder(); cout << endl;

  cout << "\nTesting Pri Fn Change:\n";
  s4.setPriFn(PriorityCalc2);
  s4.dump();
  s4.inorder(); cout << endl;
  cout << "\nDone!\n";
  
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

int PriorityCalc2(Node *node){
  int sum = 0;
  if(node->tagged_union == ISINT){
    return (-1 * (node->data_int));
  }
  else{
    int size = node->data_string.size();
    for(int i = 0; i < size; i++){
      sum = sum + node->data_string[i];
    }
  }
  return (-1 *sum);
}
