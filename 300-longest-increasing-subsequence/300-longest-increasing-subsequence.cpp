class Solution {
public:
    
    int solve(vector<int> &nums, int n, int cur, int prev, vector<vector<int>>&dp){
        if(cur == n)return 0;
        
        if(dp[cur][prev+1] != -1)return dp[cur][prev+1]; 
        
        int include =0;
        if(prev == -1 || nums[cur] > nums[prev]){
            include = 1 + solve(nums,n, cur+1, cur, dp);
        }
        int exclude = solve(nums, n, cur + 1, prev, dp);
        
        return dp[cur][prev+1] = max(include, exclude);
        
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        int n = nums.size();
        return solve(nums, n, 0, -1, dp);   
    }
};