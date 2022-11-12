class Solution {
public:
    
     long long mod = 1000000007;
    
    int solve(int n, int l, int h, int z, int o, vector<int>&dp){
        if(n > h)return 0;
        int ans=0;
        if(n>=l)ans=1;
        if(dp[n]!=-1)return dp[n];
        
        ans += (solve(n+z, l, h, z, o, dp)%mod) + (solve(n+o, l, h, z, o, dp)%mod);
        
        return dp[n] = ans;
    }
    
    int countGoodStrings(int low, int high, int z, int o) {
        vector<int> dp(100005, -1);
        return solve(0, low, high, z, o, dp)%mod;
    }
};