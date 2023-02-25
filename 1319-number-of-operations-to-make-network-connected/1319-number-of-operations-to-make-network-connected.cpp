class Solution {
public:
    
    void dfs(vector<int> vec[], vector<bool>&vis, int idx){
        vis[idx] = true;
        for(auto i:vec[idx]){
            if(!vis[i]){
                dfs(vec, vis, i);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& nums) {
        if(nums.size() < n-1)return -1;
        vector<int> vec[n];
        for(auto i:nums){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        int c =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(vec, vis, i);
                c++;
            }
        }
        return c-1;
    }
};