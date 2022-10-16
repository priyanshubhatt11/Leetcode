class Solution {
public:
    
    int solve(vector<int> &nums, int d, int idx, vector<vector<int>> &dp){
        if(idx >= nums.size())return 1e9;   //If we return INT_MAX then int overflow will happen in ans variable
        if(d == 1){
            int c =-1;
            for(int i=idx;i<nums.size();i++)c=max(c, nums[i]);
            return c;   // return maximum when day = 1;
        }
        if(dp[idx][d] != -1)return dp[idx][d];
        
        int ans =INT_MAX;
        int curr =0;
        
        for(int i=idx;i<nums.size();i++){
            
            curr = max(curr, nums[i]);
            //cout<<curr<<" ";
            ans = min(ans, curr + solve(nums, d-1, i+1, dp));
        }
        return dp[idx][d] =  ans;
        
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size()<d)return -1;
        vector<vector<int>> dp(jd.size()+1, vector<int> (d+1, -1));
        return solve(jd, d, 0, dp);
    }
};