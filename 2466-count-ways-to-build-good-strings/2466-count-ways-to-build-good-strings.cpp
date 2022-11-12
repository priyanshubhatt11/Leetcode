class Solution {
public:
    long long mod = 1000000007;
    
    int solve(int n, int low, int high, int zero, int one, vector<int>&dp){
        if(n >= high) return 0;
        if(dp[n]!= -1)return dp[n];
        long long a = solve(n+zero, low, high, zero, one, dp);
        if(low <=n+zero && n + zero <=high)a++;
        
        long long b = solve(n+one, low, high, zero, one, dp);
        if(low  <= n + one && n +one <= high)b++;
        
        return dp[n] = (a+b)%mod;
        
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(100005, -1) ;
        return solve(0, low, high, zero, one, dp);
    }
};