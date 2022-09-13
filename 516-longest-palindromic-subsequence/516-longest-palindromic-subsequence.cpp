class Solution {
public:
    
    
    int solve(string &t1, string &t2 , int n, int m, vector<vector<int>>&dp){
        if(n == 0 || m== 0)return 0;
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(t1[n-1] == t2[m-1]){
            return  dp[n][m] =  1 + solve(t1, t2, n-1 , m-1, dp);
        }
        else{
            return  dp[n][m] = max(solve(t1, t2, n-1, m, dp) , solve(t1, t2, n, m-1, dp));
        }
        
        
        
    }
    
    int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(text1,text2,n,m, dp);
    }
    
    int longestPalindromeSubseq(string s) {
        string t =s;
        reverse(t.begin(), t.end());
        return(lcs(s,t));
        
        
    }
};