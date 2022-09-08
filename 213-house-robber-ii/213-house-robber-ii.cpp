class Solution {
public:
    
    int solve(vector<int> &num, int n,vector<int> &dp){
        if(n < 0) return 0;
        if(n == 0)return num[0];
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = max(num[n] + solve(num, n-2, dp) , solve(num, n-1, dp));
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)return nums[0];
        
        vector<int> dp1(n+1, -1),dp2(n+1,-1) ;
        
        // Making two vector 
        // In one vector exclude first index and on another vector exclude nth index
        
        vector<int> first, second;
        for(int i=0;i<n;i++){
            if(i != 0){
                first.push_back(nums[i]);
            }
            if(i != n-1){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first, n-2,dp1), solve(second, n-2,dp2));
    }
};