/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solve(TreeNode *root, int t, vector<vector<int>> &ans, vector<int> vec){
        
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL){
            if(t == root->val ){
                vec.push_back(root->val);
                ans.push_back(vec);
            }
            return;
        }
        vec.push_back(root->val);
        solve(root->left, t - root->val, ans, vec);
        solve(root->right , t-root->val, ans, vec);
        vec.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(root, target,ans, vec);
        return ans;
    }
};