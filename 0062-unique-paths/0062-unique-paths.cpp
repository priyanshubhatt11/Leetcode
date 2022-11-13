class Solution {
public:
    
    int solve(int x, int y, int i, int j, vector<vector<int>> &dp){
        if(i >= x || j >= y)return 0;
        if(i == x-1 && j == y-1)return 1;
        if(dp[i][j] != -1)return dp[i][j];
        int t1=0;
        t1 += solve(x,y, i+1, j, dp) + solve(x, y, i, j+1, dp);
        return dp[i][j] = t1;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n ,0));
        vector<vector<int>> dp(m, vector<int> (n ,-1));
        
        return solve(m, n, 0, 0, dp);
        
    }
};