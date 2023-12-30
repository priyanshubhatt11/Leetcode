
class Solution {
public:
    int ans =0;
    int solve(TreeNode* root){
        if(root == NULL)return -1;
        int l = solve(root->left) + 1;
        int r = solve(root->right) + 1;
        ans = max(ans, l + r);
        return max(l, r);
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};