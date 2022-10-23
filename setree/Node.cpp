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

Node* Insertrec(Node*root, const std::string& value){
    if (!root) {
        // Insert the first node, if root is NULL.
        return new Node(value);
    }
 
    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insertrec(root->right, value);
    }
    else if (value < root->data){
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.
 
        // Process left nodes.
        root->left = Insertrec(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
};
