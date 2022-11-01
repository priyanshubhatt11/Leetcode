class Solution {
public:
    
    int solve(vector<vector<int>>&mat, int i, int j, int num, vector<vector<int>> &dp){
        //if(i < 0 || i>= mat.size() || j < 0 || j>= mat[0].size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int l =0, r=0 , d=0, u =0;
        if(i < mat.size()-1 && num < mat[i+1][j]){
            d = 1 + solve(mat, i+1, j,  mat[i+1][j], dp);
        }
        if(i > 0 && num < mat[i-1][j]){
            u = 1 + solve(mat, i-1, j, mat[i-1][j], dp);
        }
        if(j < mat[0].size()-1 && num < mat[i][j+1]){
            r = 1 + solve(mat, i, j+1, mat[i][j+1], dp);
        }
        if(j>0 && num < mat[i][j-1]){
            l = 1 + solve(mat, i, j-1, mat[i][j-1], dp);
        }
        
        return dp[i][j] = max(d , max(u, max(r, l)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size(), m =mat[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans, 1 + solve(mat, i, j, mat[i][j], dp));
            }
        }
        return ans;
    }
};