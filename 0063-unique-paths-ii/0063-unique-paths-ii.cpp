class Solution {
public:
    int ans =0,n,m;
    int dp[101][101];
    
    int solve(vector<vector<int>>& nums, int i, int j){
        
        if(i == n-1 && j == m-1 && nums[i][j] != 1){
            ans++;
            return 1;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(i>=n || j>=m || nums[i][j] == 1)return 0;
        int ans =0;
        ans += solve(nums, i, j+1);
        ans += solve(nums, i+1, j);
        
        return dp[i][j] = ans;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        n=nums.size(),m=nums[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 0);
       
    }
};