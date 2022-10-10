#include "FibVec.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
using std::cout;

int FibVec::nextFibonacci(int n) const{
    double a = n * (1 + sqrt(5)) / 2.0;
    return round(a);
}

FibVec::FibVec(){
    point= new int[1];
}
FibVec::~FibVec(){
    delete [] point;
}
size_t FibVec::capacity() const{
    return size; 
}
size_t FibVec::count() const{
    return elm;
}
void FibVec::insert(int value, size_t index){
    
}
int FibVec::lookup(size_t index) const{
    return size;    
}
void FibVec::pop(){
    
}
void FibVec::push(int value){
    
}
void FibVec::remove(size_t index){
    
}
