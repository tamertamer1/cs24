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
    int count = 0; 
    Node* current = head; 
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void List::insert(const std::string& value){
    if (*head_ref == NULL|| (*head_ref)->data>= value->data) {
        value->next = *head_ref;
        *head_ref = value;
    }
    else {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->next != NULL&& current->next->data< value->data) {
            current = current->next;
        }
        value->next = current->next;
        current->next = value;
    }
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
