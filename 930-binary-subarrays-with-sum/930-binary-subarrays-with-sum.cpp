class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0,sum=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == goal)ans++;
            if(map.find(sum-goal) != map.end()){
                ans += map[sum - goal];
            }
            
            map[sum]++;
        }   
        return ans;
    }
};