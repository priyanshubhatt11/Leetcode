class Solution {
public:
    int ans = INT_MAX;
    
    int solve(vector<int> &ob, int idx, int cur, vector<vector<int>> &dp){
        if(idx >= ob.size()-1)return 0;
        //cout<<idx<<" "<<cur<<endl;
        
        if(dp[idx][cur] != -1){
            return dp[idx][cur];
        }
        
        if(ob[idx+1] != cur) return solve(ob, idx+1, cur, dp);
        else{
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(i != cur && ob[idx] != i) {
                    ans = min(ans, 1 + solve(ob, idx, i, dp));
                }
            }
            return dp[idx][cur] = ans;
        }       
        
        
    }
    
    int minSideJumps(vector<int>& ob) {
        vector<vector<int>> dp(ob.size()+1, vector<int>(4, -1));
        return solve(ob, 0, 2, dp);
    }
};