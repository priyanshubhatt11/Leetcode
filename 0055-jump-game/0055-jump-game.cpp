class Solution {
public:
    bool ans = false;
    bool solve(vector<int>&nums, int idx, vector<int> &dp){
        if(idx >= nums.size()-1)return true;
        if(dp[idx] != -1)return dp[idx];
        
        for(int i=1;i<=nums[idx];i++){
            ans = ans || solve(nums, idx+i, dp);
            if(ans == true)return true;
        }
        return dp[idx] = ans;
        
    }
    
    bool canJump(vector<int>& nums){
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};