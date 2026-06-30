#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:
        Node* head;
        Node* tail;

        Queue(){
            head = tail = NULL;
        }
        void push(int data){
            Node* newNode = new Node(data);
            
            if(empty()){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        void pop(){
            if(empty()){
                cout << "queue is EMPTY";
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        int front(){
            if(empty()){
                cout << "queue is EMPTY";
                return -1;
            }
            return head->data;
        }
        bool empty(){
            return head == NULL;
        }

};