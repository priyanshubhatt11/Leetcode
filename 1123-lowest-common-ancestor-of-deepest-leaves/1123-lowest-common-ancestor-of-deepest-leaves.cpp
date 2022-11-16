
class Solution {
public:
    
    int height(TreeNode* root){
        if(root == NULL)return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)return NULL;
        
        if(height(root->left) > height(root->right))    return lcaDeepestLeaves(root->left);
        else if(height(root->left) < height(root->right))   return lcaDeepestLeaves(root->right);
        else return root;
        
    }
};