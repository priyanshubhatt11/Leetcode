class Solution {
public:
    
    void solve(TreeNode*root, vector<int>&vec){
        if(root == NULL)return;
        vec.push_back(root->val);
        solve(root->left, vec);
        solve(root->right,vec);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        solve(root, vec);
        return vec;
    }
};