#ifndef STACK_H
#define STACK_H
#include "AST.h"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.


struct Node {
	AST* data;
	Node *next;
Node() : data(0), next (0) {}
};

AST * parse(std::string expession);

class Stack {
	Node *high;
	public:
	Stack();
	~Stack();
	void push(AST *n);
	void pop();
	Node* top();
	bool check();
	bool check2();
};




#endif

