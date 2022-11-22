class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&vec, int idx , int tar){
        if(tar == 0)return 0;
        if(idx >= vec.size() || tar < 0)return 1000000;
        
        
        if(dp[idx][tar] != -1)return dp[idx][tar];
        
        
        int ans = INT_MAX;
        if(vec[idx] <= tar){
            ans = min(ans, 1 + solve(vec, idx, tar - vec[idx] ));
        }
        ans = min(ans, solve(vec, idx+1 , tar));
        return dp[idx][tar] = ans;
    }
    
    int numSquares(int n) {
        vector<int> vec;
        for(int i=1;i*i<=n;i++){
            vec.push_back(i*i);
        }
        dp.resize(101, vector<int>(10001, -1));
        return solve(vec, 0, n);
    }
};