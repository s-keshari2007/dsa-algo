#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>

using namespace std;

int main(){

    // map<int,int> mpp;
    // mpp[0] = 1;
    // cout << mpp[0] << endl;
    // mpp[0] = 2;
    // cout << mpp[0];
    // return 0;
    // vector<int> vec = {1,5,2};
    // sort(vec.begin(),vec.end());
    // reverse(vec.begin(),vec.end());
    // for(int i =0;i<3;i++){
    //     cout << vec[i] << " ";
    // }

    vector<char> ch = {'A', 'C', 'A', 'D', 'D', 'B'};

    sort(ch.begin(), ch.end());

    // for(int i = 0; i < 6; i++){
    //     cout << ch[i] << " ";

    //     vector<vector<int>> v;
    //     vector<vector<int>> a = {{1,2},{3,4}};
    //     v.push_back(a[0]);
    // }

    int v[5] = {0};        
    for(int i = 0; i <5; i++){
        cout << v[i] << " ";
    }
}