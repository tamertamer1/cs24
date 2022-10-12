#include "List.h"
#include <iostream>>

List::List(){

}

List::List(const List& other){

}
List::List(List&& other){

}

List::~List(){

}

size_t List::count() const{

    return 1;
}

void List::insert(const std::string& value){

}

void List::print(bool reverse = false) const{

}

size_t List::remove(const std::string& value){
    return 1;

}

std::string List::remove(size_t index){
    return "hey";

}

const std::string& List::lookup(size_t index) const{
    return "hey";

}
