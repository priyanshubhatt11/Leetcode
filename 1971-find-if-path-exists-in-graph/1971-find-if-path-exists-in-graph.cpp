class Solution {
public:
    bool flag = false;
    void solve(vector<int> vec[], int s, int d, vector<bool>&vis){
        if(vis[s])return;
        if(s == d)flag = true;
        vis[s] = true;
        for(auto i:vec[s]){
            solve(vec, i, d, vis);
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> vec[n];
        for(auto i:edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        solve(vec, source, destination, vis);
        return flag;
    }
};