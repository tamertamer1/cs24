#include "FibVec.h"
#include <stdexcept>
#include <iostream>
#include <cmath>
using std::cout;

int FibVec::nextFibonacci(int n) const{
    double a = n * (1 + sqrt(5)) / 2.0;
    return round(a);
}
int FibVec::previousFibonacci(int n) const{
    double a = 2*n/(1+sqrt(5));
    return round(a);
}
void FibVec::resize(int new_size){
    int *temp;
	temp = new int [new_size];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = point[i];
	}
	delete[] point;
	point = temp;
	size = new_size;
    sizecomp=new_size;
}
FibVec::FibVec(){
    point= new int[1];
    size=1;
    sizecomp=1;
    elm=0;
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
    if (index>(sizecomp-1)){
        throw std::out_of_range("Index out of range");
    }
    else{
        return point[index];
    }
    
}
int FibVec::pop(){
    if(size>0){
        int last=point[elm-1];
        int *temp = new int[size];
        for (int i=0;i<elm;i++){
            temp[i]=point[i];
        }
        delete [] point;
        point=temp;
        delete [] temp;
        if (elm<previousFibonacci(previousFibonacci(size))){
            resize(previousFibonacci(size));
        }
        return last;
    }

    else{
        throw std::underflow_error("Vector is empty");
    }
}
void FibVec::push(int value){
    if (size== elm){
		resize(nextFibonacci(size));
        }
	point[elm++] = value;
}
int FibVec::remove(size_t index){
    if (index>(sizecomp-1)){
        throw std::out_of_range("Index out of range");
    }
    else{
        int val=point[index];
        int *newArray = new int[size-1];
        std::copy(point, point+index, newArray);
        std::copy(point+index+1, point+size, newArray+index);
        delete[] point;
        point = newArray;
        --size;
        --elm;
        if (elm<previousFibonacci(previousFibonacci(size))){
            resize(previousFibonacci(size));
        }
        return val;
    }
}
