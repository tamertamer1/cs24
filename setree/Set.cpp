#include "Set.h"
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
    return 0;
};
bool Set::contains(const std::string& value) const{
    return recurCont(mRoot,value);
};
size_t Set::count() const{
    return recurCount(mRoot);
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
    return striii;
};

void Set::print() const{
};

size_t Set::remove(const std::string& value){
    return 0;
};

