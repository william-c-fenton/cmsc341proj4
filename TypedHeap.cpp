#include "TypedHeap.h"
void TypedHeap::insertToHeaps(vector<string> vec){
  for (int i = 0; i < vec.size(); i++){
    int possibleInt = atoi(vec.at(i).c_str());
    if (to_string(possibleInt).length() != vec.at(i).length()){
      stringHeap.insert(vec.at(i));
    }
    else if (to_string(possibleInt).length() == vec.at(i).length()){
      intHeap.insert(possibleInt);
    }
  }
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
  intHeap.setPriFn(pri);
  stringHeap.setPriFn(pri);
  totalHeap.setPriFn(pri);
}
