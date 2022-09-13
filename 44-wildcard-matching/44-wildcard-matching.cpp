class Solution {
public:
    
    int solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        if(i <0 && j< 0)return true;
        if(i>=0 && j < 0)return false;
        
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k] != '*')return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(s, p, i-1, j-1, dp);
        }
        else if(p[j] == '*'){
            return dp[i][j] = (solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp) );    // taking character || empty character
        }
        else{
            return dp[i][j] = false;
        }
    }
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};