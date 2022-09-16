class Solution {
public:
    
    int solve(vector<int> &nums, vector<int>& mul, int i, int j, int n, vector<vector<int>>&dp){
        if(j == mul.size())return 0;
        if(dp[i][j] != INT_MIN)return dp[i][j];
        
        int front =  solve(nums, mul, i+1, j+1, n, dp) + (nums[i] * mul[j]) ;
        int endd =   solve(nums, mul , i, j+1, n, dp) + (nums[n-1 - (j-i)] * mul[j]);
        
        return dp[i][j] = max(front, endd);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n = nums.size(),m = mul.size();
        vector<vector<int>> dp(m+1, vector<int> (m+1, INT_MIN));
        return solve(nums, mul, 0 , 0 , n, dp);
    }
};