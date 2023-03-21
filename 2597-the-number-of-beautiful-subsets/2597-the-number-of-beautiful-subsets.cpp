class Solution {
public:
    unordered_map<int,int> mp;
    
    int solve(vector<int>&nums, int idx, int k){
        if(idx >= nums.size())return 0;
        
        int take =0;
        if(mp[nums[idx] -k] == 0){
            mp[nums[idx]]++;
            take = 1 + solve(nums, idx+1, k);
            mp[nums[idx]]--;
        }
        int nottake = solve(nums, idx+1, k);
        
        return take + nottake;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return solve(nums, 0, k);
    }
};