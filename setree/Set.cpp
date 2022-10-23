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
    return 0;
};

size_t Set::insert(const std::string& value){
    if (contains(value)){
        return 0;
    }
    Insertrec(mRoot,value);
    return 1;
};

const std::string& Set::lookup(size_t n) const{
    return striii;
};

void Set::print() const{
};

size_t remove(const std::string& value){
    return 0;
};


