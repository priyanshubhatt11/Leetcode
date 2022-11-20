// https://www.youtube.com/watch?v=6PAj5F9O4gU

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> map;
        map[0] = -1;
        int sum =0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                sum += 1;
            }
            else sum -= 1;
            
            if(map.count(sum)){
                ans = max(ans, i - map[sum]);
            }
            else map[sum] = i;
        }
        return ans;
    }
};