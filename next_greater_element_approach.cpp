#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    vector<int> v = {6,8,0,1,3};
    vector<int> ans(v.size(),0);

    stack<int> s;

    for(int i=v.size()-1;i>=0;i--){   //this program has time cmplexity of O(n) 
        while(s.size()>0 && s.top()<=v[i]){ /*since even in worst case every element in the worst case is also pushed and pop only one time*/
            s.pop();
        }
        if(s.empty()) ans[i]=-1;
        
        else ans[i]=s.top();

        s.push(v[i]);

    }

    for(int val : ans){
        cout << val <<" ";
    }
    cout<<endl;
}