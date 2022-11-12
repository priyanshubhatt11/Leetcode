//  https://www.youtube.com/watch?v=WszrfSwMz58

class Solution {
public:
    
    int ans = INT_MIN;
    
    int solve(TreeNode* root){
        if(root == NULL)return 0;
        
        int left =0, right =0;
        
        left = max(left, solve(root->left));
        right = max(right, solve(root->right));
        
        ans = max(ans , root->val + left + right);
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};