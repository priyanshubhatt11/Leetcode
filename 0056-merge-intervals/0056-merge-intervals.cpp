class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        int mi = nums[0][0];
        int mx = nums[0][1];
        for(int i=1;i<nums.size();i++){
            if(nums[i][0] > mx){
                vec.push_back({mi,mx});
                mi = nums[i][0];
            }
            mx = max(mx, nums[i][1]);
        }
        vec.push_back({mi,mx});
        return vec;
    }
};