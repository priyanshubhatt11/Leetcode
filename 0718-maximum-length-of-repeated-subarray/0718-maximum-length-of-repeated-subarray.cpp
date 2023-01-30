class Solution {
public:
    int ans =0;
    vector<vector<int>> dp;
    int solve(vector<int>&nums1, vector<int>&nums2, int i, int j){
        if(i>=nums1.size() || j>=nums2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int c=0;
        if(nums1[i] == nums2[j]){
            c = 1+ solve(nums1, nums2, i+1, j+1);
        }
        
        solve(nums1, nums2, i+1, j);
        solve(nums1, nums2, i, j+1);
        
        ans = max(ans, c);
        
        return dp[i][j] = c;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(), vector<int>( nums2.size() , -1));
        solve(nums1, nums2, 0, 0);
        
        return ans;
    }
};