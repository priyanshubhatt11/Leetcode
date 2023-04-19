class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(vector<vector<int>>&vec, int k, int i, int j){
        if(k<=0 || i>=vec.size())return 0;
        if(dp[k][i][j] != -1)return dp[k][i][j];
        int a=0,b=0;
        a += solve(vec, k, i+1, 0);
        if(j<vec[i].size()){
            b += vec[i][j] + solve(vec, k-1, i, j+1);
        }
        return dp[k][i][j] = max(a,b);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int max_length =0;
        for(auto num:piles)
        {
            int p = num.size() ;
            max_length = max(max_length ,p);
        }
        
        dp.resize(k+1 ,vector<vector<int>>(piles.size(),vector<int>(max_length +1,-1)));
        return solve(piles, k, 0, 0);
    }
};