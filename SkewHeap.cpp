#include "SkewHeap.h"
SkewHeap::SkewHeap(pri_fn pri){
  m_heap = nullptr;
  priority = pri;
}

SkewHeap::~SkewHeap(){
  makeEmpty(m_heap);
}

void SkewHeap::makeEmpty(Node *&curr) {
  if(curr){
    makeEmpty(curr->left);
    makeEmpty(curr->right);
    delete curr;
    curr = nullptr;
  }
}

const SkewHeap& SkewHeap::operator=(const SkewHeap& rhs){

}

pri_fn SkewHeap::getPriFn() const {
  return priority;
}

void SkewHeap::setPriFn(pri_fn pri){
  priority = pri;
}

bool SkewHeap::empty() const{
  if (m_heap)
    return false;
  else
    return true;

}

void SkewHeap::insert(string data){
  Node* newNode = new Node(data);
  if (!m_heap){
    m_heap = newNode;
  }
  else{
    m_heap = mergeHelper(m_heap, newNode);
  }
}

void SkewHeap::insert(int data){
  Node* newNode = new Node(data);
  if (!m_heap){
    m_heap = newNode;
  }
  else{
    m_heap = mergeHelper(m_heap, newNode);
  }
}

Node* SkewHeap::front() const{
  return m_heap;
}

void SkewHeap::removeTop(){
  Node *oldLeft = m_heap->left;
  Node *oldRight = m_heap->right;
  m_heap->left = nullptr;
  m_heap->right = nullptr;

  delete m_heap;

  m_heap = mergeHelper(oldLeft, oldRight);

}

void SkewHeap::skewHeapMerge(SkewHeap& sh){
  m_heap = mergeHelper(m_heap, sh.m_heap);
} 

Node* SkewHeap::mergeHelper(Node *curr, Node *srcCurr){
  //if either is empty, return other
  //if curr is null, return sh
  //else return curr
  if (!curr){
    return srcCurr;
  }
  else if (!srcCurr){
    return curr;
  }

  if (priority(curr) < priority(srcCurr)){
    swap(curr, srcCurr);
  }

  swap(curr->left, curr->right);

  curr->left = mergeHelper(curr->left, srcCurr);
  
  return curr;
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
    cout << curr->data_int;
  else
    cout << curr->data_string;

  inorderHelper(curr->right);
  cout << ")" ;

  return  ;
}

void SkewHeap::dump() const{
  dumpOutput(m_heap);
}

void SkewHeap::dumpOutput(Node *curr) const{
  if(curr == nullptr)
    return ;

  string val;
  if (curr->tagged_union == ISINT)
    val = to_string(curr->data_int);
  else
    val = curr->data_string;
  
  cout << "Data is:\t" << val << "\t\tPriority is:\t" << priority(curr) << endl;
  cout << "left from " << priority(curr) << endl;
  dumpOutput(curr->left);
  cout << "right from " << priority(curr) << endl;
  dumpOutput(curr->right);
}

void SkewHeap::dumpHelper(Node *curr) const{
  if(curr == nullptr)
    return ;

  string val;
  if (curr->tagged_union == ISINT)
    val = to_string(curr->data_int);
  else
    val = curr->data_string;
  
  cout << "ADDRESS: " << curr << endl;
  cout << "VALUE: " << val << endl;
  cout << "PRIORITY: " << priority(curr) << endl;
  cout << "LEFT: " << curr->left << endl;
  cout << "RIGHT: " << curr->right << endl;
  cout << "------------------------" << endl;
  dumpHelper(curr->left);
  dumpHelper(curr->right);
}