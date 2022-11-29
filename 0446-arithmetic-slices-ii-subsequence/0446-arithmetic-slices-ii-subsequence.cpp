class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long ans =0;
        int n = nums.size();
        
        vector<unordered_map<long long , int>> dp(n);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff = (long long) nums[i] - (long long)nums[j];
                int count = 0;
            
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