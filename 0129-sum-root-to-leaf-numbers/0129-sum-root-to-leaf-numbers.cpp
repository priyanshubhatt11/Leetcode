class Solution {
public:
    
    int solve(TreeNode* root, int temp){
        if(root == NULL)return 0;
       
        
        int x = temp*10 + root->val;
        if(root->left == NULL && root->right == NULL)return x;
        int l = solve(root->left, x);
        int r = solve(root->right, x);
        return l+r;
    }
    
    int sumNumbers(TreeNode* root) {
        
        return solve(root, 0);
    }
};