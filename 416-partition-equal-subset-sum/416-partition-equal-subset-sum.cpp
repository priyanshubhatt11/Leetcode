class Solution {
public:
    
    int solve(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
        if(idx >= nums.size() || target < 0)return 0;
        
        if(target == 0)return 1;
        
        if(dp[idx][target] != -1)return dp[idx][target];
            
        int include = solve(nums, idx+1, target- nums[idx], dp);
        
        int exclude = solve(nums, idx+1, target, dp);
        
        return dp[idx][target] = (include || exclude);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i:nums){
            sum += i;
        }
        if(sum%2 == 0){
            vector<vector<int>> dp(nums.size()+1, vector<int> ((sum/2) +1, -1));
            return solve(nums, 0, sum/2, dp);
        }
        return 0;
    }
};