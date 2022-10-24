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
Node* getMinimumKey(Node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
};

// Iterative function to search in the subtree rooted at `curr` and set its parent.
// Note that `curr` and `parent` is passed by reference to the function.
void searchKey(Node* &curr, std::string key, Node* &parent)
{
    // traverse the tree and search for the key
    while (curr && curr->data != key)
    {
        // update the parent to the current node
        parent = curr;
 
        // if the given key is less than the current node, go to the left subtree;
        // otherwise, go to the right subtree
        if (key < curr->data) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
};
 
// Function to delete a node from a BST
void deleteNode(Node*& root, std::string key)
{
    // pointer to store the parent of the current node
    Node* parent = nullptr;
 
    // start with the root node
    Node* curr = root;
 
    // search key in the BST and set its parent pointer
    searchKey(curr, key, parent);
 
    // return if the key is not found in the tree
    if (!curr) {
        return;
    }
 
    // Case 1: node to be deleted has no children, i.e., it is a leaf node
    if (!curr->left && !curr->right)
    {
        // if the node to be deleted is not a root node, then set its
        // parent left/right child to null
        if (curr != root)
        {
            if (parent->left == curr) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        // if the tree has only a root node, set it to null
        else {
            root = nullptr;
        }
 
        // deallocate the memory
        free(curr);        // or delete curr;
    }
 
    // Case 2: node to be deleted has two children
    else if (curr->left && curr->right)
    {
        // find its inorder successor node
        Node* successor = getMinimumKey(curr->right);
 
        // store successor value
        std::string val = successor->data;
 
        // recursively delete the successor. Note that the successor
        // will have at most one child (right child)
        deleteNode(root, successor->data);
 
        // copy value of the successor to the current node
        curr->data = val;
    }
 
    // Case 3: node to be deleted has only one child
    else {
        // choose a child node
        Node* child = (curr->left)? curr->left: curr->right;
 
        // if the node to be deleted is not a root node, set its parent
        // to its child
        if (curr != root)
        {
            if (curr == parent->left) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
        }
 
        // if the node to be deleted is a root node, then set the root to the child
        else {
            root = child;
        }
 
        // deallocate the memory
        free(curr);
    }
};
