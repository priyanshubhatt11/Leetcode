class Solution {
public:
    int mod = 1e9+7;
    int dp[101][101][101];
    int solve(int n, int mi, vector<int> &gr, vector<int> &pr, int idx){
        //cout<<n<<" "<<mi<<endl;
        
        if(n < 0)return 0;
        if(idx >= gr.size()){
            if(mi <= 0)return 1;
            return 0;
        }
        if(dp[n][mi][idx] != -1)return dp[n][mi][idx];
        
        
        int ans =0;
        ans += solve(n, mi, gr, pr, idx+1);
        ans += solve(n-gr[idx], max(mi - pr[idx], 0), gr, pr, idx+1); // we have done max(mi - pr[idx], 0) because to prevent searching negative indexes in dp
        
        
        return dp[n][mi][idx] = ans%mod;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return solve(n, minProfit, group, profit, 0);
    }
};