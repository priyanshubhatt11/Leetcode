class Solution {
public:
    
    int solve(vector<int> &val, int i,int j, vector<vector<int>> &dp){
        if(i+1 >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k = i+1; k< j;k++){
            int mm = val[i]*val[j] *val[k] + solve(val, i, k, dp) + solve(val ,k ,j, dp);
            ans = min(ans, mm);
            dp[i][j] = ans;
        }
        //cout<<ans<<" ";
        return dp[i][j];
        
    }
    
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp( values.size(), vector<int> (values.size(), -1));
         return solve(values, 0, values.size()-1, dp);
    }
};