class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mi = 0, mx =0, start =0;
        bool minFound = false, maxFound = false;
        
        long long ans =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK){
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if(nums[i] == minK){
                minFound = true;
                mi = i;
            }
            if(nums[i] == maxK){
                maxFound = true;
                mx = i;
            }
            
            if(minFound && maxFound){
                ans += min(mi, mx) - start + 1;
            }
        }
        return ans;
    }
};