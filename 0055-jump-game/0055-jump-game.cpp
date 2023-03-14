class Solution {
public:
    
    int dp[10001];
    bool solve(vector<int>&nums, int idx){
        if(idx >= nums.size()-1)return true;
        if(dp[idx] != -1)return dp[idx];
        //cout<<idx<<" ";
        bool ans = false;
        for(int i=1;i<=nums[idx];i++){
            ans = ans |  solve(nums, idx+i);
            if(ans == true)return ans;
        }
        return dp[idx] = ans;
        
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};