class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        map[0] = 1;
        int ans =0;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(map.find(sum - target) != map.end()){
                ans++;
                sum =0;
                map.clear();
            }
            map[sum] = 1;
        }
        return ans;
    }
};