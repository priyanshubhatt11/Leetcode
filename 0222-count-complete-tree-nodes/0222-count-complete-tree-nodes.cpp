
class Solution {
public:
    
    int count =0;
    
    void solve(TreeNode*root){
        if(root==NULL)return;
        solve(root->left);
        solve(root->right);
        count++;
    }
    
    int countNodes(TreeNode* root) {
        solve(root);
        return count;
    }
};