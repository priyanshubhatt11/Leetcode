class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k>nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int mini=nums[k-1]-nums[0];
        for(int i=k;i<nums.size();i++){
            mini=min(nums[i]-nums[i-k+1],mini);
        }
        return mini;
    }
};