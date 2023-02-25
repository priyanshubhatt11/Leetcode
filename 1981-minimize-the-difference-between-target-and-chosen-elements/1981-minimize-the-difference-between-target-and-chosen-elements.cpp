class Solution {
public:
    
    int dp[71][9000];
    
    int solve(vector<vector<int>>&mat, int tar, int idx, int num){
        
        if(idx >= mat.size()){
            return abs(tar - num);
        }
        if(dp[idx][num] != -1){
            return dp[idx][num];
        }
        int ans =INT_MAX;
        for(int i=0;i<mat[idx].size();i++){
            ans = min(ans , solve(mat, tar, idx+1, num + mat[idx][i]));
        }
        return dp[idx][num] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int tar) {
        memset(dp,-1,sizeof(dp));
        return solve(mat, tar, 0, 0);
        
    }
};