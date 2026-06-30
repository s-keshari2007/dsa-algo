#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> prevSmallerElement(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size(),0);

    for(int i=0;i<v.size();i++){
        while(s.size()>0 && s.top()>=v[i]){
            s.pop();
        }
        if(s.empty()) ans[i]=-1;

        else ans[i] = s.top();

        s.push(v[i]);
    }
    return ans;

}


int main(){
    vector<int> v ={3,1,0,8,6};

    vector<int> ans = prevSmallerElement(v);

    for(int val : ans){
        cout << val << " ";
    }
}