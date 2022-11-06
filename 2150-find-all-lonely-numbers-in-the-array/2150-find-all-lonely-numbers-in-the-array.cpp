class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int >ans;
        int n=nums.size();
       
        for(auto i:nums)
        {
            mp[i]++;
        }
        int x=0;
        for(auto x:nums)
        {
            if(mp[x] == 1){
           if(mp.find(x)!=mp.end() && (mp.find(x-1)==mp.end())&& (mp.find(x+1)==mp.end()))
           {
               ans.push_back(x);
           }
            }
        
        }
        return ans;


    }
};