#include "List.h"
#include <iostream>
using namespace std;


List::List(){
    head=NULL;
}

List::List(const List& other){
    if(!other.head) return;
    head = new Node();
    head->data=other.head->data;
    Node *currSource = other.head;
    Node *curr= head;
    while (currSource->next){
        curr->next=new Node();
        curr->next->data=currSource->next->data;
        currSource=currSource->next;
        curr=curr->next;
    }

}
List::List(List&& other){
    
}
void printReverseRecursive (Node *n,Node *h){
    if(n) {
            printReverseRecursive(n->next,h);
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
        cout<<"]"<<endl;
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
    size_t numvals=count();
    if (index < 1||head==NULL||index>=numvals){
       throw std::out_of_range("Index out of range"); 
    }
    else{
        std::string val = lookup(index);
        index=numvals-index;
        Node *temp;
        Node* first = head;
        Node* second = head;
        for (size_t i = 0; i < index; i++) {
            // If count of nodes in the given linked list is <= N
            if (second->next == NULL) {
                // If count = N i.e. delete the head node
                if (i == index - 1) {
                    temp = head;
                    head = head->next;
                    free(temp);
                    return val;
                }
            }
            second = second->next;
        }
 
        // Increment both the pointers by one until second
        // pointer reaches the end
        while (second->next != NULL) {
            first = first->next;
            second = second->next;
        // First must be pointing to the Nth node from the
        // end by now So, delete the node first is pointing to
        temp = first->next;
        first->next = first->next->next;
        free(temp);
        return val;
    }
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
