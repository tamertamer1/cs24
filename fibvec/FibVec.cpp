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
    elmcomp=0;
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
    if(index>elmcomp-1){
        throw std::out_of_range("Index out of range");
    }
    else{
        if (size==elm){
            resize(nextFibonacci(elm));
        }
        int *temp = new int[size];
        for (size_t i=0;i<index;i++){
            temp[i]=point[i];
        }
        temp[index]=value;
        for(int i=index+1;i<elm;i++){
            temp[i+1]=point[i];
        }
        delete[] point;
        point=temp;
        elm++;
        elmcomp++;
    }
}
int FibVec::lookup(size_t index) const{
    if (index>(elmcomp-1)){
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
        elm=elm-1;
        elmcomp=elmcomp-1;
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
	point[elm] = value;
    elm++;
    elmcomp++;
}
int FibVec::remove(size_t index){
    if (index>(elmcomp-1)){
        throw std::out_of_range("Index out of range");
    }
    else{
        int val=point[index];
        int *temp = new int[size];
        for (size_t i=0;i<index;i++){
            temp[i]=point[i];
        }
        for(int i=index+1;i<elm;i++){
            temp[i+1]=point[i];
        }
        delete[] point;
        point=temp;
        elm=elm-1;
        elmcomp=elmcomp-1;
        if (elm<previousFibonacci(previousFibonacci(size))){
            resize(previousFibonacci(size));
        }
        return val;
    }
}
