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

Node* copyRec(Node *in){
    if(!in){
        return nullptr;
    }
    Node *sec= new Node(in->data);
    sec->countn=in->countn;
    sec->left=copyRec(in->left);
    sec->right=copyRec(in->right);
    return sec;
}

Node* delete_node(Node *root, std::string data)
{
  if(root == nullptr) return root;
  else if(data < root->data) root->left  = delete_node(root->left, data);
  else if(data > root->data) root->right = delete_node(root->right, data);

  else
  {
    if(root->left == nullptr && root->right == nullptr) // Case 1
    {
      free(root);
      root = nullptr;
    }
    else if(root->left == nullptr)       // Case 2
    {
       Node* temp = root;
       root= root->right;
       delete(temp);
    }
    else if(root->right == nullptr)      // Case 2
    {
       Node* temp = root;
       root = root->left;
       delete(temp);
    }
    else                                 // Case 3
    {
       Node* temp = root->right;

       while(temp->left != nullptr) temp = temp->left;

       root->data = temp->data;
       root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

