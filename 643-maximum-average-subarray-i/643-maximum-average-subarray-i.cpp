class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int ans = INT_MIN;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        ans = max(ans, sum);
        
        for(int i=0;i<nums.size()-k;i++){
            sum = sum - nums[i] + nums[k+i];
            ans = max(ans, sum);
        }
        return (double)ans/k;
    }
};