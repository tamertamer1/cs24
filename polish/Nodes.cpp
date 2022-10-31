#include "Nodes.h"
#include <math.h>
#include <sstream>
// Implement your AST subclasses' member functions here.

std::string number::prefix() const{
	std::ostringstream stream;
	stream << this->data;
	return stream.str();}
std::string number::postfix() const{
	std::ostringstream stream;
	stream << this->data;
	return stream.str();}
double number::value()const{
	return this->data;}

number::~number(){
		}



add::~add(){
	delete this->left;
	delete this->right;
	}
sub::~sub(){
	delete this->left;
	delete this->right;
}
mult::~mult(){
	delete this->left;
	delete this->right;
	}
mod::~mod(){
		delete this->left;
		delete this->right;
		
	}
divi::~divi(){
	delete this->left;
	delete this->right;
	}
	neg::~neg(){
		delete this->left;
		delete this->right;
	}


std::string neg::prefix() const{
	return "~ " + left->prefix();}
std::string neg::postfix() const{
	return left->postfix() + " ~";}
double neg::value() const{
	return  -left->value();}


std::string add::prefix() const{
	return "+ " + left->prefix() + " " + right->prefix();}
std::string add::postfix() const{
	return left->postfix() + " " + right->postfix() + " +";}
double add::value() const{
	double x = this->left->value() + this->right->value();
	return x;}

std::string mod::prefix() const{
	return "% " + left->prefix() + " " + right->prefix(); }
std::string mod::postfix() const{
	return left->postfix() + " " + right->postfix() + " %";}
double mod::value() const{
	if(this->right->value() == 0){
		throw std::runtime_error("Division by zero.");}
	double x = fmod(this->left->value(), this->right->value());
	return x;}


std::string sub::prefix() const{
	return "- " + left->prefix() + " " + right->prefix(); }
std::string sub::postfix() const{
	return left->postfix() + " " + right->postfix() + " -";}
double sub::value() const{
	double x = this->left->value() - this->right->value();
	return x;}



std::string divi::prefix() const{
	return "/ " + left->prefix() + " " + right->prefix(); }
std::string divi::postfix() const{
	return left->postfix() + " " + right->postfix() + " /";}
double divi::value() const{
	if(this->right->value() == 0){
		throw std::runtime_error("Division by zero.");}
	double x = this->left->value()  / this->right->value();
	return x;}



std::string mult::prefix() const{
	return "* " + left->prefix() + " " + right->prefix(); }
std::string mult::postfix() const{
	return left->postfix() + " " + right->postfix() + " *";}
double mult::value() const{
	double x = this->left->value() * this->right->value();
	return x;}


// To format a double for output:
//   std::ostringstream stream;
//   stream << value;
//   return stream.str();

