
class Solution {
public:
    
    int height(TreeNode* root){
        if(root == NULL)return 0;
        
        return max(1 + height(root->left) , 1 + height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r) > 1)return false;
        
        return isBalanced(root->left) & isBalanced(root->right);
        
    }
};