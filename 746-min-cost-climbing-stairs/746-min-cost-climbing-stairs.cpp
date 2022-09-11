class Solution {
public:
    
    int solve(vector<int> &cost, int i, vector<int> &dp){
        if(i >= cost.size())return 0;
        if(dp[i] != -1)return dp[i];
        
        return dp[i] = min(cost[i] + solve(cost, i+1, dp), cost[i] + solve(cost, i+2, dp));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        return min(solve(cost, 0, dp), solve(cost, 1, dp));
    }
};