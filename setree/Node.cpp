#include "Node.h"

bool recurCont(Node* top,const std::string& value){
    if (top == NULL) return false;
  else {
    if (value == top->data)
      return true;
    else if (value < top->data)
      return recurCont(top->left, value);      //you forgot to return the value
    else if (value > top->data)
      return recurCont(top->right, value);
  }
};

void del(Node *n){
    if (!n) {return;}
    del(n->left);
    del(n->right);
    delete n;
};
