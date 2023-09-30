class Solution {
public:
    
    int dp[101];
    int solve(vector<int> &nums, int idx){
        if(idx >= nums.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        
        int take =0, nt=0;
        take += nums[idx] + solve(nums, idx+2);
        nt = solve(nums, idx+1);
        return dp[idx] = max(take, nt);
        
    }
    
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};