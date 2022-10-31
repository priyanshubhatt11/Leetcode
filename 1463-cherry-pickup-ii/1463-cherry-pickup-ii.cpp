class Solution {
public:
    
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, int n, int m, vector<vector<vector<int>>>&dp){
        if(i == n)return 0;
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)return INT_MIN;
        
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        
        int ans = 0;
        for(int x = -1; x <=1 ;x++){
            for(int y = -1; y <=1; y++){
                ans = max(ans , solve(grid, i+1, j1 + x , j2 + y, n, m, dp));
            }
        }
        if(j1 == j2)ans+= grid[i][j1];   // both are in same column
        else{
            ans += grid[i][j1] + grid[i][j2];
        }
        
        return dp[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
        // row will be same but column will change (i, j1, j2);
        return solve(grid, 0, 0, m-1, n, m, dp);
    }
};