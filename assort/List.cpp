#include "List.h"
#include <iostream>
using namespace std;
std::string stri="hey";

List::List(){
    head=NULL;
}

List::List(const List& other){

}
List::List(List&& other){
    
}

List::~List(){
    Node *cur =head;
    Node *next = cur;
    while (cur){
        next= cur->next;
        delete cur;
        cur=next;
    }
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
   Node* current;
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
    if (reverse==false){
        Node * current;
        current = head;
        cout<<"[";
        while (current != NULL){
		cout << current->data;
        if(current->next!=NULL){
            cout<< ", ";
        }
		current = current->next;
        }
        cout<<"]"<<endl;
    }
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
