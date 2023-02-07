class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int> mp;
        int j=0;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp.size() >2){
                mp[nums[j]]--;
                if(mp[nums[j]] == 0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};