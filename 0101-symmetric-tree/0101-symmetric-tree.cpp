class Solution {
public:
    
    bool solve(TreeNode*l, TreeNode*r){
        if(l == NULL && r == NULL)return true;
        if(l == NULL || r == NULL)return false;
        if(l->val != r->val)return false;
        return solve(l->left, r->right) & solve(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};