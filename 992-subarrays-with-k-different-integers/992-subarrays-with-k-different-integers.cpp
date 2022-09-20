class Solution {
public:
    
    int solve(vector<int>&nums, int k){
        if(k<1)return 0;
        int ans =0, j=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            
            while(map.size() > k){
                map[nums[j]]--;
                if(map[nums[j]] == 0)map.erase(nums[j]);
                j++;
            }
            
            ans += i-j+1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // If we subtract atmost k with the atmost k-1 subarrays
        //  then we get exact k size of subarray
        
        int ans1 = solve(nums, k);
        int ans2 = solve(nums, k-1);
        return ans1 - ans2;
    }
};