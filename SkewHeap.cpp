#include "SkewHeap.h"
SkewHeap::~SkewHeap(){

}

const SkewHeap& SkewHeap::operator=(const SkewHeap& rhs){

}

pri_fn SkewHeap::getPriFn() const {

}

void SkewHeap::setPriFn(pri_fn pri){

}

bool SkewHeap::empty() const{
  if (m_heap)
    return false;
  else
    return true;

}

void SkewHeap::insert(string data){

}

void SkewHeap::insert(int data){

}

Node* SkewHeap::front() const{
  return m_heap;
}

void SkewHeap::removeTop(){

}

void SkewHeap::skewHeapMerge(SkewHeap& sh){

} 

void SkewHeap::inorder() const {
  inorderHelper(m_heap);
}

void SkewHeap::inorderHelper(Node *curr) const{
  if (curr == nullptr){
    return;
  }
  cout << "(" ;
  inorderHelper(curr->left) ;

  if(curr->tagged_union == ISINT)
    cout << curr->data_int << endl;
  else
    cout << curr->data_string << endl;

  inorderHelper(curr->right);
  cout << ")" ;

  return  ;
}

void SkewHeap::dump() const{

}

