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
   Node *new_node = new Node();
   new_node->data = value;
   new_node->next = NULL;

   if (head == NULL || (head)->data >= new_node->data) {
        new_node->next = head;
        head = new_node;
    }
    else {
        /* Locate the node before the
 point of insertion */
        current = head;
        while (current->next != NULL&& current->next->data< new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
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
