#include "List.h"
#include <iostream>
using namespace std;


List::List(){
    head=NULL;
}

List::List(const List& other){
    
}
List::List(List&& other){
    
}
void printReverseRecursive (Node *n,Node *h){
    if(n) {
            printReverseRecursive(n->next);
            cout << n->data;
            if(n->data != h->data){
            cout<< ", ";
            }
        }
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
    else{
        cout<<"[";
        printReverseRecursive(head,head);
        cout<<"]";
    }
}

size_t List::remove(const std::string& value){
    Node* temp = head;
    Node* prev = NULL;
    size_t counter =0;
    int totva=count();
    for (int i=0;i<totva;i++){
        if (temp != NULL && temp->data == value){
        head = temp->next;
        counter++;
        }
        while (temp != NULL && temp->data != value){
            prev = temp;
            temp = temp->next; 
            }
        if (temp==NULL){
            return counter;
        }
        counter++;
        prev->next = temp->next;
    }
    // Free memory
    delete temp;
    return counter;
}



std::string List::remove(size_t index){
    return "hey";

}

const std::string& List::lookup(size_t index) const{
    Node* current = head;
    size_t count = 0;
    while (current != NULL) {
        if (count == index){
            return (current->data);
        }
        count++;
        current = current->next;
    }
    throw std::out_of_range("Index out of range");

}
