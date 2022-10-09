#define MOD 1000000007;
class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& grid, int k, int i, int j, long long sum, vector<vector<vector<int>>> &dp){
        //cout<<i<<j<<" ";
        if(i<0 || i>=n || j<0 || j>=m)return 0;
        sum = sum%k;
        if(i == n-1 && j == m-1){
            sum += grid[i][j];
            sum = sum%k;
            if(sum == 0)return 1;
            return 0;
        }
        if(dp[i][j][sum] != -1)return dp[i][j][sum];
        
        long long ans =0;
        ans += solve(grid, k, i+1, j, sum + grid[i][j], dp) + solve(grid, k, i, j+1, sum + grid[i][j], dp);
        ans = ans%MOD;
        
        return dp[i][j][sum] = ans;
        
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size(), m= grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int> (k+1, -1)));
        return solve(grid, k, 0, 0, 0, dp);
    }
};