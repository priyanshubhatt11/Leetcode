class Solution {
public:
    
    int solve(string s1, string s2, int i,int j, vector<vector<int>> &dp){
        if(i==s1.size() || j ==s2.size())return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] =  1 + solve(s1, s2, i+1, j+1 , dp);
        }
        
            return dp[i][j] = max(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp)); 
        
    }
    
    int minDistance(string w1, string w2) {
        vector<vector<int>> dp(w1.size()+1, vector<int> (w2.size() +1, -1));
        int ans =solve(w1 , w2, 0, 0, dp);
        return w1.size() + w2.size() - 2 * ans;
    }
};