class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum =0;
        for(int i=0;i<nums.size()-1;i++){
            int mi = nums[i];
            int mx = nums[i];
            for(int j=i+1;j<nums.size();j++){
                mi = min(mi, nums[j]);
                mx = max(mx, nums[j]);
                sum += mx-mi;
            }
        }
        return sum;
    }
};