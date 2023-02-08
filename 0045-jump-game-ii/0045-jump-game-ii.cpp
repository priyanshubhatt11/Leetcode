class Solution {
public:
    
    int dp[100001];
    long long solve(vector<int>&nums, int idx){
        if(idx >= nums.size())return 1001;
        if(idx == nums.size()-1)return 0;
        if(dp[idx] != -1)return dp[idx];
        long long ans = 100001;
        for(int i=1 ;i<=nums[idx];i++){
        
            ans = min(ans, 1 + solve(nums, idx+i));
        }
        return dp[idx] = ans;
    }
    
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
       
        
    }
};