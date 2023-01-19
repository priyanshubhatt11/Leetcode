class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        long long sum= 0;
        int ans= 0;
        for(auto i:nums){
            sum += i;
            int x = sum%k;
            if(x<0){
                x+=k;  // NOTE :- we add the number k to make it positive   
            }
            ans+=mp[x];
            mp[x]++;
        }
        return ans;
    }
};