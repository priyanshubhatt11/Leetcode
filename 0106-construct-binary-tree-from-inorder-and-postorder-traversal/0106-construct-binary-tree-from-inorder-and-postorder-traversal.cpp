class Solution {
public:
    
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>&ino, vector<int>&post, int i,int j, int &k){
        if(i>j)return NULL;
        
        //cout<<k<<" ";
        TreeNode* node = new TreeNode(post[k]);
        k--;
        int x = mp[node->val];
        node->right = solve(ino, post, x+1, j, k);
        node->left = solve(ino, post, i, x-1, k);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        
        for(int i=0;i<ino.size();i++)mp[ino[i]] = i;
        int n = ino.size()-1;
        int idx = n;
        return solve(ino, post, 0, n, idx);
    }
};