
class Solution {
public:
    bool ans = true;
    bool mainn = false;
    
    bool doit(TreeNode* root, TreeNode* tar){
        if(root == NULL && tar == NULL)return true;
        if(root == NULL || tar == NULL)return false;
        if(root->val != tar->val)return false;
        
        ans &= (doit(root->left, tar->left) & doit(root->right, tar->right));
        
        return true;
        
    }
    
    void solve(TreeNode* root, TreeNode* tar){
        if(root == NULL)return;
        if(root->val == tar->val){
            
            ans = true;
            
            TreeNode* t1 = root, * t2 = tar;
            doit(t1, t2);
            
            mainn |= ans;
            
        }
        solve(root->left, tar);
        solve(root->right, tar);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solve(root , subRoot);
        
        return mainn;
    }
};