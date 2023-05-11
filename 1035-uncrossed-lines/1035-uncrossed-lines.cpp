class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i,int j){
        if(i>=nums1.size() || j>=nums2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int t=0, nt=0;
        
        if(nums1[i] == nums2[j]){
            t = 1 + solve(nums1, nums2, i+1, j+1);
        }
        else{
            nt = max(solve(nums1, nums2, i+1, j), solve(nums1, nums2, i, j+1));
        }
        return dp[i][j] = max(t, nt);
        
        
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, 0, 0);
        
    }
};