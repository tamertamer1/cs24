#ifndef NODES_H
#define NODES_H

#include "AST.h"






struct number : public AST{
	std::string prefix()  const;
  	std::string postfix() const;
  	double value()   const;  
	double data;
	~number();
	number * right, *left;
	number(double v) : data(v), right(0), left(0) { }};
	

	
struct add : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;
	~add();
	AST* right, *left;
	add(char v) : data(v) {}};


struct sub : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;
	~sub();
	AST* right, *left;
	sub(char v) : data(v) { }};

struct neg : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;

	~neg();
	AST* right, *left;
	neg(char v) : data(v) { }};

struct divi : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;
	~divi();
	AST* right, *left;
	divi(char v) : data(v) { }};

struct mod : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;
	~mod();
	AST* right, *left;
	mod(char v) : data(v) { }};

struct mult : public AST{
	std::string prefix() const;
	std::string postfix() const;
	double value() const;
	char data;
	~mult();
	AST* right, *left;
	mult(char v) : data(v) { }};

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.

#endif

