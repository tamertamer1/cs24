#include "Node.h"
#include <iostream>

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

size_t Insertrec(Node*root, const std::string& value){
    if (value>root->data && root->right){
        Insertrec(root->right,value);
    }
    else if (value > root -> data && !root->right){
        root->right=new Node(value);
        root->right->parent=root;
        root->countn=root->countn+1;
        return 1;
    }
    if (value<root->data&& root->left){
        Insertrec(root->left,value);
    }
    else if (value < root->data&& !root->left){
        root->left=new Node(value);
        root->left->parent=root;
        root->countn=root->countn+1;
        return 1;
    }
    root->countn=root->countn+1;
    return 1;

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

void printRec(Node* n){
    if(!n){
        std::cout<<"-";
    }
    else if (!n->left && !n->right){
        std::cout<<n->data;
    }
    else{
        std::cout<<"(";
        printRec(n->left);
        std::cout<<" "<<n->data<<" ";
        printRec(n->right);
        std::cout<<")";
    }
};

size_t numSmaller(Node *n, const std::string& value) {
    if(!n) return 0;
    // elements less than n->data make up the whole left subtree
    if (value == n->data) {
        return n->left ? n->left->countn : 0;
    }
    // even smaller? just recurse left
    else if (value < n->data) {
        return numSmaller(n->left, value);
    }
    // bigger? take the whole left subtree and part of the right one
    else {
        return (n->left ? n->left->countn : 0) + numSmaller(n->right, value);
    }
};
const std::string& lookupRec(Node* n, size_t ind, Node *root){
    if(!n){
    }
    else if (!n->left && !n->right){
        if (numSmaller(root,n->data)==ind){
            return n->data;
        }
    }
    else{
        printRec(n->left);
         if (numSmaller(root,n->data)==ind){
            return n->data;
        }
        printRec(n->right);
        
    }
    throw std::out_of_range("Index out of range");
};
