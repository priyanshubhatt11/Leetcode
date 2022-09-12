class Solution {
public:
    
    int solve(int k, vector<int>&prices, int idx, bool buy, vector<vector<vector<int>>> &dp){
        if(idx >= prices.size() || k == 0)return 0;
        
        if(dp[idx][buy][k] != -1)return dp[idx][buy][k];
        
        int profit =0;
        if(buy){
            int buyit = -prices[idx] + solve(k, prices, idx+1, false,dp);
            int dontbuy = solve(k, prices, idx+1, true, dp);
            
            profit = max(buyit, dontbuy);
        }
        else{
            int sellit = prices[idx] + solve(k-1, prices, idx+1, true, dp);
            int dontsell = solve(k, prices, idx+1, false, dp);
            profit = max(sellit, dontsell);
        }
        return dp[idx][buy][k] = profit;
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return solve(k, prices, 0, true, dp);
    }
};