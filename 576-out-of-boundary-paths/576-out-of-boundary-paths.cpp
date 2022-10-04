class Solution {
public:
    long MOD = 1000000007;
    
    int solve(int m, int n, int N, int i, int j, vector<vector<vector<int>>> &dp){
        if(i < 0 || i >=m || j < 0 || j >= n)return 1;
        if(N == 0)return 0;
        if(dp[N][i][j] != -1)return dp[N][i][j];
        int ans =0;
        int up = solve(m, n, N-1 ,i+1, j, dp);
        int down = solve(m, n, N-1 ,i-1, j, dp);
        int right = solve(m, n, N-1 ,i, j+1, dp);
        int left = solve(m, n, N-1 ,i, j-1, dp);
        int total = (up % MOD + down % MOD + right % MOD + left%MOD) %MOD;
        dp[N][i][j] = total;
        return dp[N][i][j];
        
    }
    
    int findPaths(int m, int n, int mxmove, int i, int j) {
        vector<vector<vector<int>>> dp(mxmove+1, vector<vector<int>>(m+1, vector<int> (n+1, -1)));
        return solve(m,n,mxmove, i , j, dp);
    }
};