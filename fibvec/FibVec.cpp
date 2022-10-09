#include "FibVec.h"
#include <stdexcept>
#include <iostream>

using std::cout;

FibVec::FibVec(){
    point= new int[1];
}
FibVec::~FibVec(){
    delete [] point;
}
