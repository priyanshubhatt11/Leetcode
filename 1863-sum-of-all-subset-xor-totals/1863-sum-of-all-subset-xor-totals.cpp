class Solution {
public:
    
    int solve(vector<int> &nums, int ans, int idx){
        if(idx == nums.size())return ans;
        int pick = solve(nums, ans ^ nums[idx] , idx+1);
        int notpick = solve(nums, ans , idx+1);
        return pick + notpick;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        return solve(nums, ans ,0);
    }
};