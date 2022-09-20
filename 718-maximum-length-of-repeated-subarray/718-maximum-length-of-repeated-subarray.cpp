class Solution {
public:
    int ans=0;
    int solve(vector<int>&n1, vector<int>&n2, int i,int j, vector<vector<int>> &dp){
        if(i>=n1.size() || j >= n2.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int count=0;
        if(n1[i] == n2[j]){
             count = 1 + solve(n1, n2, i+1, j+1, dp);
             //cout<<count<<" ";
        }
        
        solve(n1, n2, i+1, j, dp);
        solve(n1, n2, i, j+1, dp);
        
        ans = max(ans, count);
        //cout<<count<<" ";
        return dp[i][j] = count;
        
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> (nums2.size() ,-1));
        
        solve(nums1, nums2, 0 ,0, dp);
        return ans;
    }
};