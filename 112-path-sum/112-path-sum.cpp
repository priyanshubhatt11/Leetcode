class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if(root == NULL)return false;
        target =  target-root->val;
        if(root ->left == root->right && target == 0)return true;
        
        return hasPathSum(root->left, target) || hasPathSum(root->right, target );
    }
};