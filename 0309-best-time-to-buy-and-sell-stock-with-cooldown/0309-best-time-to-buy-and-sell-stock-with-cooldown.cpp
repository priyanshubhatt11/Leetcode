class Solution {
public:
    
    int solve(vector<int>&nums, int idx, bool flag, vector<vector<int>> &dp){
        if(idx >=nums.size())return 0;
        if(dp[idx][flag] != INT_MIN)return dp[idx][flag];
        if(flag){   // can buy
            return dp[idx][flag] = max(solve(nums, idx+1, false, dp) - nums[idx] , solve(nums, idx+1, true, dp)); // buy or not
        }
        else{
            return dp[idx][flag] = max(solve(nums, idx+2, true, dp) + nums[idx], solve(nums, idx+1, false ,dp));  // sell or not
        }
    }
    
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        return solve(nums, 0, true, dp);
    }
};