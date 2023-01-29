class Solution {
public:
    
    int mod = 1e9+7;
    vector<vector<int>> vec;
    vector<vector<vector<int>>> dp;
    int solve(int i, int j, int n){
        if( i<0 || i>= 4 || j<0 || j>=3|| vec[i][j] == -1 )return 0;
        
        if(n == 1)return 1;
        if(dp[i][j][n] != -1)return dp[i][j][n];
        long long ans =0;
        ans += solve(i-2, j-1, n-1)%mod;
        ans += solve(i-2, j+1, n-1)%mod;
        ans += solve(i-1, j-2, n-1)%mod;
        ans += solve(i+1, j-2, n-1)%mod;
        ans += solve(i+2, j-1, n-1)%mod;
        ans += solve(i+2, j+1, n-1)%mod;
        ans += solve(i+1, j+2, n-1)%mod;
        ans += solve(i-1, j+2, n-1)%mod;
        return dp[i][j][n] = ans%mod;
    }
    
    int knightDialer(int n) {
        long long ans =0;
        vec.resize(4, vector<int>(3));
        dp.resize(4, vector<vector<int>>(3, vector<int> (n+1, -1)));
        int c=1;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                vec[i][j] = c;
                c++;
            }
        }
        vec[3][0] = -1; vec[3][2] = -1;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans += solve(i, j, n)%mod;
                //cout<<ans <<" ";
            }
        }
        return ans%mod;
    }
};