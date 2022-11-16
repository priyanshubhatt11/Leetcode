
class Solution {
public:
    
    int height(TreeNode* root){
        if(root == NULL)return 0;
        
        return max(1+ height(root->left), 1+ height(root->right));
    }
    
    TreeNode* solve(TreeNode* root){
        if(root == NULL)return NULL;
        int l = height(root->left);
        int r = height(root->right);
        if( l > r ){
            return solve(root->left);
        }
        else if(l < r){
            return solve(root->right);
        }
        return root;
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root);
    }
};