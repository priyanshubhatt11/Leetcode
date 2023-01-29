class Solution {
public:
    int dp[101];
    int solve(string s, int idx){
        if(idx == s.size())return 1;
        if(idx > s.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        
        int x1 = s[idx]-'0', x2 =0;
        int ans =0;
        if(idx<s.size()-1)x2 = x1*10 + s[idx+1]-'0';
        if(x1 > 0){
            ans += solve(s, idx+1);
        }
        if(x1 > 0 && x2 >0 && x2<=26){
            ans += solve(s, idx+2);
        }
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};