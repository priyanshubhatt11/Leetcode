class Solution {
public:
    
    
    int solve(vector<vector<char>>&mat, int i,int j, vector<vector<int>> &dp){
        if(i >= mat.size() || j>= mat[0].size() || mat[i][j] == '0'){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(mat, i, j+1, dp);
        int diagonal = solve(mat, i+1, j+1, dp);
        int down = solve(mat, i+1, j, dp);
        
        return dp[i][j] =  1 + min(right, min(diagonal, down));
    }
    
    int maximalSquare(vector<vector<char>>& mat) {
        int ret =0,ans =0;
        
        vector<vector<int>> dp(mat.size()+1, vector<int> (mat[0].size()+1, -1));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == '1'){
                    
                    ret = solve(mat, i, j,dp);
                    ans = max(ans, ret);
                    
                }
            }
        }
        //solve(matrix, 0, 0);
        return pow(ans,2);
    }
};