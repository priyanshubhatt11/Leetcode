
class Solution {
public:
    unordered_map<TreeNode*, int> map;
    int solve(TreeNode *root){
        if(root == NULL)return 0;
        if(map.find(root)!=map.end())return map[root];
        int sum =0;    
        if(root->left){
            sum += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            sum += solve(root->right->left) + solve(root->right->right);
        }
        return map[root] = max(root->val + sum , solve(root->left) + solve(root->right));
        
    }
    
    int rob(TreeNode* root) {
        
        return solve(root);     // given , there is only one entrance in house so we have to include                                           first node 
    }
};