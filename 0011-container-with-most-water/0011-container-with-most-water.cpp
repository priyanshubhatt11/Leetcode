class Solution {
public:
    int maxArea(vector<int>& nums) {
        // we move index which is small because we takes minimum of both , so their is no logic to move maximum number index
        int l=0, h = nums.size()-1;
        int ans= 0;
        while(l<h){
            ans = max(ans, (h-l)*min(nums[l], nums[h]));
            if(nums[l] > nums[h]) h--;
            else l++;
        }
        return ans;
    }
};