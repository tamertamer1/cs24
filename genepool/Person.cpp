#include "Person.h"

// Person Member Functions


const std::string& Person::name() const{
    return this->data;
};
Gender Person::gender() const{
    return this->gend;
};
Person* Person::mother(){
    return this->mom;
};
Person* Person::father(){
    return this->dad;
};
std::set<Person*> Person::ancestors(PMod pmod){
    std::set<Person*> myset;
    return myset;
};
std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::children(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::daughters(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::descendants(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandchildren(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::granddaughters(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandfathers(PMod pmod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::grandsons(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::parents(PMod pmod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::sons(){
    std::set<Person*> myset;
    return myset;

};
std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> myset;
    return myset;

};

