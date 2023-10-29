class Solution {
public:
    
    long long dp[100001];
    long long solve(vector<int>&nums, int k, int idx){
        if(idx >= nums.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        
        long long x=0;
        if(k>nums[idx]){
            x = k - nums[idx];   
        }
        
        long long c1 = x + solve(nums, k, idx+1);
        long long c2 = x + solve(nums, k, idx+2);
        long long c3 = x + solve(nums, k, idx+3);
        
        return dp[idx] = min({c1,c2,c3});
        
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        long long c1 = solve(nums, k, 0);   
        long long c2 = solve(nums, k, 1); 
        long long c3 = solve(nums, k, 2); 
        return min({c1,c2,c3});
    }
};
