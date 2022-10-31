#include "Stack.h"

// Implement your Stack member functions here.



Stack::Stack() : high(0) {}
Stack::~Stack(){
	Node * temp = high;
	Node * next = temp;
	while (temp){
		next = temp->next;
		delete temp;
		temp= next;}
}


void Stack::push(AST* n){
	Node * temp = new Node();
	temp->data = n;
	temp->next = high;

	high = temp;}

void Stack::pop(){
	Node *temp;
		temp=high;
		high = high->next;
		delete temp;
	}

Node* Stack::top(){
	return high;}

bool Stack::check(){
	if(high){
		return 1;}
	else{return 0;}}
bool Stack::check2(){
	if(high){
		return 1;}
	else if(high->next){
		return 1;}
	else {return 0;}}

