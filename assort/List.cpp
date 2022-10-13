#include "List.h"
#include <iostream>

std::string stri="hey";

List::List(){
    struct Node* head=NULL;
}

List::List(const List& other){

}
List::List(List&& other){
    
}

List::~List(){

}

size_t List::count() const{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void List::insert(const std::string& value){

}

void List::print(bool reverse) const{

}

size_t List::remove(const std::string& value){
    return 1;

}

std::string List::remove(size_t index){
    return "hey";

}

const std::string& List::lookup(size_t index) const{
    
    return stri;

}
