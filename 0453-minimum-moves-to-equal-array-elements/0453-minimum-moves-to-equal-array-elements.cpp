class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *min_element(nums.begin(), nums.end());
        int ans =0;
        for(auto i:nums){
            ans += (i-mx);
        }
        return ans;
    }
};