class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), output = nums[0];
        deque<int> dp;
        for (int i = 1; i < n; ++i){
            while (!dp.empty() && nums[dp.back()] <= nums[i-1]){
                dp.pop_back();
            }
            if (nums[i - 1] > 0){
                dp.push_back(i-1);
            }
            if (!dp.empty()){
                nums[i] += nums[dp.front()];
                if (i - dp.front() >= k){
                    dp.pop_front();
                }
            }
            output = max(output,nums[i]);
        }
        return output; 
    }
};