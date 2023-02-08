class Solution {
public:
    
    int solve(vector<int>&nums, int idx, vector<long long> &dp){
        if(idx >= nums.size()-1)return 0;
        if(dp[idx] != -1)return dp[idx];
        int ans = 1e5;
        for(int i=1;i<=nums[idx];i++){
            ans = min(ans, 1+ solve(nums,idx+i, dp));
        }
        return dp[idx] = ans;
    }
    
    int jump(vector<int>& nums) {
        vector<long long> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};