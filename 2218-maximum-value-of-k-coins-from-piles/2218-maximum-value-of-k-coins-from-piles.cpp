class Solution {
public:
    
    int Recursion(vector<vector<int>>& piles , int k , int i ,int j ,vector<vector<vector<int>>>& dp)
    {
        if(i>=piles.size() || k<=0 )
        {
            return 0;
        }
        if(dp[i][k][j]!=-1)
        {
            return dp[i][k][j];
        }
        int a = 0+ Recursion(piles,k , i+1 , 0,dp) ;
        int b=0;
        if(j<piles[i].size())
        {
            b = piles[i][j]+ Recursion(piles, k-1 ,i ,j+1,dp) ;
        }
       // cout<<a<< " "<<b<<endl;
        dp[i][k][j] = max(a,b) ;
        return dp[i][k][j] ;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int max_length =0;
        for(auto num:piles)
        {
            int p = num.size() ;
            max_length = max(max_length ,p);
        }
        vector<vector<vector<int>>> dp(piles.size() ,vector<vector<int>>(k+1,vector<int>(max_length +1,-1)));
       
        return Recursion(piles, k , 0 , 0 , dp);
    }
};