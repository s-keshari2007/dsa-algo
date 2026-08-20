#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, rank, size;

    public:
        DisjointSet(int n){
            // this done using 1  based indexing   
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            size.resize(n+1 ,0); 
            for(int i = 0; i <= n; i++){
                parent[i] = i; //firstly  everybody is the parent of itself
                size[i] = 1;
            }
        }

        int FindUpar(int node){
            if(node == parent[node]) return node;

            return parent[node] = FindUpar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = FindUpar(u);
            int ulp_v = FindUpar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = FindUpar(u);
            int ulp_v = FindUpar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
             }
        }


};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.FindUpar(3) == ds.FindUpar(7)){
        cout << "same\n";
    }
    else{
        cout << "not saame\n";
    }

    ds.unionBySize(3, 7);

    if(ds.FindUpar(3) == ds.FindUpar(7)){
        cout << "same\n";
    }
    else{
        cout << "not saame";
    }


    return 0;

}