class Solution {
public:
    vector<vector<int>> dp;
    int ok(string &s, string &t, int n, int m){
        if(n == 0 || m == 0)return 0;
        if(dp[n][m] != -1)return dp[n][m];
        
        if(s[n-1] == t[m-1]){
            return dp[n][m] = 1 + ok(s, t, n-1, m-1);
        }
        else{
            return dp[n][m] = max(ok(s, t, n-1, m), ok(s, t, n, m-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        dp.resize(n+1, vector<int> (n+1, -1));
        return ok(s, t, n, n);
    }
};