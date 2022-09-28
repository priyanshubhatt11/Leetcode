class Solution {
public:
    
    int solve(vector<int>&prices, int idx, int m, bool buy, vector<vector<vector<int>>> &dp){
        if(idx>=prices.size())return 0;
        if(m == 0)return 0;
        if(dp[idx][m][buy] != -1)return dp[idx][m][buy];
        
        int profit =0;
        if(buy){
            int buyit = -prices[idx] + solve(prices, idx+1, m, false, dp);
            int dontbuy = solve(prices, idx+1, m, true, dp);
            profit = max(buyit, dontbuy);
        }
        else{
            int sellit = prices[idx] + solve(prices, idx+1, m-1, true, dp);
            int dontsell = solve(prices, idx+1, m, false, dp);
            profit = max(sellit, dontsell);
        }
        return dp[idx][m][buy] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (3, vector<int>(2, -1)));
        return solve(prices, 0, 2, true, dp);
    }
};