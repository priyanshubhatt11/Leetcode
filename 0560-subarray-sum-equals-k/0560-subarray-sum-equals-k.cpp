class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long,int> mp;
        mp[0]++;
        long long x =0;
        int ans =0;
        for(auto i:nums){
            x += i;
            int tar = x - k;
            if(mp.count(tar)){
                ans += mp[tar];
            }
            mp[x]++;
        }
        return ans;
    }
};