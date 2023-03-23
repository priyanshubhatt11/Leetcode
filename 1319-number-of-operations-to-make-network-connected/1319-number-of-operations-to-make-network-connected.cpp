class Solution {
public:
    
    void solve(vector<int> vec[], int idx, vector<bool>&vis){
        vis[idx] = true;
        for(auto i:vec[idx]){
            if(!vis[i]){
                solve(vec, i, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(n-1 > conn.size())return -1;
        vector<int> vec[n+1];
        for(auto i:conn){
            vec[i[0]].push_back(i[1]);
            vec[i[1]].push_back(i[0]);
        }
        
        int ans =0;
        vector<bool> vis(n+1, false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(vec, i, vis);
                ans++;
            }
        }
        
        return ans-1;
        
    }
};