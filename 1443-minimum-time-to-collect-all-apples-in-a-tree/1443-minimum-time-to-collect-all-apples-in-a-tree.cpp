class Solution {
public:

    int dfs(vector<vector<int>>& adj , int curr , int prev , vector<bool>& hasApple){
        int dis = 0;
        
        for(auto& x : adj[curr]){
            if(x == prev) continue;
            int tmp = dfs(adj,x,curr,hasApple);
            if(tmp) dis += tmp;
        }
        
        if(curr && (hasApple[curr] || dis)) dis += 2;     
        return dis;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto& x : edges){
          adj[x[0]].push_back(x[1]);
          adj[x[1]].push_back(x[0]);
        }
        
        return dfs(adj,0,-1,hasApple);
    }
};