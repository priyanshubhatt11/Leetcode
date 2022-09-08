class Solution {
public:
    
    int solve(vector<int> &days, vector<int> &cost, int idx, vector<int> &dp){
        if(idx >= days.size())return 0;
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        // 1 day pass
        int a = cost[0] + solve(days,cost, idx+1, dp);
        
        // 7 day pass
        int i;
        for(i = idx; i<days.size() && days[i] < days[idx] + 7; i++);
        
        int b = cost[1] + solve(days, cost, i, dp);
        
        // 30 days pass
        for(i= idx; i< days.size() && days[i] < days[idx] + 30;i++);
        
        int c = cost[2] + solve(days, cost, i, dp);
        
        return dp[idx] = min(a, min(b,c));
        
        
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        return solve(days, costs, 0, dp);
    }
};