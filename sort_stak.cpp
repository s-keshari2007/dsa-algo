#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<vector>

using namespace std;

void sortStack(stack<int> &s){

    vector<int> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    sort(v.begin(),v.end());

    for(int i=0; i<v.size(); i++){
        s.push(v[i]);
    }
}

int main(){
stack<int> s ;
    s.push(11);
    s.push(2);
    s.push(32);
    s.push(3);
    s.push(41);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() <<endl;
        s.pop();
    }

    return 0;
}