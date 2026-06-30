#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool isleaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }

     void addleftboundry(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->left;
        while(curr){
            if(!isleaf(curr)) res.push_back(curr->data);
            if(curr->left)  curr = curr->left;
            else  curr = curr->right;
        }
     }
    void addrightboundry(TreeNode* root ,vector<int> &res){
        vector<int> temp;
        TreeNode* curr = root->right;
        while(curr){
            if(!isleaf(curr)) temp.push_back(curr->data);
            if(curr->right)  curr = curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1; i>=0; i--){
            res.push_back(temp[i]);
        }
    }

    void addleaf(TreeNode* root ,vector<int> &res){
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addleaf(root->left,res);
        if(root->right) addleaf(root->right,res);
    }
    vector <int> boundary(TreeNode* root){
    	vector<int> res;
        if(!root) return res;
        if(!isleaf(root)) res.push_back(root->data);
        addleftboundry(root,res);
        addleaf(root,res);
        addrightboundry(root,res);

        return res;
        
    }
};