#include "AST.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include <sstream>
#include "Nodes.h"

AST* AST::parse(const std::string& expression) {
	Stack mystack;
	std::string token;
	std::string c = expression;
	std::istringstream my_stream(c);
	while(my_stream >> token){
		Node *n = mystack.top();
		if(token[1]){
			int c=0;
		for(size_t i = 1; i<token.length(); i++){
			if(!(isdigit(token[i]))){
				if((token[i]!='.') || ((token[i]== '.') && (c==1))){
					while(mystack.top()){
						delete mystack.top()->data;
						mystack.pop();}
				throw std::runtime_error("Invalid token: " +token);}				
				if(token[i]=='.'){
					c = 1;}
					}}}
		if(token[0] == '-' && isdigit(token[1])){
				token.erase(0,1);
		double f = std::stod(token);
		AST* ast = new number(-f);
		mystack.push(ast);
		}
		else if(token[0] == '+' && isdigit(token[1])){
				token.erase(0,1);
				double f = std::stod(token);
				AST* ast = new number(f);
				mystack.push(ast);}
		else if(isdigit(token[0])){
		double f = std::stod(token);
		AST* ast = new number(f);
		mystack.push(ast);
			}    
		else if(token[0] == '~'){
			if(!(mystack.top())){
			throw std::runtime_error("Not enough operands.");}
			neg* ast = new neg(token[0]);
			ast->left = n->data;
			ast->right = nullptr;
			mystack.pop();
			mystack.push(ast);}
		else if(token[0] == '+'||'-'||'%'||'/'||'*') {
			Node* n = mystack.top();
			if(n){
				if(!n->next){
					delete n->data;
					mystack.pop();
				throw std::runtime_error("Not enough operands.");}}
			if(!n){
				throw std::runtime_error("Not enough operands.");}
			if(token[0] == '+'){
				add* ast = new add(token[0]);
				ast->left = n->next->data;
				ast->right = n->data;
				mystack.pop();
				mystack.pop();
				mystack.push(ast);
				}
			else if(token[0] == '-'){
				sub* ast = new sub(token[0]);
				ast->right = n->data;
				ast->left = n->next->data;
				mystack.pop();
				mystack.pop();
				mystack.push(ast);}
			else if(token[0] == '%'){
				mod* ast = new mod(token[0]);
				ast->right = n->data;
				ast->left = n->next->data;
				mystack.pop();
				mystack.pop();
				mystack.push(ast);}
			else if (token[0] == '/'){
				divi* ast = new divi(token[0]);
				ast->right = n->data;
				ast->left = n->next->data;
				mystack.pop();
				mystack.pop();
				mystack.push(ast);}
			else if (token[0] == '*'){
				mult* ast = new mult(token[0]);
				ast->right = n->data;
				ast->left = n->next->data;
				mystack.pop();
				mystack.pop();
				mystack.push(ast);}
		else{   
			while(mystack.top()){
				delete mystack.top()->data;
				mystack.pop();}
		throw std::runtime_error("Invalid token: " + token);
		}
			
		}}
		if(!mystack.top()){
			throw std::runtime_error("No input.");}

		if(mystack.top() -> next){
			while(mystack.top()){
				delete mystack.top()->data;
				mystack.pop();}
			throw std::runtime_error("Too many operands.");}
			
		

		AST * l = mystack.top()->data;
    return l;

}

