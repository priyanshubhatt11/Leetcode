class Solution {
public:
    
    int solve(vector<int>&vec, int idx , int tar, vector<vector<int>> &dp){
        if(idx >= vec.size() || tar < 0)return 1000000;
        if(tar == 0)return 0;
        
        if(dp[idx][tar] != -1)return dp[idx][tar];
        
        
        int ans = INT_MAX;
        if(vec[idx] <= tar){
            ans = min(ans, 1 + solve(vec, idx, tar - vec[idx] , dp));
        }
        ans = min(ans, solve(vec, idx+1 , tar, dp));
        return dp[idx][tar] = ans;
    }
    
    int numSquares(int n) {
        vector<int> vec;
        for(int i=1;i*i<=n;i++){
            vec.push_back(i*i);
        }
        vector<vector<int>> dp(101, vector<int>(10001, -1));
        return solve(vec, 0, n, dp);
    }
};