class Solution {
public:
    vector<int> dp;
    int solve(vector<int>&days, vector<int> &costs, int idx){
        if(idx >= days.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        
        int a = costs[0] + solve(days, costs, idx+1);
        
        int i;
        for(i=idx;i<days.size() && days[i] < days[idx] + 7;i++);
        int b = costs[1] + solve(days, costs, i);
        
        for(i=idx;i<days.size() && days[i] < days[idx] + 30;i++);
        int c = costs[2] + solve(days, costs, i);
        
        return dp[idx] = min({a,b,c});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return solve(days, costs, 0);
    }
};