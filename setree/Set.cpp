#include "Set.h"
#include <iostream>
std::string striii="hello";
Set::Set(){
    mRoot=nullptr;
};

Set::Set(const Set& other){

};

Set::Set(Set&& other){

};

Set::~Set(){
    del(mRoot);
};

size_t Set::clear(){
    
};
bool Set::contains(const std::string& value) const{
    return recurCont(mRoot,value);
};
size_t Set::count() const{
    if (!mRoot){
        size_t k=0;
        return k;
    }
    return mRoot ->countn;
};

size_t Set::insert(const std::string& value){
    if (!mRoot){
        mRoot=new Node(value);
        mRoot->countn=mRoot->countn+1;
        return 1;
    }
    if (contains(value)) {return 0;}
    return Insertrec(mRoot,value);
};

const std::string& Set::lookup(size_t n) const{
    return lookupRec(mRoot,n,mRoot);
};

void Set::print() const{
    if (!mRoot){
        std::cout<<"-";
    }
    else{
        printRec(mRoot);
    }
    std::cout<<std::endl;
};

size_t Set::remove(const std::string& value){
    return 0;
};



