#include "TypedHeap.h"
void TypedHeap::insertToHeaps(vector<string> vec){

}

void TypedHeap::combineHeaps(){
  cout << "Merging Heaps: " << endl;

  totalHeap.skewHeapMerge(stringHeap);
  totalHeap.skewHeapMerge(intHeap);
}

void TypedHeap::printHeaps() const{
  cout << "Int Heap: " << endl;
  intHeap.dump();

  cout << "String Heap: " << endl;
  stringHeap.dump();

  cout << "Total Heap: " << endl;
  totalHeap.dump();
}

void TypedHeap::changePriority(pri_fn pri){

}
