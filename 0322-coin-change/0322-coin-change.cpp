class Solution {
public:
    int dp[13][10001];
    int solve(vector<int> &coins, int idx, int amount){
        if(idx < 0)return INT_MAX;
        if(amount <= 0)return 0;
        if(dp[idx][amount] != -1)return dp[idx][amount];
        long long take=INT_MAX;
        long long nt = INT_MAX;
        int ans = INT_MAX;
        //cout<<amount<<" "<<idx<<"\n";
        if(amount >= coins[idx]){
            take = 1 + (1LL)*solve(coins, idx, amount - coins[idx]);
        }
        nt = solve(coins, idx-1, amount);
        
        return dp[idx][amount] = min(nt, take);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, coins.size()-1, amount);
        if(ans >= INT_MAX)return -1;
        return ans;
    }
};