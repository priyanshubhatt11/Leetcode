class Solution {
public:
    int ans =1;
    vector<int> dist;
    
    void solve(vector<int> vec[], string &s, int idx){
        for(auto node:vec[idx]){
            solve(vec, s, node);
            if(s[idx] == s[node])continue;
            ans = max(ans, dist[idx] + dist[node]);
            dist[idx] = max(dist[idx], dist[node]+1);
        }
    }
    
    int longestPath(vector<int>& p, string s) {
        int n = p.size();
        vector<int> vec[n];
        for(int i=1;i<n;i++){
            vec[p[i]].push_back(i);
        }
        dist.resize(n, 1);
        solve(vec, s, 0);
        return ans;
    }
};