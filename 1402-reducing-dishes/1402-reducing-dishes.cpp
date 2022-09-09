class Solution {
public:
    
    int solve(vector<int> &sat, int idx, int t, vector<vector<int>> &dp){
        if(idx >= sat.size())return 0;
        if(dp[idx][t] != -1)return dp[idx][t];
        
        int include = (sat[idx] * t) + solve(sat, idx+1, t+1 ,dp);
        
        int exclude = solve(sat, idx +1, 1, dp);
        
        return dp[idx][t] = max(include, exclude);
    
    }
    
    int maxSatisfaction(vector<int>& sat) {
        
        vector<vector<int>> dp(sat.size()+1 , vector<int>(sat.size()+1, -1));
        sort(sat.begin(),sat.end());
        return solve(sat, 0, 1, dp);
    }
};