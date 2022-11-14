class Solution {
public:
    
    void dfs(int idx, vector<vector<int>> &nums, vector<bool> &vis){
        vis[idx] = true;
        for(int i=0;i<nums.size();i++){
            
            if(vis[i])  continue;
            
            if(nums[i][0] == nums[idx][0] || nums[i][1] == nums[idx][1]){
                dfs(i, nums, vis);
            }
        }
    }
    
    int removeStones(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<bool> vis(n , false);
        
        int c =0;
        for(int i=0;i<n ;i++){
            if(vis[i])  continue;
            dfs(i, nums, vis);
            c++;
        }
        
        return n - c;   // n - number of connected graphs formed
    }
    
};