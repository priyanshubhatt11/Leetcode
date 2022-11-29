class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // vector<int> slice;
        // return numberOfArithmeticSlices(nums, 0, slice);
        int ans = 0, n = nums.size();
        vector<unordered_map<long, int>> dp(n);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int count = 0;
                long diff = (long)nums[i] - nums[j];
                if (dp[j].find(diff) != dp[j].end()){
                    count = dp[j][diff];
                }
                dp[i][diff] += count + 1;
                ans += count;
            }
        }
        return ans;
        
    }
};