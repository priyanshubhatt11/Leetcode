class Solution {
public:
    
    unordered_map<string,int> mp;
    vector<TreeNode*> vec;
    
    string solve(TreeNode *root){
        if(root == NULL)return "#";
        string x = solve(root->left);
        string y = solve(root->right);
        string s = to_string(root->val) + "#" + x + "#" + y ;
        if(mp[s] == 1){
            vec.push_back(root);
        }
        mp[s]++;
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return vec;
    }
};