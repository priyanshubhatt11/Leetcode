class Solution {
public:
    
    vector<long long> dp;
    long long solve(vector<vector<int>>&vec, int i){
        if(i >= vec.size())return 0;
        if(dp[i] != -1)return dp[i];
        
        long long t = vec[i][0] + solve(vec, i+vec[i][1]+1);
        long long nt = solve(vec, i+1);
        
        return dp[i] = max(t, nt);
        
    }
    
    long long mostPoints(vector<vector<int>>& vec) {
        dp.resize(vec.size(), -1);
        return solve(vec, 0);
    }
};