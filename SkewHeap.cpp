#include "SkewHeap.h"
SkewHeap::SkewHeap(pri_fn pri){
  m_heap = nullptr;
  priority = pri;
}

const SkewHeap& SkewHeap::operator= (const SkewHeap& rhs){
  makeEmpty(m_heap);
  makeCopy(m_heap, rhs.front());
  return *this;
}

SkewHeap::SkewHeap(const SkewHeap& rhs){
  m_heap = nullptr;
  priority = rhs.priority;
  makeCopy(m_heap, rhs.m_heap);
}

void SkewHeap::makeCopy(Node *&curr, const Node *srcCurr){
  if (srcCurr != nullptr){
    Node *newNode;

    if (srcCurr->tagged_union == ISINT){
      int data = srcCurr->data_int;
      newNode = new Node(data);

      curr = newNode;

      makeCopy(curr->left, srcCurr->left);
      makeCopy(curr->right, srcCurr->right);
    }
    else{
      string data = srcCurr->data_string;
      newNode = new Node(data);

      curr = newNode;

      makeCopy(curr->left, srcCurr->left);
      makeCopy(curr->right, srcCurr->right);
    }
    
  }
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

pri_fn SkewHeap::getPriFn() const {
  return priority;
}

void SkewHeap::setPriFn(pri_fn pri){
  priority = pri;
  SkewHeap s2(*this);
  makeEmpty(m_heap);
  
  while (!s2.empty()){
    if (s2.front()->tagged_union == ISINT)
      insert(s2.front()->data_int);
    else
      insert(s2.front()->data_string);
    
    s2.removeTop();
  }
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
  if (sh.getPriFn() != getPriFn())
    throw std::domain_error("Attempt to merge with diff priority funcs");

  m_heap = mergeHelper(m_heap, sh.m_heap);
  sh.m_heap = nullptr;
} 

Node* SkewHeap::mergeHelper(Node *&curr, Node *&srcCurr){
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
  dumpOutput();
}

void SkewHeap::dumpOutput() const{
  SkewHeap copy(*this);
  while(!copy.empty()){
    string val;
    if (copy.front()->tagged_union == ISINT)
      val = to_string(copy.front()->data_int);
    else
      val = copy.front()->data_string;
    
    cout << "Data is:\t" << val << "\t\tPriority is:\t" << priority(copy.front()) << endl;

    copy.removeTop();
  }


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