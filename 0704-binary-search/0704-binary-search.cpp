class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(lo == nums.size() || nums[lo] != target)return -1;
        
        return lo;
    }
};