class Solution {
public:
    vector<int> dist;
    int ans=1;
    
    void dfs(vector<int>vec[], string &s, int src){
        for(auto node: vec[src]){
            dfs(vec, s, node);
            if(s[node] == s[src])continue;
            ans = max(ans, dist[src] + dist[node]);
            dist[src] = max(dist[src] , dist[node]+1);
        }
    }
    
    int longestPath(vector<int>& p, string s) {
        int n = p.size();
        dist.resize(n,1);
        vector<int> vec[n];
        for(int i=1;i<n;i++){
            vec[p[i]].push_back(i);
        }
        
        dfs(vec, s, 0);
        return ans;
    }
};