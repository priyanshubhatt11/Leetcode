class Solution {
public:
    
    int solve(vector<int> &prices, int fee, int idx, bool buy, vector<vector<int>> &dp){
        if(idx == prices.size())return 0;
        
        if(dp[idx][buy] != -1)return dp[idx][buy];
        
        int profit =0;
        if(buy){
            int buyit = -prices[idx] + solve(prices, fee, idx+1, false, dp) ; // -3 + 8 = 5 taking price[idx] negative to find miximum
            int dontbuyit = solve(prices, fee, idx+1, true, dp);
            profit = max(buyit, dontbuyit);
        }
        else{
            int sellit = prices[idx] - fee + solve(prices, fee, idx+1, true, dp) ;
            int dontsellit = solve(prices, fee, idx+1, false, dp);
            profit = max(sellit, dontsellit);
        }
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solve(prices, fee, 0, true, dp);
    }
};