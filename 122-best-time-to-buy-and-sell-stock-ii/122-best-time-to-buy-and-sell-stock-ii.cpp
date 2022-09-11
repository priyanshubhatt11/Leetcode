class Solution {
public:
    
    int solve(vector<int> &pri, bool buy, int idx, vector<vector<int>> &dp){
        if(idx >= pri.size())return 0;
        
        if(dp[idx][buy] != -1)return dp[idx][buy];
        
        int profit =0;
        if(buy){    // buy
            profit = max(-pri[idx] + solve(pri, false, idx+1, dp), solve(pri, true, idx+1, dp));
        }
        else{   // Sell
            profit = max(pri[idx] + solve(pri, true, idx+1, dp), solve(pri, false, idx+1, dp));
        }
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        return solve(prices, true, 0, dp);
    }
};