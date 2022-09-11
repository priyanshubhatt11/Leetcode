class Solution {
public:
    
    int solve(vector<int> &prices, int idx,int mm, bool buy, vector<vector<vector<int>>> &dp){
        if(idx >= prices.size())return 0;
        if(mm == 0)return 0;
        if(dp[idx][buy][mm] != -1)return dp[idx][buy][mm];
        
        int profit =0;
        if(buy){
            int buyi = -prices[idx] + solve(prices, idx+1, mm, false, dp);
            int notbuyi = solve(prices, idx+1, mm, true, dp);
            profit = max(buyi, notbuyi);
        }
        else{
            int selli = prices[idx] + solve(prices, idx+1, mm-1, true, dp);
            int notselli = solve(prices, idx+1, mm, false, dp);
            profit = max(selli, notselli);
        }
        return dp[idx][buy][mm] = profit;
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int> (3, -1)));
        return solve(prices, 0, 2, true, dp);
    }
};