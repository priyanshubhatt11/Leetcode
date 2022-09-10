class Solution {
public:
        
    int solve(vector<vector<int>> &cubo, int cur, int prev, vector<vector<int>> &dp){
        if(cur >= cubo.size() )return 0;
        if(dp[cur][prev+1] != -1)return dp[cur][prev+1];
        
        int include =0;
        if(prev == -1 || (cubo[cur][0] >= cubo[prev][0] && cubo[cur][1] >= cubo[prev][1] && cubo[cur][2] >= cubo[prev][2]) )
        {
            include = cubo[cur][2] + solve(cubo, cur+1, cur, dp);
        }
        int exclude = solve(cubo, cur+1, prev, dp);
        
        int ans = max(include, exclude);
        return dp[cur][prev+1] = ans;
        
    }
    
    int maxHeight(vector<vector<int>>& cubo) {
        for(auto &i: cubo){
            sort(i.begin(),i.end());
        }
        sort(cubo.begin(), cubo.end());
        // for(auto i: cubo){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> dp(cubo.size(), vector<int> ( cubo.size() , -1));
        return solve(cubo, 0, -1, dp);
        
        
    }
};