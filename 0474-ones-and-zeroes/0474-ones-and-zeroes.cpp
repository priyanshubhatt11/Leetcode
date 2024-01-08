class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>&strs, int idx, int m, int n){
        if(m <0 || n<0)return -1;
        if(idx >= strs.size())return 0;
        if(dp[idx][m][n] != -1)return dp[idx][m][n];
        
        int c1=0, c2= 0;
        for(auto &it:strs[idx]){
            if(it == '0')c1++;
            else c2++;
        }
        int take = 1 + solve(strs, idx+1, m-c1, n-c2);
        int nt = solve(strs, idx+1, m, n);
        
        return dp[idx][m][n] = max(take, nt);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, 0, m, n);
    }
};