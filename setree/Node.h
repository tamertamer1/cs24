#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.

struct Node{
std::string data;
size_t c;
Node *left,*right,*parent;
Node(std::string v): data(v),c(0), left(0), right(0), parent(0){}
};



void del(Node *n);
bool recurCont(Node* top,const std::string& value);
Node* Insertrec(Node*root, const std::string& value);
#endif
