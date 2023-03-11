class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&vec, int idx, bool flag){
        if(idx >= vec.size()){
            return 0;
        }
        if(dp[idx][flag]!= -1) return dp[idx][flag];
        int pro =0;
        if(flag){
            pro = max(-vec[idx] + solve(vec, idx+1, false), solve(vec, idx+1, true));
        }
        else{
            pro = max(+vec[idx] + solve(vec, idx+1, true), solve(vec, idx+1, false));
        }
        return dp[idx][flag] =  pro;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<int>(2, -1));
        return solve(prices, 0, true);
    }
};