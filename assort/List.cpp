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
    delete curr;

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
    size_t ogcount= count();
    Node *temp = head;
    Node *prev = head;
    while(temp!=NULL) {
        if(temp->data == value){
        if(temp == head) {
            head = temp->next;
            delete temp;
            temp = head;
        } else {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
      } else {
         prev = temp;
         temp = temp->next;
      }
   }
   return ogcount-count();
} 




std::string List::remove(size_t index){
    if (index>=count()){
        throw std::out_of_range("Index out of range");
    }
    else{
        size_t l=0;
        Node *cur=head;
        if (index==0){
            std::string c=cur->data;
            head=cur->next;
            delete cur;
            return c;
        }

        if (index==count()-1){
            Node* second_last = head;
            while (second_last->next->next != NULL){
            second_last = second_last->next;
            }
            // Delete last node
            std::string c= second_last->next->data;
            delete (second_last->next);
            // Change next of second last
            second_last->next = NULL;
            delete second_last;
            return c;

        }

        while (l+1!=index){
            cur=cur->next;
            l++;
        }
        if(!cur->next->next){
            std::string c=cur->next->data;
            cur->next=NULL;
            delete cur;
            return c;
        }
        std::string c =cur->next->data;
        cur->next=cur->next->next;
        delete cur;
        return c;
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
