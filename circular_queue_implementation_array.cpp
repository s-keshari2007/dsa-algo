#include<iostream>
using namespace std;

class CircularQueue{ // size has to predefined
    int* arr;
    int currSize ,cap; //cap = capacity
    int f,r ; //f = front r = rear
public:
    CircularQueue(int size){
        cap = size;
        currSize = 0;
        arr = new int[cap];
        f=0,r =-1;
    }
    void push(int data){
        if(currSize == cap){
            cout << "CQ if full" <<endl;
        }
        r = (r+1)%cap;
        arr[r]=data;
        currSize++;
    }
    void pop(){
        if(currSize == 0){
            cout << "CQ is empty" <<endl;
        }
        f = (f+1)%cap;
        currSize--;
    }
    int front(){
        return arr[f];
    }
    bool empty(){
        return currSize == 0;
    }
    void printArr(){ //just print the array which stores CQ
        for(int i=0; i<currSize; i++){
            cout << arr[i] << " ";
        }
        cout <<endl;
    }

};
int main(){
    CircularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    //cq.push(4);
    cq.pop();
    cq.push(4);
    cq.printArr();

    while(!cq.empty()){ //printing in the order of circular queue
        cout << cq.front() << " ";
        cq.pop();
    }

    return 0;
}