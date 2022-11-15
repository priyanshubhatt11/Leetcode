
class Solution {
public:
    
    int ans= 0;
    void solve(TreeNode*root){
        if(root == NULL)return;
        ans++;
        solve(root->left);
        solve(root->right);
    }
    
    int countNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};