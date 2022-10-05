class Solution {
public:
    int ans=INT_MAX;
    void solve(TreeNode * root, int mm){
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL){
            ans = min(ans, mm);
        }
        solve(root->left , mm+1);
        solve(root->right , mm+1);
    }
    
    int minDepth(TreeNode* root) {
        solve(root, 0);
        if(ans == INT_MAX)return 0;
        return ans+1;
    }
};