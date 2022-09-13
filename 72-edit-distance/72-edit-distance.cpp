class Solution {
public:
    
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        if(i == a.length()){    // word a is small
            return b.size() - j; // deleting remaining char
        }
        if(j == b.length()){    // word b is small
            return a.size() - i;
        }
        if(dp[i][j] != -1)return dp[i][j];
        
        int mm=0;
        if(a[i] == b[j]){
            return solve(a, b, i+1, j+1, dp);
        }
        else{
            int insert =  solve(a, b, i, j+1, dp);
            int del =  solve(a , b , i+1, j, dp);
            int replace =  solve(a, b, i+1, j+1, dp);
            mm = 1+ min(insert, min(del, replace));
        }
        return dp[i][j] = mm;
        
    }
    
    int minDistance(string w1, string w2) {
        vector<vector<int>> dp(w1.size(), vector<int> (w2.size(), -1));
        return solve(w1, w2, 0, 0, dp);
    }
};