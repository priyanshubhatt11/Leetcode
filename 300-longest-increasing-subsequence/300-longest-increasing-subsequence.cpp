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
    
    int solveTab(vector<int> &num){
        int n = num.size();
        vector<vector<int>>dp (n+1, vector<int> (n+1, 0));
        
        for(int  cur= n-1; cur>=0; cur--){
            for(int prev = cur-1;prev >= -1; prev--){
                
                int include = 0;
                if(prev == -1 || num[cur] > num[prev]){
                    include = 1 + dp[cur+1][cur+1];
                } 
                int exclude = dp[cur+1][prev+1];
                
                dp[cur][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
        
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, -1));
        int n = nums.size();
        return solveTab(nums);
        //return solve(nums, n, 0, -1, dp);   
    }
};