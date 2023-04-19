class Solution {
public:
    int ans =0;
    
    void solve(TreeNode* root, bool f, int c){
        if(root == NULL)return;
        ans = max(ans, c);
        if(f){
            solve(root->right, false, c+1);
            solve(root->left, true, 1);
        }
        else{
            solve(root->left, true, c+1);
            solve(root->right, false, 1);
        }
    }
    
    int longestZigZag(TreeNode* root) {
        solve(root->left, true, 1);
        solve(root->right, false, 1);
        return ans;
    }
};