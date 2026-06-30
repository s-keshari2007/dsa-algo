#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int getCelebrity(vector<vector<int>> arr){
    stack<int> s;
    int n = arr.size();

    for(int i =0; i<n; i++){
        s.push(i);
    }

    while(s.size()>1){
        int i =s.top();
        s.pop();
        int j =s.top();
        s.pop();

        if(arr[i][j] == 0){
            s.push(i);
        }
        else{
            s.push(j);
        }
    }

    int ans = s.top();

    for(int i =0; i<n; i++){
        if(i!=ans && arr[i][ans] == 0 && arr[ans][i] ==1){
            return -1;
        }
    }

    return ans;

}


int main(){
    vector<vector<int>> arr = {{0,1,0} ,{0,0,0},{0,1,0}};

    int celeb = getCelebrity(arr);

    cout << "the celebrity is :" << celeb << endl;

    return 0;
}f