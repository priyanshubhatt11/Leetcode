class Solution {
public:
    int dp[1001][1001];
    int solve(vector<pair<int,int>>&vec, int i, int age){
        if(i>=vec.size())return 0;
        if(dp[i][age] != -1)return dp[i][age];
        if(vec[i].second >= age){
            return dp[i][age] = max(vec[i].first + solve(vec, i+1, vec[i].second), solve(vec, i+1, age));
        }
        return dp[i][age] = solve(vec, i+1, age);
        
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vec;
        for(int i=0;i<scores.size();i++){
            vec.push_back({scores[i], ages[i]});
        }
        memset(dp, -1, sizeof(dp));
        sort(vec.begin(), vec.end());
        return solve(vec, 0, 0);
    }
};