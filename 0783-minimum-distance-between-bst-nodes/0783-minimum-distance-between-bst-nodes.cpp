void solve(TreeNode*root, vector<int>&vec){
    if(root == NULL)return ;
    vec.push_back(root->val);
    solve(root->left, vec);
    solve(root->right, vec);
}
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        solve(root, vec);
        sort(vec.begin(), vec.end());
        int ans = INT_MAX;
        for(int i=0;i<vec.size()-1;i++){
            ans = min(ans, vec[i+1]-vec[i]);
        }
        return ans;
    }
};