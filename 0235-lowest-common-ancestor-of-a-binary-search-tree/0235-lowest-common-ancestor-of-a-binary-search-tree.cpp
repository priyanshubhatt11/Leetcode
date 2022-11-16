
class Solution {
public:
    
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)return NULL;
        
        if(root->val > p->val && root->val > q->val) return solve(root->left , p, q);
        
        else if(root->val < p->val && root->val < q->val) return solve(root->right, p, q);
        
        return root;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};