class Solution {
public:
    
    int solve(vector<int> &nums, int idx,int n, int k, vector<vector<int>> &dp){
        if(idx > n || k == 0) return 0;
        if(dp[idx][k] != -1)return dp[idx][k];
        
        int inc = nums[idx] + solve(nums, idx+2, n, k-1, dp);
        int exc = solve(nums, idx+1, n, k, dp);
        int ans = max(inc, exc);
        return dp[idx][k] = ans;
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k , vector<int>(k, -1));
        vector<vector<int>> dp2(k , vector<int>(k, -1));
        int ans1 = solve(slices, 0, k-2 ,k/3, dp1);
        int ans2 = solve(slices, 1, k-1, k/3, dp2);
        return max(ans1, ans2);
    }
};