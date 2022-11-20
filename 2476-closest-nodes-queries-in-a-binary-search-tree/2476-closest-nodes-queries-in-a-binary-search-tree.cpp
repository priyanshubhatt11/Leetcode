class Solution {
public:
    vector<int>arr;
    
    void dfs(TreeNode* root){
        if(!root) return;
        
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>>ans;
        
        for(auto& x : queries){
            vector<int>t(2,-1);
            auto it = lower_bound(arr.begin(),arr.end(),x+1);
            if(it != arr.begin()) {
                it--;
                t[0] = *it;
            }
            it = lower_bound(arr.begin(),arr.end(),x);
            
            if(it != arr.end()) t[1] = *it;
            ans.push_back(t);    
        }
        return ans;
        
    }
};