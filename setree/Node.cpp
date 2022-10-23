#include "Node.h"

bool recurCont(Node* top,const std::string& value){
    if (!top) return false;
    if (value == top->data) return true;
    if (value < top->data) return recurCont(top->left, value);
    return recurCont(top->right, value);
};

void del(Node *n){
    if (!n) {return;}
    del(n->left);
    del(n->right);
    delete n;
};

Node* Insertrec(Node*root, const std::string& value){
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(value);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (value < root->data) {
        root->left = Insertrec(root->left, value);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = Insertrec(root->right, value);
    }
 
    return root;

};
size_t recurCount(Node *root){
    if(!root)     
        return 0; 
    if(!root->left && !root->right) 
        return 1;         
    else
        return recurCount(root->left)+ 
            recurCount(root->right); 
};
