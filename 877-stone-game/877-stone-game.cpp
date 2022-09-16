class Solution {
public:
    
    int solve(int i, int j, vector<int> &pile, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j] != INT_MIN)return dp[i][j];
        
        return dp[i][j] = max(pile[i] - solve(i+1,j,pile, dp), pile[j] - solve(i, j-1, pile, dp));
    }
    
    bool stoneGame(vector<int>& piles) {
        // return 1; // Answer will be always true
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int ans = solve(0, n-1, piles, dp);
        if(ans >0)return true;
        return false;
    }
};