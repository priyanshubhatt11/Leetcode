// Can be rearranged to nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

class Solution {
public:
    int mod = 1e9+7;
    
    int rev(int x){
        int ans=0;
        while(x!=0){
            ans = ans*10 + x%10;
            x/=10;
        }
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<long long,long long> mp;
        for(int i=0;i<nums.size();i++){
            long long x = nums[i] - rev(nums[i]);
            mp[x]++;
        }
        long long ans =0;
        for(auto &i:mp){
            ans += ((i.second)*(i.second-1))/2;
            ans %= mod;
        }
        return ans;
    }
};