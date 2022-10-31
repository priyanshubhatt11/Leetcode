class Solution {
public:
    
    int solve(vector<int>&nums, int idx ,int prev, vector<vector<int>> &dp){
        if(idx >= nums.size())return 0;
        if(dp[idx][prev+1] != -1)return dp[idx][prev+1];
        
        int inc =0;
        
        if(prev == -1 || nums[prev] < nums[idx])
            inc = 1 + solve(nums, idx+1, idx, dp);
        
        int exc = solve(nums, idx+1, prev, dp);
        
        return dp[idx][prev+1] = max(inc, exc);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return solve(nums, 0,  -1, dp); 
    }
};