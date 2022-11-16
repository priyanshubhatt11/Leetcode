
class Solution {
public:
    
    int height(TreeNode* root){
        if(root == NULL)return NULL;
        return max(1 + height(root->left) , 1+ height(root->right));
    }
    
    TreeNode* solve(TreeNode*root){
        if(root == NULL)return NULL;
        
        if(height(root->left) > height(root->right) ){
            return solve(root->left);
        }
        else if(height(root->left) < height(root->right)){
            return solve(root->right);
        }
        else {
            return root;
        }
       
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root);
    }
};