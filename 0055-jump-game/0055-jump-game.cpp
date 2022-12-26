class Solution {
public:
    bool ans = false;
    bool solve(vector<int>&nums, int idx, vector<int> &dp){
        if(idx >= nums.size()-1)return true;
        if(dp[idx] != -1)return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            dp[idx] = solve(nums, idx+i, dp);
            if(dp[idx] == true)return dp[idx];
        }
        return false;
        
    }
    
    bool canJump(vector<int>& nums){
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};