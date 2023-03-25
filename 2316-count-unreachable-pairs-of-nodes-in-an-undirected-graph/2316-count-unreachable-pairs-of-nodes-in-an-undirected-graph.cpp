class Solution {
public:
    
    void solve(vector<int> vec[], vector<bool>&vis, int idx, int &c){
        vis[idx] = true;
        c++;
        for(auto i:vec[idx]){
            if(!vis[i]){
                solve(vec, vis, i,c);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vec[n+1];
        for(auto i:edges){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        vector<int> ans;
        vector<bool> vis(n+1, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int c =0;
                solve(vec, vis, i, c);
                ans.push_back(c);
            }
        }
        long long temp =0, tot=0;
        for(int i=0;i<ans.size();i++){
            temp += ans[i]*(n-tot-ans[i]);
            tot += ans[i];
        }
        return temp;
    }
};