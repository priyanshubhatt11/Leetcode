class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();
        if(n == 0)return {-1,-1};
        int l = lower_bound(nums.begin(), nums.end(), t) - nums.begin();
        int u = upper_bound(nums.begin(), nums.end() ,t) - nums.begin();
        vector<int> vec;
        u--;
        //cout<<l<<" "<<u;
        if(l < n && nums[l] == t)vec.push_back(l);
        else vec.push_back(-1);
        
        if(u >= 0 && nums[u] == t)vec.push_back(u);
        else vec.push_back(-1);
        
        return vec;
    }
};