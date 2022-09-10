class Solution {
public:
    #define MOD 1000000007;
    
    
    int solve(int n,int k,int target, vector<vector<long long>> &dp){
        if(target <0)return 0;
        if(n == 0 && target !=0)return 0;
        if(n != 0 && target == 0)return 0;
        if(n== 0 && target == 0)return 1;
        if(dp[n][target] != -1)return dp[n][target];
                
       
        long long ans =0;
        for(int i=1;i<=k;i++){
            ans += solve(n-1, k, target-i, dp);
            
        }
        return dp[n][target] = ans%MOD;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,  vector<long long> (target+1, -1));
        return solve(n, k, target, dp);
    }
};