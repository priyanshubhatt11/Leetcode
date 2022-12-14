class Solution {
public:
    
    long long solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx >= nums.size()-1)return 0;
        if(dp[idx] != -1)return dp[idx];
        
        long long mm = INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            mm = min(mm, 1 + solve(nums, idx + i, dp));
        }
        return dp[idx] = mm;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};