// first solution is dp
class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int k, int idx){
        if(idx >= nums.size() && k == 0)return 0;
        if(k < 0)return INT_MAX;
        
        if(dp[idx][k] != -1)return dp[idx][k];
        //cout<<idx<<" "<<k<<endl;
        int sum =0, ans = INT_MAX;
        for(int i=idx;i<nums.size();i++){
            sum += nums[i];
                     
            ans = min(ans, max(sum, solve(nums,k-1, i+1)));
        }
        return dp[idx][k] = ans;
    }
    
    int splitArray(vector<int>& nums, int k) {
        dp.resize(nums.size()+1, vector<int> (k+1, -1));
        return solve(nums, k, 0);
    }
};