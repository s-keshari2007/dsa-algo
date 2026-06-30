#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;  
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;    
    }
};
static int idx = -1;
    Node* buildTree(vector<int> preorder){ //O(n)
        idx++;
        if(preorder[idx] == -1) return NULL ;

        Node* root = new Node(preorder[idx]);
        root->left = buildTree(preorder);// LEFT
        root->right = buildTree(preorder);//RIGHT

        return root;

    }
int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftcount = count(root->left);
    int rightcount = count(root->right);

    return leftcount+rightcount+1;
}

int main(){

    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
     
    Node* root = buildTree(preorder);

    cout << "the number of nodes are: "  << count(root) <<endl;
    return 0;
}