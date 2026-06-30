#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        
        Node(int val){
            data = val;
            next = prev = NULL; 
        }
};
class DoublyList{
    Node* head;
    Node* tail;

    public:
        DoublyList(){
            head = tail = NULL;
        }

        void push_front(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
        }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;  
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
        }
    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;  
        }
    }
    void pop_front(){
        if(head==NULL){
            cout<<"dll is alreadsy empty";
            return;
        }
        Node* temp = head;
        head = head->next;
         if(head!=NULL){ //this condition is there since if dll had only one element then since head is already incemented to next
                         // then if dll had only one element head already points to NULL so NULL prev will not exist and will give error   
            head->prev = NULL;
         }
         temp->next = NULL;
         delete temp;
    }
    void pop_back(){
        if(head==NULL){
        cout<<"dll is empty";
        return;
        }
        Node* temp =tail;
        tail = tail->prev;
        
         if(tail != NULL){
            tail->next = NULL;
         }
         temp->prev = NULL;
         delete temp;
    }

    void print(){
        Node* temp = head;
        
        while(temp!=NULL){
            cout << temp->data << "<=>";
            temp =temp->next;
        }
         cout << "NULL\n";

    }
};
int main(){
DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    // dll.push_back(4);
    // dll.print();
    // dll.pop_front();
    dll.pop_back();
    dll.print();

}

