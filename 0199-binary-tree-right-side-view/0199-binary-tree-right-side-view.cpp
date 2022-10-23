
class Solution {
public:
    
    void solve(TreeNode *root, vector<int> &vec, int c){
        if(root == NULL)return;
        if(c == vec.size())vec.push_back(root->val);
        
        solve(root->right, vec, c+1 );
        solve(root->left, vec, c+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        solve(root, vec, 0);
        return vec;
    }
};