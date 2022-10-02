class Solution {
public:
     
    #define MOD 1000000007;
    
    int solve(int n, int k, int target, vector<vector<int>> &dp){
        if(target < 0 || n<0)return 0;
        if(target == 0 && n == 0)return 1;
        if(dp[n][target] != INT_MIN){
            return dp[n][target];
        }
        
        long long ans= 0;
        for(int i=1;i<=k;i++){
            ans += solve(n-1, k, target-i, dp);
        }
        return dp[n][target] = ans%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, INT_MIN));
        return solve(n, k, target, dp);
    }
};