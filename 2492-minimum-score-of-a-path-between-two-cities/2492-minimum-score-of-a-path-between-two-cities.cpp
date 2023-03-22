class Solution {
public:
    
    int ans = INT_MAX;
    
    void solve(vector<pair<int,int>> vec[], vector<bool>&vis, int idx){
        
        vis[idx] = true;
        
        for(auto i:vec[idx]){
            ans = min(ans, i.second);
            if(!vis[i.first]){
                solve(vec, vis, i.first);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> vec[n+1];
        for(auto i:roads){
            vec[i[0]].push_back({i[1], i[2]});
            vec[i[1]].push_back({i[0], i[2]});
        }
        
        vector<bool> vis(n+1, false);
        solve(vec, vis, 1);
        return ans;
        
    }
};